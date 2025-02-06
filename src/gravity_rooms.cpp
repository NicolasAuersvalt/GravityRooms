#include "gravity_rooms.h"

// Construtor
Gravity_Rooms::Gravity_Rooms()
    : GG(), listaPersonagem(), listaObstaculo(),
      GC(&listaPersonagem, &listaObstaculo), GE(), menu(nullptr), fase(nullptr),
      player2Active(false), currentState(MAIN), currentPontos(0) {
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
    menu->inicializarIterator();
  }
  Event eventao;
  bool out = false;
  if (GG.getJanela().pollEvent(eventao)) {
    if ((currentState == GAMEOVER) && (eventao.type == Event::TextEntered)) {
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
        currentState = MAIN;
        return true;
      }
      if (selecao == IDs::IDs::botao_carregar) {
        if (carregarEntidades("save.json")) {
          out = true;
        }
      }
      if (selecao == IDs::IDs::botao_novoJogo) {
        criarFases(IDs::IDs::fase_laboratorio);

        fase->complete = false;
        currentState = PLAYING;
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
        salvarEntidades("save.json");
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
        if (currentState == COLOCACAO)
          break;
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
      string tecla = pGE->isTeclaPressionada(sf::Keyboard::M);
      if (GC.pJog1) {
        currentPontos = GC.pJog1->getPontos();
      }
      if (tecla == "M" && !player2Active) {
        criarJogadorDois();
      }
      if ((!GC.pJog1 || !GC.pJog1->verificarVivo()) &&
          (!GC.pJog2 || !GC.pJog2->verificarVivo())) {
        if (fase != nullptr) {
          delete fase;
          fase = nullptr;
        }
        listaPersonagem.limparLista();
        listaObstaculo.limparLista();
        player2Active = false;
        GC.pJog1 = nullptr;
        GC.pJog2 = nullptr;
        currentState = GAMEOVER;

        break;
      }

      bool enemiesExist = false;

      auto atual = listaPersonagem.LEs->getPrimeiro();
      while (atual != nullptr) {
        if (dynamic_cast<Inimigo *>(atual->pInfo)) {
          enemiesExist = true;
          break;
        }
        atual = atual->getProximo();
      }

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
      while (GG.processarEvento(evento)) {
        if (evento.type == Event::Closed) {
          GG.fechar();
        }
        if (evento.type == Event::KeyPressed &&
            evento.key.code == Keyboard::Y) {
          salvarEntidades("save.json");
        }
        if (evento.type == Event::KeyPressed &&
            evento.key.code == Keyboard::Escape) {
          salvarEntidades("save.json");
          currentState = PAUSE;
        }
      }

      GG.limpar();
      listaBackgrounds.desenharTodos();

      listaObstaculo.desenharTodos();

      listaPersonagem.desenharTodos();

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
  if (fase && !GC.pJog2) {
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
  if (fase) {
    delete fase;
    fase = nullptr;
  }
  listaPersonagem.limparLista();
  listaObstaculo.limparLista();
  listaBackgrounds.limparLista();
  GC.pJog1 = nullptr;
  GC.pJog2 = nullptr;
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
    listaObstaculo.incluir(atualObstaculos->pInfo);
    atualObstaculos = atualObstaculos->getProximo();
  }
  auto atualPersonagens = fase->listaPersonagens->LEs->getPrimeiro();
  while (atualPersonagens != nullptr) {
    if (dynamic_cast<Entidades::Personagens::Tripulante *>(
            atualPersonagens->pInfo)) {
      Tripulante *tripPtr = dynamic_cast<Tripulante *>(atualPersonagens->pInfo);
      GC.incluirTripulante(*tripPtr);
    }

    listaPersonagem.incluir(atualPersonagens->pInfo);
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
    arquivo << j.dump(4); // Formatação bonita com 4 espaços
  }
}

bool Gravity_Rooms::carregarEntidades(const std::string &nomeArquivo) {
  // Limpa o estado atual - pode se tornar um metodo
  if (fase) {
    delete fase;
    fase = nullptr;
  }
  listaPersonagem.limparLista();
  listaObstaculo.limparLista();
  listaBackgrounds.limparLista();
  GC.pJog1 = nullptr;
  GC.pJog2 = nullptr;
  // end Limpa o estado atual - pode se tornar um metodo

  std::ifstream arquivo(nomeArquivo);
  if (!arquivo.is_open()) {
    std::cerr << "Erro ao abrir arquivo de salvamento!\n";
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
          } else if (!GC.pJog2) {
            GC.pJog2 = jogador;
            GC.pJog2->setPlayerOne(true);
          }
        } else {
          if (GC.pJog1) {
            auto inimigo = dynamic_cast<Inimigo *>(ente.get());
            inimigo->setTripulante(GC.pJog1);
          }
        }
        listaPersonagem.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (dynamic_cast<Obstaculo *>(ente.get())) {
        listaObstaculo.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (dynamic_cast<Background *>(ente.get())) {
        listaBackgrounds.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (auto proj = dynamic_cast<Projetil *>(ente.get())) {
        if (proj->getID() == IDs::IDs::projetil_tripulante) {
          if (GC.pJog1 && !GC.pJog1->getProjetil()) {
            GC.pJog1->setProjetil(proj);
          }
        } else if (proj->getID() == IDs::IDs::projetil_inimigo) {
          auto atualPer = listaPersonagem.LEs->getPrimeiro();
          while (atualPer != nullptr) {
            if (auto clone = dynamic_cast<Clone *>(atualPer->pInfo)) {
              if (!clone->getProjetil()) {
                clone->setProjetil(proj);
                break;
              }
            }
            atualPer = atualPer->getProximo();
          }
        }
        listaPersonagem.incluir(dynamic_cast<Entidade *>(ente.release()));
      }
    }
  }
  auto atualPersonagens = listaPersonagem.LEs->getPrimeiro();
  while (atualPersonagens != nullptr) {
    if (dynamic_cast<Inimigo *>(atualPersonagens->pInfo))
      dynamic_cast<Inimigo *>(atualPersonagens->pInfo)->setTripulante(GC.pJog1);

    atualPersonagens = atualPersonagens->getProximo();
  }
  currentState = PLAYING;
  return true;
}
