#include "Entidades/Personagens/Personagem.h"
// #include "gerenciador_grafico.h"

#include <iostream>

#include "personagem.h"

using namespace std;
using namespace Entidades::Personagens;

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Personagens {

Personagem::Personagem(pair<int, int> p, pair<int, int> d)
    : Entidade(p, d), noChao(false), pontosVida(100) {}

Personagem::~Personagem() {}
void Personagem::salvar() {}
}  // namespace Entidades::Personagens

const sf::RectangleShape Entidades::Personagens::Personagem::getCorpo() {
  return sf::RectangleShape();
}
