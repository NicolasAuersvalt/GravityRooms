#include "gravity_rooms.h"

// Construtor
Gravity_Rooms::Gravity_Rooms()
    : GG(),
      listaPersonagem(),
      listaObstaculo(),
      GC(&listaPersonagem, &listaObstaculo),
      GE(),
      menu(nullptr),
      fase(nullptr),
      player2Active(false),
      currentState(MAIN) {
  /*
  if (!backgroundTexture.loadFromFile("assets/tripulante.png")) {
          cerr << "Erro ao carregar o background!" << endl;
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setPosition(25, 25);
  */

  Ente::setGerenciador(&GG);
  // fase->setGerenciador(&GG);

  // Vector2f pos = pJog1.getPosicao();

  // pJog1.setSprite("assets/tripulanteG.png", pos.x, pos.y);

  // cout << "bli\n";
  // listaPersonagem.incluir(static_cast<Entidade *>(&pJog1));

  // pAnd1.setSprite("assets/androidG.png", 0, 0);
  // pAnd1.setVida(10);

  // listaPersonagem.incluir(static_cast<Entidade *>(&pAnd1));

  executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms() {}

bool Gravity_Rooms::ligarMenu(IDs::IDs pMenu) {
  if (pMenu == IDs::IDs::menu_principal &&
      (menu == nullptr || menu->getID() != IDs::IDs::menu_principal)) {
    MenuPrincipal *aux = new MenuPrincipal(IDs::IDs::menu_principal);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o menu principal " << endl;
    }
    cout << "  menu principal " << endl;

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
  } else if (pMenu == IDs::IDs::menu_pausa &&
             menu->getID() != IDs::IDs::menu_pausa && currentState == PAUSE) {
    MenuPause *aux = new MenuPause(IDs::IDs::menu_pausa);

    cout << "here" << endl;
    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o menu pausa " << endl;
    }
    cout << "  menu pausa " << endl;

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
  } else if (pMenu == IDs::IDs::menu_colocacao &&
             menu->getID() != IDs::IDs::menu_colocacao &&
             currentState == COLOCACAO) {
    Menus::Ranking *aux = new Menus::Ranking(IDs::IDs::menu_colocacao);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o  menu_colocacao " << endl;
    }
    cout << "   menu_colocacao " << endl;

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();

  } else if ((pMenu == IDs::IDs::menu_game_over) &&
             (menu->getID() != IDs::IDs::menu_game_over) &&
             (currentState == GAMEOVER)) {
    cout << "her2e" << endl;
    Menus::MenuGameOver *aux =
        new Menus::MenuGameOver(IDs::IDs::menu_game_over);
    if (aux == nullptr) {
      cout << "nao foi possivel criar o  menu_game_over " << endl;
      exit(1);
    }
    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
    // menu->inicializarIterator();
    menu->inicializarIterator();  // Add this line
  }
  Event eventao;
  bool out = false;
  if (GG.getJanela().pollEvent(eventao)) {
    /*/*/
    if ((currentState == GAMEOVER) && (eventao.type == Event::TextEntered)) {
      // Handle regular text input
      if (eventao.text.unicode >= 32 && eventao.text.unicode < 128) {
        // Menus::MenuGameOver *menuGameOver = dynamic_cast<MenuGameOver
        // *>(menu); if (menuGameOver) {
        Menus::MenuGameOver *menuGameOver =
            dynamic_cast<Menus::MenuGameOver *>(menu);
        if (menuGameOver) {
          menuGameOver->addCaracter(static_cast<char>(eventao.text.unicode));
          std::cout << "Input character: "
                    << static_cast<char>(eventao.text.unicode) << std::endl;
        }
      }
    }
    /**/
    if (eventao.type == Event::KeyPressed) {
      menu->eventoTeclado(eventao.key.code);
    }

    if (menu->getSelecionado()) {
      IDs::IDs selecao = menu->getIDBotaoSelecionado();
      if (selecao == IDs::IDs::menu_salvar_jogada) {
        salvarJogo();
        cout << "Jogo salvo com sucesso!" << endl;
        currentState = MAIN;  // Keep menu open after saving
        return true;
      }
      if (selecao == IDs::IDs::botao_carregar) {
        if (carregarJogo()) {
          currentState = PLAYING;
          return true;
        }
      }
      if (selecao == IDs::IDs::botao_novoJogo) {
        criarFases(IDs::IDs::fase_laboratorio);
        fase->complete = false;
        out = true;
      }
      if (selecao == IDs::IDs::botao2) {
        criarFases(IDs::IDs::fase_nave);
        fase->complete = false;
        out = true;
      }

      if (selecao == IDs::IDs::botao_voltar) {
        currentState = PLAYING;
        out = true;
      }
      if (selecao == IDs::IDs::botao_sair) {
        exit(1);
      }
      if (selecao == IDs::IDs::botao_colocacao) {
        currentState = COLOCACAO;
        out = true;
      }
      if (selecao == IDs::IDs::botao_nome) {
        Menus::MenuGameOver *menuGameOver =
            dynamic_cast<Menus::MenuGameOver *>(menu);
        if (menuGameOver) {
          menuGameOver->salvarColocacao();
        }
        currentState = MAIN;
        out = true;
      }
      if (selecao == IDs::IDs::estado_menu_principal) {
        // Clean up game state
        salvarJogo();
        if (fase) {
          delete fase;
          fase = nullptr;
        }
        listaPersonagem.limparLista();
        listaObstaculo.limparLista();
        GC.pJog1 = nullptr;
        GC.pJog2 = nullptr;
        player2Active = false;

        currentState = MAIN;
        out = true;
      }
    }
  }

  GG.limpar();
  // menuGeral.desenhar(&GG);
  menu->desenhar(&GG);
  GG.exibir();
  return out;
}
void Gravity_Rooms::executar() {
  GG.executar();

  while (GG.estaAberta()) {
    if (GC.pJog1) {
      GC.pJog1->atualizar();
    }
    if (GC.pJog2 && player2Active) {
      GC.pJog2->atualizar();
    }
    Event evento;

    switch (currentState) {
      case MAIN: {
        if (ligarMenu(IDs::IDs::menu_principal)) {
          if (currentState == COLOCACAO) break;
          currentState = PLAYING;
        }
        break;
      }
      case PAUSE: {
        menu->setSelecionado(false);
        if (ligarMenu(IDs::IDs::menu_pausa)) break;
      }
      case COLOCACAO: {
        menu->setSelecionado(false);
        if (ligarMenu(IDs::IDs::menu_colocacao)) {
          currentState = MAIN;
        }
        break;
      }
      case GAMEOVER: {
        menu->setSelecionado(false);
        if (ligarMenu(IDs::IDs::menu_game_over)) {
          currentState = MAIN;
        }
        break;
      }

      case PLAYING: {
        // Check for "2" key press to activate Player 2
        string tecla = pGE->isTeclaPressionada(sf::Keyboard::M);
        if (tecla == "M" && !player2Active) {
          criarJogadorDois();
        }
        if ((!GC.pJog1 || !GC.pJog1->verificarVivo()) &&
            (!GC.pJog2 || !GC.pJog2->verificarVivo())) {
          // Cleanup when player dies
          if (fase != nullptr) {
            delete fase;
            fase = nullptr;
          }
          cout << "asdasdas" << GC.pJog1 << endl;
          // Removed fase->complete = false;
          listaPersonagem.limparLista();
          listaObstaculo.limparLista();
          player2Active = false;
          GC.pJog1 = nullptr;
          GC.pJog2 = nullptr;
          currentState = GAMEOVER;

          break;
        }

        // Check if all enemies are dead
        bool enemiesExist = false;

        auto atual = listaPersonagem.LEs->getPrimeiro();
        while (atual != nullptr) {
          if (dynamic_cast<Inimigo *>(atual->pInfo)) {
            enemiesExist = true;
            break;
          }
          atual = atual->getProximo();
        }

        // Transition logic
        if (!enemiesExist && fase->complete == false) {
          if (dynamic_cast<Laboratorio *>(fase)) {
            cout << "Transitioning to Nave..." << endl;
            delete fase;
            fase = nullptr;
            listaPersonagem.limparLista();
            listaObstaculo.limparLista();
            GC.pJog1 = nullptr;
            GC.pJog2 = nullptr;
            criarFases(IDs::IDs::fase_nave);
            if (player2Active) {
              criarJogadorDois();
            }
            continue;
          } else if (dynamic_cast<Nave *>(fase)) {
            cout << "Nave completed. Returning to main menu..." << endl;
            delete fase;
            fase = nullptr;
            listaPersonagem.limparLista();
            listaObstaculo.limparLista();
            GC.pJog1 = nullptr;
            GC.pJog2 = nullptr;
            player2Active = false;
            menu->setSelecionado(false);
            currentState = GAMEOVER;
            continue;
          }
        }
        // Handle game events
        while (GG.processarEvento(evento)) {
          if (evento.type == Event::Closed) {
            GG.fechar();
          }
          if (evento.type == Event::KeyPressed &&
              evento.key.code == Keyboard::Y) {
            salvarJogo();
          }
          if (evento.type == Event::KeyPressed &&
              evento.key.code == Keyboard::Escape) {
            salvarJogo();
            currentState = PAUSE;
          }
        }

        // Update game state
        GG.limpar();

        listaObstaculo.desenharTodos();

        listaPersonagem.desenharTodos();

        GC.setLista_Entidades(&listaPersonagem, &listaObstaculo);

        GC.executar(&listaPersonagem, &listaObstaculo);

        GG.exibir();

        listaPersonagem.atualizarTodas();
        listaObstaculo.atualizarTodas();

        break;
      }
    }
  }
}

