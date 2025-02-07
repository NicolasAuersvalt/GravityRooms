#include "Gerenciadores/save.h"

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include "Entidades/background.h"
#include "Fases/laboratorio.h"
#include "Fases/nave.h"
#include "Gerenciadores/registry.h"

Save::Save() {}

Save::~Save() {}

void Save::setJogador(Entidades::Personagens::Tripulante *jogador) {}

void Save::gravarDados() {}

void Save::salvar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                  Lista_Entidades &listaObstaculo,
                  Lista_Entidades &listaBackgrounds, Fase *&fase,
                  const std::string &nomeArquivo) {
  json j;

  j["fase"] = dynamic_cast<Laboratorio *>(fase) ? "laboratorio" : "nave";
  j["entities"] = json::array();
  auto atual = listaPersonagem.LEs->getPrimeiro();
  while (atual != nullptr) {
    if (atual->pInfo) {
      json obj;
      atual->pInfo->salvar(obj);
      j["entities"].push_back(obj);
    }
    atual = atual->getProximo();
  }
  auto atual1 = listaBackgrounds.LEs->getPrimeiro();
  while (atual1 != nullptr) {
    if (atual1->pInfo) {
      json obj;
      atual1->pInfo->salvar(obj);
      j["entities"].push_back(obj);
    }
    atual1 = atual1->getProximo();
  }
  auto atual2 = listaObstaculo.LEs->getPrimeiro();
  while (atual2 != nullptr) {
    if (atual2->pInfo) {
      json obj;
      atual2->pInfo->salvar(obj);
      j["entities"].push_back(obj);
    }
    atual2 = atual2->getProximo();
  }

  std::ofstream arquivo(nomeArquivo);
  if (arquivo.is_open()) {
    arquivo << j.dump(4); // Formatação bonita com 4 espaços
  }
}

bool Save::carregar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
<<<<<<< HEAD
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
          atualObstaculos->pInfo); // Add entity to listaPersonagem
      atualObstaculos = atualObstaculos->getProximo();
    }
    auto atualPersonagens = fase->listaPersonagens->LEs->getPrimeiro();
    while (atualPersonagens != nullptr) {
      listaPersonagem.incluir(
          atualPersonagens->pInfo); // Add entity to listaPersonagem
      atualPersonagens = atualPersonagens->getProximo();
    }
    // Save players
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

    return true;
  } catch (const std::exception &e) {
    std::cerr << "Erro ao carregar jogo: " << e.what() << std::endl;
=======
                    Lista_Entidades &listaObstaculo,
                    Lista_Entidades &listaBackgrounds, Fase *&fase,
                    const std::string &nomeArquivo) {
  std::ifstream arquivo(nomeArquivo);
  if (!arquivo.is_open()) {
    std::cerr << "Erro ao abrir arquivo de salvamento!\n";
>>>>>>> psave
    return false;
  }

  json dados;
  arquivo >> dados;

  // Carrega a fase
  std::string tipoFase = dados["fase"];
  if (tipoFase == "laboratorio") {
    fase = new Laboratorio(IDs::IDs::fase_laboratorio);
  } else if (tipoFase == "nave") {
    fase = new Nave(IDs::IDs::fase_nave);
  }

  // Carrega todas as entidades
  for (auto &entidadeData : dados["entities"]) {
    if (entidadeData.is_null() || !entidadeData.contains("tipo")) {
      continue;
    }

    std::string tipo = entidadeData["tipo"];
    auto &registry = Registry::getInstance();
    auto ente = registry.criar(entidadeData);
    if (ente) {
      // Adiciona nas listas apropriadas
      if (dynamic_cast<Personagem *>(ente.get())) {
        if (auto jogador = dynamic_cast<Tripulante *>(ente.get())) {
          if (!GC.pJog1) {
            GC.pJog1 = jogador;
            GC.pJog1->setPlayerOne(false);
            if (entidadeData.contains("projetil")) {
              auto proj = registry.criar(entidadeData["projetil"]);
              if (proj) {
                listaPersonagem.incluir(
                    dynamic_cast<Entidade *>(jogador->getProjetil()));
              }
            }
          } else if (!GC.pJog2) {
            GC.pJog2 = jogador;
            GC.pJog2->setPlayerOne(true);
            if (entidadeData.contains("projetil")) {
              auto proj = registry.criar(entidadeData["projetil"]);
              if (proj) {
                listaPersonagem.incluir(
                    dynamic_cast<Entidade *>(jogador->getProjetil()));
              }
            }
          }
        } else {
          if (GC.pJog1) {
            auto inimigo = dynamic_cast<Inimigo *>(ente.get());
            inimigo->setTripulante(GC.pJog1);
            if (entidadeData.contains("projetil")) {
              auto proj = registry.criar(entidadeData["projetil"]);
              if (proj) {
                listaPersonagem.incluir(
                    dynamic_cast<Entidade *>(inimigo->getProjetil()));
              }
            }
          }
        }

        listaPersonagem.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (dynamic_cast<Obstaculo *>(ente.get())) {
        listaObstaculo.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (dynamic_cast<Background *>(ente.get())) {
        listaBackgrounds.incluir(dynamic_cast<Entidade *>(ente.release()));
      }
    }
  }
  auto atualPersonagens = listaPersonagem.LEs->getPrimeiro();
  while (atualPersonagens != nullptr) {
    if (dynamic_cast<Inimigo *>(atualPersonagens->pInfo))
      dynamic_cast<Inimigo *>(atualPersonagens->pInfo)->setTripulante(GC.pJog1);

    atualPersonagens = atualPersonagens->getProximo();
  }
  return true;
}