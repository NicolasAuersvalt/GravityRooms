#include "gravity_rooms.h"

#include <Fases/laboratorio.h>
#include <Fases/nave.h>

// Construtor
Gravity_Rooms::Gravity_Rooms()
    : GG(),
      listaPersonagem(),
      listaObstaculo(),
      GC(&listaPersonagem, &listaObstaculo),
      GE(),
      menuGeral(),
      fase(nullptr) {
  Ente::setGerenciador(&GG);

  Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("assets/nave1.jpg")) {
    cerr << "Erro ao carregar o background!" << endl;
    return;
  }

  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setPosition(25, 25);

  ifstream arquivo("dados_salvos.json");
  if (arquivo.is_open()) {
    nlohmann::ordered_json buffer;
    arquivo >> buffer;
    arquivo.close();
    cout << "Dados carregados de 'dados_salvos.json'.\n";
  } else {
    cerr << "Erro ao abrir o arquivo para carregar os dados.\n";
  }

  // Vector2f pos = pJog1.getPosicao();

  // pJog1.setSprite("assets/tripulanteG.png", pos.x, pos.y);

  // cout << "bli\n";
  // listaPersonagem.incluir(static_cast<Entidade *>(&pJog1));

  // pAnd1.setSprite("assets/androidG.png", 0, 0);
  // pAnd1.setVida(10);

  // listaPersonagem.incluir(static_cast<Entidade *>(&pAnd1));

  menuGeral.criarBotoes();
  executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms() {}

bool Gravity_Rooms::ligarMenu() {
  Event eventao;
  bool out = false;

  if (GG.getJanela().pollEvent(eventao)) {
    if (eventao.type == Event::KeyPressed) {
      menuGeral.eventoTeclado(eventao.key.code);
    }

    if (menuGeral.getSelecionado()) {
      IDs::IDs selecao = menuGeral.getIDBotaoSelecionado();

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
  menuGeral.desenhar(&GG);
  GG.exibir();
  return out;
}
void Gravity_Rooms::executar() {
  bool primeiraVez = false;

  GG.executar();
  while (GG.estaAberta()) {
    primeiraVez = ligarMenu();
    if (primeiraVez) break;
  }
  // GC.incluirInimigo(static_cast<Inimigo *>(&pAnd1));

  while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
    Event evento;
    if (GC.pJog1 && GC.pJog1->verificarVivo()) {
      while (GG.processarEvento(evento)) {
        if (evento.type == Event::Closed) {
          GG.fechar();
        }

        if (evento.type == Event::KeyPressed) {
          // Verifica se a tecla pressionada foi 'Y'

          if (evento.key.code == Keyboard::Y) {
            // Chama o método de salvar buffer do objeto PJog1
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
        }
      }
      cout << "bli\n";
      GG.limpar();  // Limpa a tela antes de desenhar qualquer coisa
      listaObstaculo.desenharTodos();
      listaPersonagem.desenharTodos();
      // Desenha os outros sprites da lista
      GC.setLista_Entidades(&listaPersonagem, &listaObstaculo);

      GC.executar(&listaPersonagem, &listaObstaculo);

      GG.exibir();  // Exibe a tela com todos os objetos desenhados
      // Atualiza os objetos, caso necessário (atualização de movimentos,
      // animações, etc.)

      listaPersonagem.atualizarTodas();
      listaObstaculo.atualizarTodas();
    } else {
      if (fase != nullptr) {
        delete fase;
        fase = nullptr;
      }
      if (&listaPersonagem != nullptr) {
        listaPersonagem.limparLista();  // Use limparLista() instead of limpar()
        GC.pJog1 = nullptr;             // Reset player pointer
      }
      if (&listaObstaculo != nullptr) listaObstaculo.limparLista();
      if (menuGeral.getSelecionado()) {
        menuGeral.setSelecionado(false);
      }
      primeiraVez = false;
      while (GG.estaAberta()) {
        primeiraVez = ligarMenu();
        if (primeiraVez) break;
      }
    }
  }
}

void Gravity_Rooms::criarFases(IDs::IDs faseSelecionada) {
  if (faseSelecionada == IDs::IDs::fase_laboratorio) {
    Fases::Laboratorio *aux =
        new Fases::Laboratorio(IDs::IDs::fase_laboratorio);

    if (aux == nullptr) {
      exit(1);
      cout << "nao foi possivel criar o laboratorio " << endl;
    }
    cout << " laboratorio " << endl;

    fase = static_cast<Fases::Fase *>(aux);
  } else if (faseSelecionada == IDs::IDs::fase_nave) {
    Fases::Nave *pNave = new Fases::Nave(IDs::IDs::fase_nave);
    if (pNave == nullptr) {
      exit(1);
      cout << "nao foi possivel criar a nave " << endl;
    }

    cout << " nave " << endl;
    fase = static_cast<Fases::Fase *>(pNave);
  }

  fase->criarMapa();

  cout << "nblu " << endl;
  auto atualObstaculos = fase->listaObstaculos->LEs->getPrimeiro();
  while (atualObstaculos != nullptr) {
    listaObstaculo.incluir(
        atualObstaculos->pInfo);  // Add entity to listaPersonagem
    atualObstaculos = atualObstaculos->getProximo();
  }
  cout << "abkla " << endl;
  auto atualPersonagens = fase->listaPersonagens->LEs->getPrimeiro();
  while (atualPersonagens != nullptr) {
    if (dynamic_cast<Entidades::Personagens::Tripulante *>(
            atualPersonagens->pInfo)) {
      Tripulante *tripPtr = dynamic_cast<Tripulante *>(atualPersonagens->pInfo);
      GC.incluirTripulante(*tripPtr);
    } else {
      // GC.incluirInimigo(static_cast<Inimigo *>(atualPersonagens->pInfo));
    }

    cout << "todo " << endl;
    listaPersonagem.incluir(
        atualPersonagens->pInfo);  // Add entity to listaPersonagem
    atualPersonagens = atualPersonagens->getProximo();
  }
}

// ===/===/===/===/ Outros  ===/===/===/===/