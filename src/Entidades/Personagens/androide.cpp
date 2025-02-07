#include "Entidades/Personagens/androide.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens {

Androide::Androide(const Vector2f pos, Tripulante *tripulante,
                   const IDs::IDs ID)
    : Inimigo(pos, sf::Vector2f(100.0f, 100.0f), tripulante, ID) {
  this->dano = 2;
  this->pontosVida = 10;
  nivel_maldade = 2;
  setSprite("assets/androide.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
}

Androide::~Androide() {}
void Androide::executar() {
  if (vivo)
    mover();
}

void Androide::danificar(Tripulante *p) {}

void Androide::mover() {
  if (vivo) {
    Inimigo::mover();
  }
}

int Androide::getDano() { return dano; }

void Androide::salvarDataBuffer(nlohmann::ordered_json &json) {}
<<<<<<< HEAD
=======

REGISTRAR_CLASSE(Androide, "androide")
>>>>>>> psave
} // namespace Entidades::Personagens
