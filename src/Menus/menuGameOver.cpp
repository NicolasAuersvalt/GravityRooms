#include "Menus/MenuGameOver.h"

namespace Menus {

MenuGameOver::MenuGameOver(IDs::IDs id)
    : Menu(IDs::IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),
           "PAUSA", 180) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuGameOver::MenuGameOver(const IDs::IDs ID, std::string nome,
                           const unsigned int tamFonte)
    : Menu(IDs::IDs::menu_pausa,  // ID CORRETO
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuGameOver::~MenuGameOver() {}

void MenuGameOver::criarBotoes() {
  // Centralizar horizontalmente (igual ao menu principal)
  float centerX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
  float startY = tamJanela.y * 0.4f;  // Posição Y inicial
  float spacing = tamBotao.y * 1.5f;

  // Botões em maiúsculas e centralizados
  addBotao("CONTINUAR", sf::Vector2f(centerX, startY), IDs::IDs::botao_voltar,
           sf::Color{0, 255, 0});
  addBotao("SAIR", sf::Vector2f(centerX, startY + spacing),
           IDs::IDs::botao_sair, sf::Color{0, 255, 0});

  inicializarIterator();  // Inicializa o iterador
}

void MenuGameOver::executar() {
  // conteúdo do efeito Parallax
}

}  // namespace Menus