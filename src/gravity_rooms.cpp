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
      currentState(MAIN),
      currentPontos(0) {
  Ente::setGerenciador(&GG);

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
    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
  } else if (pMenu == IDs::IDs::menu_pausa &&
             menu->getID() != IDs::IDs::menu_pausa && currentState == PAUSE) {
    MenuPause *aux = new MenuPause(IDs::IDs::menu_pausa);
    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o menu pausa " << endl;
    }

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

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();

  } else if ((pMenu == IDs::IDs::menu_game_over) &&
             (menu->getID() != IDs::IDs::menu_game_over) &&
             (currentState == GAMEOVER)) {
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
    if ((currentState == GAMEOVER) && (eventao.type == Event::TextEntered)) {
      // Handle regular text input
      if (eventao.text.unicode >= 32 && eventao.text.unicode < 128) {
        Menus::MenuGameOver *menuGameOver =
            dynamic_cast<Menus::MenuGameOver *>(menu);
        if (menuGameOver) {
          menuGameOver->addCaracter(static_cast<char>(eventao.text.unicode));
        }
      }
    }

    if (eventao.type == Event::KeyPressed) {
      menu->eventoTeclado(eventao.key.code);
    }

    if (menu->getSelecionado()) {
      IDs::IDs selecao = menu->getIDBotaoSelecionado();
      if (selecao == IDs::IDs::menu_salvar_jogada) {
        salvarEntidades("save.json");
        currentState = MAIN;  // Keep menu open after saving
        return true;
      }
      if (selecao == IDs::IDs::botao_carregar) {
        if (save.carregar(GC, listaPersonagem, listaObstaculo, fase)) {
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
          menuGameOver->salvarColocacao(currentPontos);
        }
        currentState = MAIN;
        out = true;
      }
      if (selecao == IDs::IDs::estado_menu_principal) {
        // Clean up game state
        save.salvar(GC, listaPersonagem, listaObstaculo, *fase);
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
        if (ligarMenu(IDs::IDs::menu_pausa)) {
        }
        break;
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
        if (GC.pJog1) {
          currentPontos = GC.pJog1->getPontos();
        }
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
            save.salvar(GC, listaPersonagem, listaObstaculo, *fase);
          }
          if (evento.type == Event::KeyPressed &&
              evento.key.code == Keyboard::Escape) {
            save.salvar(GC, listaPersonagem, listaObstaculo, *fase);
            currentState = PAUSE;
          }
        }

        // Update game state
        GG.limpar();
        listaBackgrounds.desenharTodos();

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

    player2Active = true;
  }
}

void Gravity_Rooms::criarFases(IDs::IDs faseSelecionada) {
  if (faseSelecionada == IDs::IDs::fase_laboratorio) {
    Laboratorio *aux = new Laboratorio(IDs::IDs::fase_laboratorio);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o laboratorio " << endl;
    }

    fase = static_cast<Fase *>(aux);
  } else if (faseSelecionada == IDs::IDs::fase_nave) {
    Nave *pNave = new Nave(IDs::IDs::fase_nave);
    if (pNave == nullptr) {
      exit(1);
      cout << "nao foi possivel criar a nave " << endl;
    }

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
    }

    listaPersonagem.incluir(
        atualPersonagens->pInfo);  // Add entity to listaPersonagem
    atualPersonagens = atualPersonagens->getProximo();
  }
  listaBackgrounds.incluir(fase->bg);
}
void Gravity_Rooms::salvarEntidades(const std::string &nomeArquivo) {
  json j;

  j["fase"] = dynamic_cast<const Laboratorio *>(fase) ? "laboratorio" : "nave";
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
    arquivo << j.dump(4);  // Formatação bonita com 4 espaços
  }
}
void Gravity_Rooms::carregarEntidades(const std::string &nomeArquivo) {
  if (fase) {
    delete fase;
    fase = nullptr;
  }
  listaPersonagem.limparLista();
  listaObstaculo.limparLista();
  GC.pJog1 = nullptr;
  GC.pJog2 = nullptr;
  std::ifstream arquivo(nomeArquivo);

  if (arquivo.is_open()) {
    json dados;
    arquivo >> dados;
    if (dados.empty() || !dados.is_array()) {
      std::cerr << "Formato JSON inválido.\n";
    }
    std::string level = dados["fase"];
    IDs::IDs faseID = (level == "laboratorio") ? IDs::IDs::fase_laboratorio
                                               : IDs::IDs::fase_nave;
    fase = (faseID == IDs::IDs::fase_laboratorio)
               ? static_cast<Fase *>(new Laboratorio(faseID))
               : static_cast<Fase *>(new Nave(faseID));

    for (size_t i = 1; i < dados.size(); i++) {
      if (!dados[i].is_object())
        continue;  // Pula valores inválidos como `null`

      IDs::IDs id = static_cast<IDs::IDs>(dados["id"]);
      Vector2f pos(dados[i]["posicao"]["x"], dados[i]["posicao"]["y"]);

      switch (id) {
        case IDs::IDs::androide: {
          fase->criarInimMedios(pos, GC.pJog1);
          break;
        }
        case IDs::IDs::ciborgue:
          fase->criarInimFaceis(pos, GC.pJog1);
          break;
        case IDs::IDs::clone:
          fase->criarInimDificeis(pos, GC.pJog1);
          break;
        case IDs::IDs::plataforma:
          fase->criarPlataforma(pos);
          break;
        case IDs::IDs::espinho:
          fase->criarEspinho(pos);
          break;
        case IDs::IDs::centro_gravidade:
          fase->criarCentroGravidade(pos);
          break;
        case IDs::IDs::tripulante:
          fase->criarJogador(pos, 0);
          if (fase->tripulantes[0]) {
            GC.incluirTripulante(*(fase->tripulantes[0]));
            GC.pJog1->setVida(dados[i]["vida"]);
            Projetil *projetil =
                fase->criarProjetil(pos, IDs::IDs::projetil_tripulante);
            GC.pJog1->setProjetil(projetil);
            listaPersonagem.incluir(projetil);
          } else {
            GC.incluirTripulante(*(fase->tripulantes[1]));
            GC.pJog2->setVida(dados[i]["vida"]);
            Projetil *projetil =
                fase->criarProjetil(pos, IDs::IDs::projetil_tripulante);
            GC.pJog2->setProjetil(projetil);
            listaPersonagem.incluir(projetil);
          }
          break;
        default:
          std::cerr << "Tipo de inimigo desconhecido" << std::endl;
          break;
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
  }
}