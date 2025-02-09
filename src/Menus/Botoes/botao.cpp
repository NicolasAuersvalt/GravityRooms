#include "Menus/Botoes/botao.h"

namespace Menus {

namespace Botoes {

Botao::Botao(const Vector2f tam, const Vector2f pos, const IDs::IDs ID,
             const float tempoTroca, const Vector2f tamMax)
    : Ente(ID),
      pos(pos),
      tam(tam),
      textura(new Texture()),
      tamMax(tamMax == Vector2f(0.0f, 0.0f) ? tam : tamMax),
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

void Botao::atualizarPosicaoCaixa(const Vector2f pos) {
  this->pos = pos;
  caixa.setPosition(pos);
}

const Vector2f Botao::getPos() const { return caixa.getPosition(); }

void Botao::setTextura(Texture *textura) {
  this->textura = textura;
  caixa.setTexture(textura);
}

void Botao::desenhar() {}

}  // namespace Botoes

}  // namespace Menus
