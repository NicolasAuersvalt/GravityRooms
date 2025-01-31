#include "gravity_rooms.h"

// Construtor
Gravity_Rooms::Gravity_Rooms()
    : GG(),
      listaPersonagem(),
      listaObstaculo(),
      GC(&listaPersonagem, &listaObstaculo),
      GE(),
      menu(nullptr),
      fase(nullptr) {
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
  if (pMenu == IDs::IDs::menu_principal && menu == nullptr) {
    MenuPrincipal *aux = new MenuPrincipal(IDs::IDs::menu_principal);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o menu principal " << endl;
    }
    cout << "  menu principal " << endl;

    menu = static_cast<Menu *>(aux);
    menu->criarBotoes();
  }
  Event eventao;
  bool out = false;
  if (GG.getJanela().pollEvent(eventao)) {
    if (eventao.type == Event::KeyPressed) {
      menu->eventoTeclado(eventao.key.code);
    }

    if (menu->getSelecionado()) {
      IDs::IDs selecao = menu->getIDBotaoSelecionado();

      if (selecao == IDs::IDs::botao_novoJogo) {
        criarFases(IDs::IDs::fase_laboratorio);
        out = true;
      }

      if (selecao == IDs::IDs::botao_sair) {
        exit(1);
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
  enum GameState { MAIN, PLAYING, PAUSE };
  GameState currentState = MAIN;
  bool isLaboratorioComplete = false;

  GG.executar();

  while (GG.estaAberta()) {
    Event evento;

    switch (currentState) {
      case MAIN: {
        if (ligarMenu(IDs::IDs::menu_principal)) {
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

      case PLAYING: {
        if (!GC.pJog1 || !GC.pJog1->verificarVivo()) {
          // Cleanup when player dies
          if (fase != nullptr) {
            delete fase;
            fase = nullptr;
          }

          listaPersonagem.limparLista();

          listaObstaculo.limparLista();
          GC.pJog1 = nullptr;
          menu->setSelecionado(false);
          currentState = MAIN;
          continue;
        }

        // // Check if all enemies are dead
        // bool enemiesExist = false;
        // auto atual = listaPersonagem.LEs->getPrimeiro();
        // while (atual != nullptr) {
        //   if (dynamic_cast<Inimigo *>(atual->pInfo)) {
        //     enemiesExist = true;
        //     break;
        //   }
        //   atual = atual->getProximo();
        // }

        // // If no enemies and in laboratory, transition to nave
        // if (!enemiesExist && !isLaboratorioComplete &&
        //     dynamic_cast<Laboratorio *>(fase)) {
        //   delete fase;
        //   fase = nullptr;
        //   listaPersonagem.limparLista();
        //   listaObstaculo.limparLista();
        //   criarFases(IDs::IDs::fase_nave);
        //   isLaboratorioComplete = true;
        //   continue;
        // }

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
              evento.key.code == Keyboard::P) {
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
        cout << "entrei na obstaulo" << endl;
        listaObstaculo.atualizarTodas();

        break;
      }
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
