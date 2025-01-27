#include "Entidades/Personagens/clone.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Clone::Clone(const sf::Vector2f pos, Tripulante* tripulante)
    : Inimigo(pos, sf::Vector2f(150.0f, 150.0f), tripulante) {
  nivel_maldade = 3;
  setSprite("assets/cloneG.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  std::cout << "here Position: " << pos.x << " " << pos.y << std::endl;
}

Clone::~Clone() {}
void Clone::executar() {
  if (vivo) mover();
}

void Clone::salvarDataBuffer(nlohmann::ordered_json& json) {}
void Clone::mover() {
  if (vivo) {
    Inimigo::mover();
  }
}
void Clone::colidir(Entidade* outro, string direction) {}
void Clone::danificar(Tripulante* p) {}
}  // namespace Entidades::Personagens
