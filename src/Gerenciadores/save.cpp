#include "Gerenciadores/save.h"

Save::Save() {}

Save::~Save() {}

void Save::setJogador(Entidades::Personagens::Tripulante *jogador) {}

void Save::gravarDados() {}

void Save::salvar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                  Lista_Entidades &listaObstaculo, Fase &fase) {
  nlohmann::ordered_json saveData;

  // Save level state
  saveData["level"] =
      dynamic_cast<const Laboratorio *>(&fase) ? "laboratorio" : "nave";

  // Save player data
  if (GC.pJog1) {
    saveData["jogador1"] = {{"x", GC.pJog1->getPosicao().x},
                            {"y", GC.pJog1->getPosicao().y},
                            {"vida", GC.pJog1->getVida()}};
  }

  if (GC.pJog2) {
    saveData["jogador2"] = {{"x", GC.pJog2->getPosicao().x},
                            {"y", GC.pJog2->getPosicao().y},
                            {"vida", GC.pJog2->getVida()}};
  }

  // Save enemies
  nlohmann::json enemiesData;
  auto atual = listaPersonagem.LEs->getPrimeiro();
  while (atual != nullptr) {
    if (auto inimigo = dynamic_cast<Inimigo *>(atual->pInfo)) {
      enemiesData.push_back({{"id", inimigo->getID()},
                             {"x", inimigo->getPosicao().x},
                             {"y", inimigo->getPosicao().y},
                             {"vida", inimigo->getVida()}});
    }
    atual = atual->getProximo();
  }
  saveData["enemies"] = enemiesData;

  // Save obstacles
  nlohmann::json obstaculosData;
  auto atualObstaculo = listaObstaculo.LEs->getPrimeiro();
  while (atualObstaculo != nullptr) {
    if (auto obstaculo = dynamic_cast<Obstaculo *>(atualObstaculo->pInfo)) {
      obstaculosData.push_back({{"id", obstaculo->getID()},
                                {"x", obstaculo->getPosicao().x},
                                {"y", obstaculo->getPosicao().y}});
    }
    atualObstaculo = atualObstaculo->getProximo();
  }
  saveData["obstaculos"] = obstaculosData;

  // Write to file
  std::ofstream arquivo("saves/save_game.json");
  if (arquivo.is_open()) {
    arquivo << saveData.dump(4);
    arquivo.close();
    std::cout << "Jogo salvo com sucesso!" << std::endl;
  } else {
    std::cerr << "Erro ao salvar o jogo!" << std::endl;
  }
}
bool Save::carregar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                    Lista_Entidades &listaObstaculo, Fase *&fase) {
  try {
    std::ifstream arquivo("saves/save_game.json");
    if (!arquivo.is_open()) {
      std::cerr << "Nenhum jogo salvo encontrado!" << std::endl;
      return false;
    }
    std::cerr << "Jogo salvo encontrado!" << std::endl;
    nlohmann::json saveData;
    arquivo >> saveData;
    arquivo.close();

    // Clear existing game state
    if (fase) {
      delete fase;
      fase = nullptr;
    }
    listaPersonagem.limparLista();
    listaObstaculo.limparLista();
    GC.pJog1 = nullptr;
    GC.pJog2 = nullptr;

    // Load level
    std::string level = saveData["level"];

    std::cerr << "Nivel: " << level << std::endl;
    IDs::IDs faseID = (level == "laboratorio") ? IDs::IDs::fase_laboratorio
                                               : IDs::IDs::fase_nave;
    fase = (faseID == IDs::IDs::fase_laboratorio)
               ? static_cast<Fase *>(new Laboratorio(faseID))
               : static_cast<Fase *>(new Nave(faseID));

    // Load players
    if (saveData.contains("jogador1")) {
      auto &jog1 = saveData["jogador1"];
      Vector2f pos(jog1["x"], jog1["y"]);
      fase->criarJogador(pos, 0);
      if (fase->tripulantes[0]) {
        GC.incluirTripulante(*(fase->tripulantes[0]));
        GC.pJog1->setVida(jog1["vida"]);
        /**/
        Projetil *projetil =
            fase->criarProjetil(pos, IDs::IDs::projetil_tripulante);
        GC.pJog1->setProjetil(projetil);
        listaPersonagem.incluir(projetil);
      }
    }

    if (saveData.contains("enemies")) {
      for (const auto &enemyData : saveData["enemies"]) {
        Vector2f pos(enemyData["x"], enemyData["y"]);
        IDs::IDs enemyType = static_cast<IDs::IDs>(enemyData["id"]);

        switch (enemyType) {
          case IDs::IDs::androide:
            fase->criarInimMedios(pos, GC.pJog1);
            break;
          case IDs::IDs::ciborgue:
            fase->criarInimFaceis(pos, GC.pJog1);
            break;
          case IDs::IDs::clone:
            fase->criarInimDificeis(pos, GC.pJog1);
            break;
          default:
            std::cerr << "Tipo de inimigo desconhecido" << std::endl;
            break;
        }
      }
    }

    if (saveData.contains("obstaculos")) {
      for (const auto &obsData : saveData["obstaculos"]) {
        Vector2f pos(obsData["x"], obsData["y"]);
        IDs::IDs obsType = static_cast<IDs::IDs>(obsData["id"].get<int>());

        switch (obsType) {
          case IDs::IDs::plataforma:
            fase->criarPlataforma(pos);
            break;
          case IDs::IDs::espinho:
            fase->criarEspinho(pos);
            break;
          case IDs::IDs::centro_gravidade:
            fase->criarCentroGravidade(pos);
            break;
          default:
            std::cerr << "Tipo de obstáculo desconhecido" << std::endl;
            break;
        }
      }
    }
    auto atualObstaculos = fase->listaObstaculos->LEs->getPrimeiro();
    while (atualObstaculos != nullptr) {
      listaObstaculo.incluir(
          atualObstaculos->pInfo);  // Add entity to listaPersonagem
      atualObstaculos = atualObstaculos->getProximo();
    }
    auto atualPersonagens = fase->listaPersonagens->LEs->getPrimeiro();
    while (atualPersonagens != nullptr) {
      listaPersonagem.incluir(
          atualPersonagens->pInfo);  // Add entity to listaPersonagem
      atualPersonagens = atualPersonagens->getProximo();
    }
    // Save players
    if (GC.pJog1) {
      saveData["jogador1"] = {{"x", GC.pJog1->getPosicao().x},
                              {"y", GC.pJog1->getPosicao().y},
                              {"vida", GC.pJog1->getVida()}};
    }
    if (GC.pJog2) {
      std::cout << "asdasddo!" << std::endl;
      saveData["jogador2"] = {{"x", GC.pJog2->getPosicao().x},
                              {"y", GC.pJog2->getPosicao().y},
                              {"vida", GC.pJog2->getVida()}};
    }

    return true;
  } catch (const std::exception &e) {
    std::cerr << "Erro ao carregar jogo: " << e.what() << std::endl;
    return false;
  }
}
