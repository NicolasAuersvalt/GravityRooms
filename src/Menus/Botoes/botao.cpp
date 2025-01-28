#include "Menus/Botoes/botao.h"

namespace Menus {

namespace Botoes {

Botao::Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID,
             const float tempoTroca, const sf::Vector2f tamMax)
    : Ente(ID),
      pos(pos),
      tam(tam),
      textura(new sf::Texture()),
      tamMax(tamMax == sf::Vector2f(0.0f, 0.0f) ? tam : tamMax),
      tempoTroca(tempoTroca),
      tempo(0.0f),
      tamInicial(tam),
      aumentando(true) {
  caixa.setPosition(pos);
  caixa.setSize(tam);
}

Botao::~Botao() {
  if (textura) {
    delete (textura);
    textura = nullptr;
  }
}

void Botao::atualizarPosicaoCaixa(const sf::Vector2f pos) {
  this->pos = pos;
  caixa.setPosition(pos);
}

const sf::Vector2f Botao::getPos() const { return caixa.getPosition(); }

void Botao::setTextura(sf::Texture* textura) {
  this->textura = textura;
  caixa.setTexture(textura);
}

void Botao::desenhar() {}

void Botao::atualizarAnimacao() {}

}  // namespace Botoes

}  // namespace Menus
