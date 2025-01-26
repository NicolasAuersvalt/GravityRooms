#include "Entidades/Obstaculos/espinho.h"

#include <iostream>
using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Espinho::Espinho(const sf::Vector2f pos, const sf::Vector2f tam)
    : Obstaculo(pos, tam) {
  setSprite("assets/espinhoG.png", pos.x, pos.y);
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