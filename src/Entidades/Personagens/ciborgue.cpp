#include "Entidades/Personagens/ciborgue.h"
// #include "gerenciador_grafico.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Ciborgue::Ciborgue(const Vector2f pos, Tripulante* tripulante)
    : Inimigo(pos, Vector2f(100.0f, 80.0f), tripulante) {
  nivel_maldade = 1;
  setSprite("assets/ciborgueG.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  std::cout << "here Position: " << pos.x << " " << pos.y << std::endl;
}

Ciborgue::~Ciborgue() {}
void Ciborgue::executar() {
  if (vivo) mover();
}

void Ciborgue::danificar(Tripulante* p) {}

void Entidades::Personagens::Ciborgue::mover() {
  cout << "ciborgue tas vivo talbez" << endl;
  if (vivo) {
    cout << "ciborgue movendo" << endl;
    Inimigo::mover();
  }
}
void Ciborgue::salvarDataBuffer(nlohmann::ordered_json& json) {}

void Ciborgue::colidir(Entidade* outro, string direction) {}

}  // namespace Entidades::Personagens
