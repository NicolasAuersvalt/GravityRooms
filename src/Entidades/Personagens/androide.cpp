#include "Entidades/Personagens/androide.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens {

Androide::Androide(const Vector2f pos, Tripulante* tripulante,
                   const IDs::IDs ID)
    : Inimigo(pos, sf::Vector2f(100.0f, 100.0f), tripulante, ID) {
  this->dano = 2;
  this->pontosVida = 10;
  nivel_maldade = 2;
  // setSprite("assets/androidP.png", pos.x, pos.y);
  setSprite("assets/androide.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  std::cout << "Androide Position: " << pos.x << " " << pos.y << std::endl;
}

Androide::~Androide() {}
void Androide::executar() {
  if (vivo) mover();
}

void Androide::danificar(Tripulante* p) {}
void Androide::mover() {
  if (vivo && this != nullptr) {
    Inimigo::mover();
  }
}
// void Androide::colidir(Entidade* outro, string direction) {

int Androide::getDano() { return dano; }

// }

void Androide::salvarDataBuffer(nlohmann::ordered_json& json) {}
}  // namespace Entidades::Personagens
