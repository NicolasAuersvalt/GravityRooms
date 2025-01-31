#include "Entidades/Personagens/clone.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Clone::Clone(const sf::Vector2f pos, Tripulante* tripulante, const IDs::IDs ID)
    : Inimigo(pos, sf::Vector2f(100.0f, 100.0f), tripulante, ID),
      projetil(nullptr) {
  this->pontosVida = 20;
  this->dano = 3;

  nivel_maldade = 3;
  // setSprite("assets/cloneP.png", pos.x, pos.y);
  setSprite("assets/clone.png", pos.x, pos.y);

  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
}

Clone::~Clone() {}
void Clone::executar() {
  if (vivo) mover();
}

void Clone::salvarDataBuffer(nlohmann::ordered_json& json) {}
void Clone::mover() {
  if (vivo) {
    Inimigo::mover();
    // Try to shoot if enough time has passed (every 2 seconds)
    if (timerTiro.getElapsedTime().asSeconds() >= 2.0f) {
      atirar();
      timerTiro.restart();
    }
  }
}

void Clone::danificar(Tripulante* p) {}

void Clone::atirar() {
  if (!projetil->getAtivo()) {
    Vector2f posClone = sprite.getPosition();
    Vector2f posTripulante = tripulante->getSprite().getPosition();

    // Calculate direction vector towards player
    Vector2f direcao = posTripulante - posClone;
    float magnitude = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    if (magnitude != 0) {
      direcao /= magnitude;  // Normalize direction vector
    }

    // Set projectile position and velocity
    projetil->setPosicao(posClone.x, posClone.y);
    projetil->setVelocidade(direcao * 10.0f);  // Adjust speed as needed
    projetil->setAtivo(true, posClone);
  }
}
int Clone::getDano() { return dano; }

}  // namespace Entidades::Personagens
