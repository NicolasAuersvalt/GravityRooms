
#include "Menus/menuPrincipal.h"

namespace Menus {

MenuPrincipal::MenuPrincipal(IDs::IDs id)
    : Menu(id, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "MenuPrin",
           180) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
  criarFundo();
}

MenuPrincipal::MenuPrincipal(const IDs::IDs ID, std::string nome,
                             const unsigned int tamFonte)
    : Menu(IDs::IDs::menu_principal,
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::criarBotoes() {
  float centerX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
  float startY = tamJanela.y * 0.9f;
  float spacing = tamBotao.y * 1.5f;
  addBotao("LABORATORIO", sf::Vector2f(centerX, startY),
           IDs::IDs::botao_novoJogo, sf::Color(0, 255, 0));
  addBotao("NAVE", sf::Vector2f(centerX, startY + spacing), IDs::IDs::botao2,
           sf::Color(0, 255, 0));
  addBotao("RANKING", sf::Vector2f(centerX, startY + spacing * 2),
           IDs::IDs::botao_colocacao, sf::Color(0, 255, 0));
  addBotao("CARREGAR JOGO", sf::Vector2f(centerX, startY + spacing * 3),
           IDs::IDs::botao_carregar, sf::Color(0, 255, 0));
  addBotao("SAIR", sf::Vector2f(centerX, startY + spacing * 4),
           IDs::IDs::botao_sair, sf::Color(0, 255, 0));

  inicializarIterator();
}

void MenuPrincipal::executar() {}

void MenuPrincipal::criarFundo() {
  if (!texturaBackground.loadFromFile("assets/logo.png")) {
    std::cerr << "Erro ao carregar textura do background do menu principal!"
              << std::endl;
    exit(1);
  }
  spriteBackground.setTexture(texturaBackground);
  atualizarPosicaoFundo();
}

}  // namespace Menus
