#include "Entidades/Obstaculos/espinho.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Espinho::Espinho(const sf::Vector2f pos, const sf::Vector2f tam,
                 const IDs::IDs ID)
    : Obstaculo(pos, tam, ID) {
  this->dano = 2;
  setSprite("assets/espinhoG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(90.0f, 90.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
  std::cout << "Espinho Position: " << pos.x << " " << pos.y << std::endl;
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

void Espinho::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
  // if (outraEntidade->getID() == IDs::IDs::tripulante) {
  //   Personagem::Tripulante::tripulante* pTripulante =
  //       dynamic_cast<Personagem::Tripulante::tripulante*>(outraEntidade);
  //   pTripulante->tomarDano(dano);
  //   if (!pTripulante->getMorrer()) {
  //     const float gravidade = 1200.0f;
  //     const float tamPulo = 120.0f;
  //     pTripulante->setVelFinal(sf::Vector2f(pTripulante->getVelFinal().x,
  //                                           -sqrt(2.0f * gravidade *
  //                                           tamPulo)));
  //   }
  // }
}
int Entidades::Obstaculos::Espinho::getDano() { return dano; }
}  // namespace Entidades::Obstaculos
