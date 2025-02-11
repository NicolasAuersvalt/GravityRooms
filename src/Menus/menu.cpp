#include "Menus/menu.h"

namespace Menus {
Menu::Menu(const IDs::IDs ID, const Vector2f tamBotao, const string nome,
           const unsigned int tamFonte)
    : Ente(ID),
      listaBotaoTexto(),
      it(),
      tamBotao(tamBotao),
      tamJanela(1280.0f, 920.0f),  // Ajuste manual da tela
      botaoSelecionado(false),
      titulo(nome, tamFonte) {
  if (!texturaBackground.loadFromFile("assets/menu.png")) {
    cerr << "Erro ao carregar textura do background!" << endl;
    exit(1);
  }
  spriteBackground.setTexture(texturaBackground);

  atualizarPosicaoFundo();
}

Menu::~Menu() {
  if (!listaBotaoTexto.empty()) {
    for (it = listaBotaoTexto.begin(); it != listaBotaoTexto.end(); it++) {
      delete (*it);
      *it = nullptr;
    }
    listaBotaoTexto.clear();
  }
}

void Menu::addBotao(const string info, const Vector2f pos, const IDs::IDs ID,
                    const Color corSelecionado) {
  float centerX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
  Vector2f centeredPos(centerX, pos.y);

  Botoes::BotaoTexto *botao =
      new Botoes::BotaoTexto(info, tamBotao, centeredPos, ID, corSelecionado);
  if (botao) {
    listaBotaoTexto.push_back(botao);
  }
}

string Menu::getTipo() const { 
  return "Menu";
 }

void Menu::atualizarPosicaoFundo() {
  // Centraliza o background
  FloatRect bounds = spriteBackground.getLocalBounds();
  spriteBackground.setOrigin(bounds.width / 2, bounds.height / 2);
  spriteBackground.setPosition(tamJanela.x / 2, tamJanela.y / 2);

  // Centraliza o título
  titulo.setPos(Vector2f(tamJanela.x / 2, tamJanela.y * 0.2f));
}

void Menu::inicializarIterator() {
  try {
    it = listaBotaoTexto.begin();
    (*it)->setSelecionado(true);
  } catch (const exception &e) {
    cerr << e.what() << endl;
    exit(1);
  }
}

void Menu::selecionaCima() {
  Botoes::BotaoTexto *botao = *it;
  botao->setSelecionado(false);
  if (it == listaBotaoTexto.begin()) {
    it = listaBotaoTexto.end();
  }
  it--;
  botao = *it;
  botao->setSelecionado(true);
}

void Menu::selecionaBaixo() {
  Botoes::BotaoTexto *botao = *it;
  botao->setSelecionado(false);
  it++;
  if (it == listaBotaoTexto.end()) {
    it = listaBotaoTexto.begin();
  }
  botao = *it;
  botao->setSelecionado(true);
}

const IDs::IDs Menu::getIDBotaoSelecionado() const { return (*it)->getID(); }

void Menu::eventoTeclado(const Keyboard::Key tecla) {
  if (listaBotaoTexto.empty()) {
    return;
  }

  if (it == listaBotaoTexto.end()) {
    inicializarIterator();
    return;
  }

  try {
    if (*it) {
      (*it)->setSelecionado(false);

      if (tecla == Keyboard::Down) {
        it++;
        if (it == listaBotaoTexto.end()) {
          it = listaBotaoTexto.begin();
        }
      } else if (tecla == Keyboard::Up) {
        if (it == listaBotaoTexto.begin()) {
          it = --listaBotaoTexto.end();
        } else {
          --it;
        }
      } else if (tecla == Keyboard::Enter) {
        botaoSelecionado = true;
      }

      (*it)->setSelecionado(true);
    }
  } catch (exception &e) {
    cerr << "Error in eventoTeclado: " << e.what() << endl;
    inicializarIterator();
  }
}
bool Menu::getSelecionado() { return botaoSelecionado; }

void Menu::setSelecionado(bool status) { botaoSelecionado = status; }

void Menu::desenhar(Gerenciador_Grafico *GG) {
  // Desenha os botões
  list<Botoes::BotaoTexto *>::iterator aux;

  GG->desenharBackground(spriteBackground);
  for (aux = listaBotaoTexto.begin(); aux != listaBotaoTexto.end(); aux++) {
    Botoes::BotaoTexto *botao = *aux;
    botao->desenhar(*GG);
    botao = nullptr;
  }
}

}  // namespace Menus