void Gravity_Rooms::criarJogadorDois() {
  player2Active = true;
  if (fase && !GC.pJog2) {  // Only create if doesn't exist
    fase->criarJogador(Vector2f(200.0f, 100.0f), 1);
    Projetil *projetil = fase->criarProjetil(Vector2f(200.0f, 100.0f),
                                             IDs::IDs::projetil_tripulante);
    fase->tripulantes[1]->setProjetil(projetil);
    listaPersonagem.incluir(projetil);
    Tripulante *tripPtr = dynamic_cast<Tripulante *>(fase->tripulantes[1]);
    if (tripPtr) {
      GC.incluirTripulante(*tripPtr);
      listaPersonagem.incluir(tripPtr);
    }
  }
}

void Gravity_Rooms::salvarJogo() {
  nlohmann::ordered_json saveData;

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

  // Save level state
  saveData["level"] =
      dynamic_cast<Laboratorio *>(fase) ? "laboratorio" : "nave";

  // Save enemies
  nlohmann::json enemiesData;
  auto atual = listaPersonagem.LEs->getPrimeiro();
  while (atual != nullptr) {
    if (auto inimigo = dynamic_cast<Inimigo *>(atual->pInfo)) {
      nlohmann::json enemyData = {{"id", inimigo->getID()},
                                  {"x", inimigo->getPosicao().x},
                                  {"y", inimigo->getPosicao().y},
                                  {"vida", inimigo->getVida()}};
      enemiesData.push_back(enemyData);
    }
    atual = atual->getProximo();
  }
  saveData["enemies"] = enemiesData;

  // Save obstacles
  nlohmann::json obstaculosData;
  auto atualObstaculo = listaObstaculo.LEs->getPrimeiro();
  while (atualObstaculo != nullptr) {
    if (auto obstaculo = dynamic_cast<Obstaculo *>(atualObstaculo->pInfo)) {
      nlohmann::json obsData = {{"id", obstaculo->getID()},
                                {"x", obstaculo->getPosicao().x},
                                {"y", obstaculo->getPosicao().y}};
      obstaculosData.push_back(obsData);
    }
    atualObstaculo = atualObstaculo->getProximo();
  }
  saveData["obstaculos"] = obstaculosData;

  // Write to file
  std::ofstream arquivo("saves/save_game.json");
  if (arquivo.is_open()) {
    arquivo << saveData.dump(4);
    arquivo.close();
  }
}

