#include "Menus/menu.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Menus {

// Construtor
/*
Menu::Menu(const ID,  const Vector2f tamBotao, const string nome,
                const unsigned int tamFonte)
{
    cout << "Construtor Menu" << endl;

}
*/
Menu::Menu() {
#ifdef _WIN32
  // Caminho para Windows
  if (!font.loadFromFile("assets/Fontes/DejaVuSans-Bold.ttf")) {
    std::cerr << "Erro: Não foi possível carregar a fonte no Windows!"
              << std::endl;
  }
#elif __linux__
  // Caminho para Linux
  if (!font.loadFromFile(
          "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
    std::cerr << "Erro: Não foi possível carregar a fonte no Linux!"
              << std::endl;
  }
#endif
  // font.loadFromFile("assets/Fontes/DejaVuSans-Bold.ttf");

  // Inicializando as opções do menu
  fases.push_back("Nave");
  fases.push_back("Laboratorio");

  // Criando os textos para as fases
  for (size_t i = 0; i < fases.size(); ++i) {
    Text texto;
    texto.setFont(font);
    texto.setString(fases[i]);
    texto.setCharacterSize(30);
    texto.setFillColor(
        Color::White);  // Inicialmente todas as fases são brancas
    texto.setPosition(500, 300 + (i * 40));
    textos.push_back(texto);
  }

  // Cor da fase selecionada (verde)
  textos[0].setFillColor(Color::Green);
  selecionada = 0;
}

// Destrutor
Menu::~Menu() {}

int Menu::obterSelecao(Event& evento) {
  if (evento.type == Event::KeyPressed) {
    if (evento.key.code == Keyboard::Up) {
      moverSelecaoParaCima();

    } else if (evento.key.code == Keyboard::Down) {
      moverSelecaoParaBaixo();

    } else if (evento.key.code == Keyboard::Enter) {
      return +1;  // Retorna o número da fase selecionada
    }
  }
  return 0;
}

void Menu::moverSelecaoParaCima() {
  cout << "moverSelecaoParaBaixo" << endl;

  if (selecionada > 0) {
    textos[selecionada].setFillColor(Color::White);  // Desmarca a opção

    selecionada--;

    textos[selecionada].setFillColor(Color::Green);  // Marca a nova opção
  }
}

void Menu::desenhar(Gerenciador_Grafico& gerenciador) {
  // cout << "Desenhando Texto no Gerenciador Grafico" << endl;
  for (auto& texto : textos) {
    gerenciador.desenharTexto(texto);
  }
}

void Menu::moverSelecaoParaBaixo() {
  cout << "moverSelecaoParaBaixo" << endl;
  if (selecionada < fases.size() - 1) {
    textos[selecionada].setFillColor(sf::Color::White);  // Desmarca a opção
    selecionada++;
    textos[selecionada].setFillColor(sf::Color::Green);  // Marca a nova opção
  }
}

void Menu::selecionaCima() { cout << "Menu: Selecionado para Cima" << endl; }

void Menu::selecionaBaixo() { cout << "Menu: Selecionado para Baixo" << endl; }

void Menu::addBotao(const string info, const Vector2f pos, /* const ID,*/
                    const Color corSelecionado) {
  cout << "Menu: Add Botao" << endl;
}

void Menu::atualizarPosicaoFundo() { cout << "Menu: Atualizar Fundo" << endl; }

// ===/===/===/===/ Outros  ===/===/===/===/
}  // namespace Menus