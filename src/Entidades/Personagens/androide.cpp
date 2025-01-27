#include "Entidades/Personagens/androide.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens {

Androide::Androide(const Vector2f pos, Tripulante* tripulante)
    : Inimigo(pos, sf::Vector2f(150.0f, 150.0f), tripulante) {
  nivel_maldade = 2;
  setSprite("assets/androidG.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  std::cout << "here Position: " << pos.x << " " << pos.y << std::endl;
}

Androide::~Androide() {}
void Androide::executar() {
  if (vivo) mover();
}

void Androide::danificar(Tripulante* p) {}

void Androide::mover() {
  if (vivo) {
    Inimigo::mover();
  }
}
void Androide::colidir(Entidade* outro, string direction) {
  // int index = other->get_id();
  // switch (index)
  // {
  // case 1:
  //     other->inflict_damage(damage);
  //     break;
  // case 11:
  //     if (direction == "Right" || direction == "Left")
  //     {
  //         vel = sf::Vector2f(-CR * vel.x, vel.y);
  //     }
  //     else
  //     {
  //         vel = sf::Vector2f(vel.x, -CR * vel.y);
  //     }
  //     break;

  // default:
  //     break;
  // }
}

void Androide::salvarDataBuffer(nlohmann::ordered_json& json) {}
}  // namespace Entidades::Personagens
