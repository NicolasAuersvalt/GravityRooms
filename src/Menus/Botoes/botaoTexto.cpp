#include "Menus/Botoes/botaoTexto.h"

namespace Menus {

namespace Botoes {

BotaoTexto::BotaoTexto(const std::string info, const sf::Vector2f pos,
                       const sf::Vector2f tam, const IDs::IDs ID,
                       const sf::Color corSelecionado)
    : Botao(tam, pos, ID, 0.01f),
      corSelecionado(corSelecionado),
      selecionado(false) {
  // Load font for sf::Text
  if (!font.loadFromFile("assets/Fontes/light-arial.ttf")) {
    // Handle error if font loading fails
    std::cerr << "Failed to load font!" << std::endl;
  }

  texto.setFont(font);
  texto.setString(info);
  texto.setCharacterSize(24);            // Set font size
  texto.setFillColor(sf::Color::White);  // Default color

  // Position the text
  sf::Vector2f tamTexto = getTamTexto();
  sf::Vector2f posTexto =
      sf::Vector2f(pos.x + tam.x / 2.0f - tamTexto.x / 2.0f,
                   pos.y + tam.y / 2.0f - tamTexto.y / 2.0f);
  texto.setPosition(posTexto);
}

BotaoTexto::~BotaoTexto() {}

const sf::Vector2f BotaoTexto::getTamTexto() const {
  return sf::Vector2f(texto.getGlobalBounds().width,
                      texto.getGlobalBounds().height);
}

void BotaoTexto::atualizarAnimacao() {
  // this->tempo += pGrafico->getTempo();
  if (selecionado) {
    if (this->tempo > tempoTroca) {
      sf::Uint8 transparente = texto.getFillColor().a;
      if (texto.getFillColor().a < 255) {
        transparente += 5;
      } else {
        transparente -= 5;
      }
      texto.setFillColor(sf::Color(255, 255, 255, transparente));
      this->tempo = 0.0f;
    }
  } else {
    this->tempo = 0.0f;
  }
}

void BotaoTexto::atualizarPosicaoCaixa(const sf::Vector2f pos) {
  this->pos = pos;
  caixa.setPosition(pos);
  sf::Vector2f tamTexto = getTamTexto();
  sf::Vector2f posTexto =
      sf::Vector2f(pos.x + tam.x / 2.0f - tamTexto.x / 2.0f,
                   pos.y + tam.y / 2.0f - tamTexto.y / 2.0f);
  texto.setPosition(posTexto);
}

void BotaoTexto::setSelecionado(bool selecionado) {
  texto.setFillColor(selecionado ? corSelecionado : sf::Color::White);
  this->selecionado = selecionado;
}

const bool BotaoTexto::getSelecionado() const { return selecionado; }
void BotaoTexto::desenhar(Gerenciador_Grafico& pGrafico) {
  atualizarAnimacao();
  pGrafico.desenharTexto(texto);
}
}  // namespace Botoes

}  // namespace Menus
