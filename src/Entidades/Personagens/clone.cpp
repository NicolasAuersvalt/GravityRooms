#include "Entidades/Personagens/clone.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Clone::Clone(const sf::Vector2f pos, Tripulante* tripulante, const IDs::IDs ID)
    : Inimigo(pos, sf::Vector2f(150.0f, 150.0f), tripulante, ID) {
  this->pontosVida = 20;
  this->dano = 3;
  nivel_maldade = 3;
  // setSprite("assets/cloneP.png", pos.x, pos.y);
  setSprite("assets/clone.png", pos.x, pos.y);

  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  std::cout << "cloneG Position: " << pos.x << " " << pos.y << std::endl;
}

Clone::~Clone() {}
void Clone::executar() {
  if (vivo) mover();
}

void Clone::salvarDataBuffer(nlohmann::ordered_json& json) {}
void Clone::mover() {
  if (vivo) {
    Inimigo::mover();
    atirar();
  }
}

void Clone::danificar(Tripulante* p) {}
void Clone::atirar() {
  if (!projetil->getAtivo()) {
    projetil->setAtivo(true, getSprite().getPosition());
  }
}
}  // namespace Entidades::Personagens
