
#include "Menus/menuPrincipal.h"

namespace Menus {

MenuPrincipal::MenuPrincipal()
    : Menu(2, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "MenuPrin", 180) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuPrincipal::MenuPrincipal(const int ID, std::string nome,
                             const unsigned int tamFonte)
    : Menu(ID, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::criarBotoes() {
  const float posBotaoX = 200.0f;
  addBotao("Novo Jogo", sf::Vector2f(posBotaoX, 800.0f / 2.0f), 1,
           sf::Color{0, 255, 0});
  addBotao("Carregar Jogo",
           sf::Vector2f(posBotaoX, 800.0f / 2.0f + tamBotao.y * 1.2f), 0,
           sf::Color{0, 255, 0});
  addBotao("Colocacao",
           sf::Vector2f(posBotaoX, 800.0f / 2.0f + tamBotao.y * 2.4f), 0,
           sf::Color{0, 255, 0});
  addBotao("Opcao", sf::Vector2f(posBotaoX, 800.0f / 2.0f + tamBotao.y * 3.6f),
           0, sf::Color{0, 255, 0});
  addBotao("Sair", sf::Vector2f(posBotaoX, 800.0f / 2.0f + tamBotao.y * 4.8f),
           10, sf::Color{0, 255, 0});
  inicializarIterator();
}

void MenuPrincipal::executar() {
  // conteúdo do efeito Parallax

  // desenha todo o conteúdo do menu principal na tela
  // desenhar();
}

}  // namespace Menus
