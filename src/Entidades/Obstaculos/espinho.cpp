#include "Entidades/Obstaculos/espinho.h"

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Espinho::Espinho(const sf::Vector2f pos, const sf::Vector2f tam)
    : Obstaculo(pos, tam) {
  setSprite("assets/espinhoG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(90.0f, 90.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
  std::cout << "Position: " << pos.x << " " << pos.y << std::endl;
}

Espinho::~Espinho() {}
void Espinho::executar() {
  mover();
  desenhar();
}
void Espinho::mover() {}
void Espinho::salvar() {
  // Add implementation
}

}  // namespace Entidades::Obstaculos