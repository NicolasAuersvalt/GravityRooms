#include "gravity_rooms.h"

#include <Fases/laboratorio.h>
#include <Fases/nave.h>

// Construtor
Gravity_Rooms::Gravity_Rooms()
    : GG(),
      listaPersonagem(),
      listaObstaculo(),
      GC(&listaPersonagem, &listaObstaculo),
      menuGeral(),
      fase(nullptr) {
  Ente::setGerenciador(&GG);

  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("assets/nave1.jpg")) {
    std::cerr << "Erro ao carregar o background!" << std::endl;
    return;
  }

  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setPosition(25, 25);

  std::ifstream arquivo("dados_salvos.json");
  if (arquivo.is_open()) {
    nlohmann::ordered_json buffer;
    arquivo >> buffer;
    arquivo.close();
    std::cout << "Dados carregados de 'dados_salvos.json'.\n";
  } else {
    std::cerr << "Erro ao abrir o arquivo para carregar os dados.\n";
  }

  // Vector2f pos = pJog1.getPosicao();

  // pJog1.setSprite("assets/tripulanteG.png", pos.x, pos.y);

  // std::cout << "bli\n";
  // listaPersonagem.incluir(static_cast<Entidade *>(&pJog1));

  // pAnd1.setSprite("assets/androidG.png", 0, 0);
  // pAnd1.setVida(10);

  // listaPersonagem.incluir(static_cast<Entidade *>(&pAnd1));

  menuGeral.criarBotoes();
  executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms() {}

void Gravity_Rooms::executar() {
  bool primeiraVez = false;

  GG.executar();

  while (GG.estaAberta()) {
    sf::Event eventao;

    if (GG.getJanela().pollEvent(eventao)) {
      if (eventao.type == sf::Event::KeyPressed) {
        menuGeral.eventoTeclado(eventao.key.code);
      }
      if (menuGeral.getSelecionado()) {
        IDs::IDs selecao = menuGeral.getIDBotaoSelecionado();
        if (selecao == IDs::IDs::botao_novoJogo) {
          criarFases(IDs::IDs::fase_laboratorio);
          break;
        }
        if (selecao == IDs::IDs::botao_sair) {
          exit(1);
        }
      }
      primeiraVez = true;
    }

    GG.limpar();
    menuGeral.desenhar(&GG);
    GG.exibir();
  }
  // GC.incluirInimigo(static_cast<Inimigo *>(&pAnd1));

  while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
    sf::Event evento;

    while (GG.processarEvento(evento)) {
      if (evento.type == sf::Event::Closed) {
        GG.fechar();
      }

      if (evento.type == sf::Event::KeyPressed) {
        // Verifica se a tecla pressionada foi 'Y'

        if (evento.key.code == sf::Keyboard::Y) {
          // Chama o método de salvar buffer do objeto PJog1
          nlohmann::ordered_json buffer;
          // Exemplo: Salvar o buffer em um arquivo
          std::ofstream arquivo("dados_salvos.json");
          if (arquivo.is_open()) {
            arquivo << buffer.dump(4);  // Salva com indentação de 4 espaços
            arquivo.close();
            std::cout << "Dados salvos em 'dados_salvos.json'.\n";
          } else {
            std::cerr << "Erro ao abrir o arquivo para salvar os dados.\n";
          }
        }
      }
    }

    GG.limpar();  // Limpa a tela antes de desenhar qualquer coisa

    // Desenha os objetos na ordem correta
    // GG.desenhar(backgroundSprite); // Desenha o fundo primeiro

    // GG.desenharEnte(&pJog1);  // Desenha o Tripulante 1 (ou qualquer outro
    // ente)
    listaObstaculo.desenharTodos();

    listaPersonagem.desenharTodos();
    // Desenha os outros sprites da lista
    GC.setLista_Entidades(&listaPersonagem, &listaObstaculo);
    GC.executar(&listaPersonagem, &listaObstaculo);
    cout << "bloia4 " << endl;
    GG.exibir();  // Exibe a tela com todos os objetos desenhados
    // Atualiza os objetos, caso necessário (atualização de movimentos,
    // animações, etc.)
    listaPersonagem.atualizarTodas();
    listaObstaculo.atualizarTodas();
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
      // GC.incluirTripulante(*tripPtr);
    } else {
      // GC.incluirInimigo(static_cast<Inimigo *>(atualPersonagens->pInfo));
    }
    listaPersonagem.incluir(
        atualPersonagens->pInfo);  // Add entity to listaPersonagem
    atualPersonagens = atualPersonagens->getProximo();
  }
}

// ===/===/===/===/ Outros  ===/===/===/===/