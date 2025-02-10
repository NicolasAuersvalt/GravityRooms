#include "Menus/menuPause.h"

namespace Menus {

MenuPause::MenuPause(IDs::IDs id)
    : Menu(IDs::IDs::menu_pausa, Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),
           "PAUSA", 180) {
  titulo.setPos(Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(Color{0, 200, 0});
}

MenuPause::MenuPause(const IDs::IDs ID, string nome,
                     const unsigned int tamFonte)
    : Menu(IDs::IDs::menu_pausa, // ID CORRETO
           Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(Color{0, 200, 0});
}

MenuPause::~MenuPause() {}

void MenuPause::criarBotoes() {
  // Centralizar horizontalmente (igual ao menu principal)
  float centerX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
  float startY = tamJanela.y * 0.75f; // Posição Y inicial
  float spacing = tamBotao.y * 1.5f;

  // Botões em maiúsculas e centralizados
  addBotao("CONTINUAR", Vector2f(centerX, startY), IDs::IDs::botao_voltar,
           Color{0, 255, 0});
  addBotao("SALVAR JOGADA", Vector2f(centerX, startY + spacing),
           IDs::IDs::menu_salvar_jogada, Color{0, 255, 0});
  addBotao("VOLTAR PARA O MENU", Vector2f(centerX, startY + spacing * 2),
           IDs::IDs::estado_menu_principal, Color{0, 255, 0});
  addBotao("SAIR", Vector2f(centerX, startY + spacing * 3),
           IDs::IDs::botao_sair, Color{0, 255, 0});

  inicializarIterator(); // Inicializa o iterador
}

void MenuPause::executar() {}

} // namespace Menus