#include "Entidades/Obstaculos/espinho.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Espinho::Espinho(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Obstaculo(pos, tam, ID) {
  this->dano = 2;
  setSprite("assets/espinho.png", pos.x, pos.y);

  setTamanho(Vector2f(90.0f, 90.0f));
  sprite.setOrigin(45.0f, 45.0f);
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

Espinho::~Espinho() {}
void Espinho::executar() {
  mover();
  desenhar();
}
void Espinho::mover() {}

void Espinho::colisao(Entidade *outraEntidade, Vector2f ds) {}
int Entidades::Obstaculos::Espinho::getDano() { return dano; }

REGISTRAR_CLASSE(Espinho, "espinho")
} // namespace Entidades::Obstaculos
