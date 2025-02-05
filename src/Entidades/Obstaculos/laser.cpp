#include "Entidades/Obstaculos/laser.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Laser::Laser(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID)
    : Obstaculo(pos, tam, ID) {
  this->dano = 2;
  // setSprite("assets/laserP.png", pos.x, pos.y);
  setSprite("assets/laser.png", pos.x, pos.y);

  setTamanho(sf::Vector2f(90.0f, 90.0f));
  sprite.setOrigin(45.0f, 45.0f);
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

Laser::~Laser() {}
void Laser::executar() {
  mover();
  desenhar();
}
void Laser::mover() {}

void Laser::colisao(Entidade *outraEntidade, sf::Vector2f ds) {}
int Entidades::Obstaculos::Laser::getDano() { return dano; }
}  // namespace Entidades::Obstaculos