void Gravity_Rooms::criarFases(IDs::IDs faseSelecionada) {
  if (faseSelecionada == IDs::IDs::fase_laboratorio) {
    Laboratorio *aux = new Laboratorio(IDs::IDs::fase_laboratorio);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o laboratorio " << endl;
    }
    cout << " laboratorio " << endl;

    fase = static_cast<Fase *>(aux);
  } else if (faseSelecionada == IDs::IDs::fase_nave) {
    Nave *pNave = new Nave(IDs::IDs::fase_nave);
    if (pNave == nullptr) {
      exit(1);
      cout << "nao foi possivel criar a nave " << endl;
    }

    cout << " nave " << endl;
    fase = static_cast<Fase *>(pNave);
  }

  fase->criarMapa();

  auto atualObstaculos = fase->listaObstaculos->LEs->getPrimeiro();
  while (atualObstaculos != nullptr) {
    listaObstaculo.incluir(
        atualObstaculos->pInfo);  // Add entity to listaPersonagem
    atualObstaculos = atualObstaculos->getProximo();
  }
  auto atualPersonagens = fase->listaPersonagens->LEs->getPrimeiro();
  while (atualPersonagens != nullptr) {
    if (dynamic_cast<Entidades::Personagens::Tripulante *>(
            atualPersonagens->pInfo)) {
      Tripulante *tripPtr = dynamic_cast<Tripulante *>(atualPersonagens->pInfo);
      GC.incluirTripulante(*tripPtr);
    } else {
      // GC.incluirInimigo(static_cast<Inimigo *>(atualPersonagens->pInfo));
    }

    listaPersonagem.incluir(
        atualPersonagens->pInfo);  // Add entity to listaPersonagem
    atualPersonagens = atualPersonagens->getProximo();
  }
}
void Gravity_Rooms::criarFasesVazia(IDs::IDs faseSelecionada) {
  if (faseSelecionada == IDs::IDs::fase_laboratorio) {
    fase = new Laboratorio(IDs::IDs::fase_laboratorio);
  } else if (faseSelecionada == IDs::IDs::fase_nave) {
    fase = new Nave(IDs::IDs::fase_nave);
  }
}
bool Gravity_Rooms::carregarJogo() {
  try {
    std::ifstream arquivo("saves/save_game.json");
    if (!arquivo.is_open()) {
      std::cerr << "Nenhum jogo salvo encontrado!" << std::endl;
      return false;
    }
    cout << "bla" << endl;
    nlohmann::json saveData;
    arquivo >> saveData;
    arquivo.close();
    cout << "bl2" << endl;

    // Clear existing game state
    if (fase) {
      delete fase;
      fase = nullptr;
    }
    listaPersonagem.limparLista();
    listaObstaculo.limparLista();
    GC.pJog1 = nullptr;
    GC.pJog2 = nullptr;

    cout << "bl3" << endl;
    // Load level
    std::string level = saveData["level"];
    IDs::IDs faseID = (level == "laboratorio") ? IDs::IDs::fase_laboratorio
                                               : IDs::IDs::fase_nave;

    criarFasesVazia(faseID);
    cout << "bl4" << endl;
    // Load player 1
    if (saveData.contains("jogador1")) {
      auto &jog1 = saveData["jogador1"];
      Vector2f pos(jog1["x"], jog1["y"]);
      fase->criarJogador(pos, 0);
      GC.incluirTripulante(*(fase->tripulantes[0]));

      Projetil *projetil = fase->criarProjetil(Vector2f(200.0f, 100.0f),
                                               IDs::IDs::projetil_tripulante);
      fase->tripulantes[0]->setProjetil(projetil);
      listaPersonagem.incluir(projetil);
      if (GC.pJog1) {
        GC.pJog1->setVida(jog1["vida"]);
      }
    }

    cout << "bl5" << endl;
    // Load enemies
    if (saveData.contains("enemies")) {
      for (const auto &enemyData : saveData["enemies"]) {
        Vector2f pos(enemyData["x"], enemyData["y"]);
        IDs::IDs enemyType = static_cast<IDs::IDs>(enemyData["id"]);

        switch (enemyType) {
          case IDs::IDs::androide:
            fase->criarInimFaceis(pos, GC.pJog1);
            break;
          case IDs::IDs::ciborgue:
            fase->criarInimMedios(pos, GC.pJog1);
            break;
          case IDs::IDs::clone:
            fase->criarInimMedios(pos, GC.pJog1);
            break;
          default:
            std::cout << "Enemy type not recognized" << std::endl;
            break;
        }
      }
    }
    // Load obstacles
    if (saveData.contains("obstaculos") && !saveData["obstaculos"].is_null()) {
      for (const auto &obsData : saveData["obstaculos"]) {
        if (obsData.contains("x") && obsData.contains("y") &&
            obsData.contains("id")) {
          Vector2f pos(obsData["x"], obsData["y"]);
          IDs::IDs obsType = static_cast<IDs::IDs>(obsData["id"].get<int>());

          switch (obsType) {
            case IDs::IDs::plataforma: {
              fase->criarPlataforma(pos);
              break;
            }
            case IDs::IDs::espinho: {
              fase->criarEspinho(pos);
              break;
            }
          }
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
      if (dynamic_cast<Entidades::Personagens::Tripulante *>(
              atualPersonagens->pInfo)) {
        Tripulante *tripPtr =
            dynamic_cast<Tripulante *>(atualPersonagens->pInfo);
        GC.incluirTripulante(*tripPtr);
      } else {
        // GC.incluirInimigo(static_cast<Inimigo *>(atualPersonagens->pInfo));
      }

      listaPersonagem.incluir(
          atualPersonagens->pInfo);  // Add entity to listaPersonagem
      atualPersonagens = atualPersonagens->getProximo();
    }
    cout << "bl6" << endl;
    std::cout << "Jogo carregado com sucesso!" << std::endl;
    return true;

  } catch (const std::exception &e) {
    std::cerr << "Erro ao carregar jogo: " << e.what() << std::endl;
    return false;
  }
}