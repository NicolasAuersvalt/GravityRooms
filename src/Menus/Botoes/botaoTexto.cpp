#include "Menus/Botoes/botaoTexto.h"

namespace Menus {
namespace Botoes {

BotaoTexto::BotaoTexto(const std::string info, const sf::Vector2f pos,
                       const sf::Vector2f tam, const IDs::IDs ID,
                       const sf::Color corSelecionado)
    : Botao(tam, pos, ID, 0.01f),
      Texto(info, 24),
      corSelecionado(corSelecionado),
      selecionado(false) {
  atualizarPosicaoCaixa(pos);
}

BotaoTexto::~BotaoTexto() {}

void BotaoTexto::atualizarPosicaoCaixa(const sf::Vector2f pos) {
  this->pos = pos;
  caixa.setPosition(pos);

  sf::Vector2f centerPos(pos.x + (tam.x / 2.0f),  // Centro x
                         pos.y + (tam.y / 2.0f)   // Centro y
  );

  setPos(centerPos);
}

void BotaoTexto::setSelecionado(bool selecionado) {
  setCorTexto(selecionado ? corSelecionado : sf::Color::White);
  this->selecionado = selecionado;
}

bool BotaoTexto::getSelecionado() const { return selecionado; }

void BotaoTexto::desenhar(Gerenciador_Grafico& pGrafico) {
  pGrafico.desenharTexto(getTexto());
}

}  // namespace Botoes
}  // namespace Menus
