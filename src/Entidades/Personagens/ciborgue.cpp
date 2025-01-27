#include "Entidades/Personagens/ciborgue.h"
// #include "gerenciador_grafico.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Ciborgue::Ciborgue(const Vector2f pos, Tripulante* tripulante)
    : Inimigo(pos, Vector2f(100.0f, 80.0f), tripulante) {
  std::cout << "Creating Ciborgue at position: " << pos.x << "," << pos.y
            << std::endl;
  nivel_maldade = 1;
  setSprite("assets/ciborgueG.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  std::cout << "here Position: " << pos.x << " " << pos.y << std::endl;
  // Debug output
  std::cout << "Ciborgue sprite position: " << sprite.getPosition().x << ","
            << sprite.getPosition().y << std::endl;
  std::cout << "Ciborgue corpo position: " << corpo.getPosition().x << ","
            << corpo.getPosition().y << std::endl;
}

Ciborgue::~Ciborgue() {}
void Ciborgue::executar() {
  if (vivo) {
    std::cout << "Ciborgue executing at: " << corpo.getPosition().x << ","
              << corpo.getPosition().y << std::endl;
    mover();
    desenhar();
  }
}

void Ciborgue::danificar(Tripulante* p) {}

void Entidades::Personagens::Ciborgue::mover() {
  if (vivo) {
    Inimigo::mover();
  }
}
void Ciborgue::salvarDataBuffer(nlohmann::ordered_json& json) {}

void Ciborgue::colidir(Entidade* outro, string direction) {}

}  // namespace Entidades::Personagens
