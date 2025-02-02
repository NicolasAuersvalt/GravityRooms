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
             menu->getID() == IDs::IDs::menu_principal) {
    MenuPause *aux = new MenuPause(IDs::IDs::menu_pausa);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o menu pausa " << endl;
    }
    cout << "  menu pausa " << endl;

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
  } else if (pMenu == IDs::IDs::menu_colocacao &&
             menu->getID() == IDs::IDs::menu_principal) {
    Menus::Ranking *aux = new Menus::Ranking(IDs::IDs::menu_colocacao);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o  menu_colocacao " << endl;
    }
    cout << "   menu_colocacao " << endl;

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
  } else if (pMenu == IDs::IDs::menu_game_over &&
             menu->getID() == IDs::IDs::menu_principal) {
    Menus::MenuGameOver *aux =
        new Menus::MenuGameOver(IDs::IDs::menu_game_over);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o  menu_game_over " << endl;
    }

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
    // menu->inicializarIterator();
    cout << "menu_game_over criado" << endl;
  }
  Event eventao;
  bool out = false;
  if (GG.getJanela().pollEvent(eventao)) {
    /*/*/
    if ((currentState = GAMEOVER) && (eventao.type == Event::TextEntered)) {
      // Handle regular text input
      if (eventao.text.unicode >= 32 && eventao.text.unicode < 128) {
        // addCaracter(static_cast<char>(eventao.text.unicode));
        cout << "here" << endl;  // Print current input
      }
    }
    /**/
    if (eventao.type == Event::KeyPressed) {
      menu->eventoTeclado(eventao.key.code);
    }

    if (menu->getSelecionado()) {
      IDs::IDs selecao = menu->getIDBotaoSelecionado();

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
        out = true;
      }
      if (selecao == IDs::IDs::botao_sair) {
        exit(1);
      }
      if (selecao == IDs::IDs::botao_colocacao) {
        currentState = COLOCACAO;
        out = true;
      }
      if (selecao == IDs::IDs::estado_menu_principal) {
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
          currentState = PLAYING;
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
          menu->setSelecionado(false);
          currentState = GAMEOVER;
          continue;
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
            currentState = MAIN;
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
  nlohmann::ordered_json buffer;
  // Exemplo: Salvar o buffer em um arquivo
  ofstream arquivo("dados_salvos.json");
  if (arquivo.is_open()) {
    arquivo << buffer.dump(4);  // Salva com indentação de 4 espaços
    arquivo.close();
    cout << "Dados salvos em 'dados_salvos.json'.\n";
  } else {
    cerr << "Erro ao abrir o arquivo para salvar os dados.\n";
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

// ===/===/===/===/ Outros  ===/===/===/===/