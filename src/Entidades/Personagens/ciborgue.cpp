#include "Entidades/Personagens/ciborgue.h"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Ciborgue::Ciborgue(const sf::Vector2f pos, Tripulante* tripulante)
    : Inimigo(pos, Vector2f(100.0f, 80.0f), tripulante) {
  nivel_maldade = 1;
}

Ciborgue::~Ciborgue() {}
void Ciborgue::executar() {
  if (vivo) mover();
}

void Ciborgue::danificar(Tripulante* p) {}
}  // namespace Entidades::Personagens
