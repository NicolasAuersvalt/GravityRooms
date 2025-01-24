#include "Entidades/Personagens/Inimigo.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

// Inimigo::Inimigo() : Personagem(make_pair(-1, -1), make_pair(-1, -1)) {}
Inimigo::Inimigo(cosnt sf::Vector2f pos, const sf::Vector2f tam,
                 Jogador::Jogador* pJog) {}
Inimigo::~Inimigo() {}

void Inimigo::executar() {}
void Inimigo::mover() {
  sf::Vector2f posJogador = pJog->getCorpo().getPosition();
}
void Inimigo::salvarDataBuffer() {}
// Pode sobrescrever se quiser (com algum multiplicador)

void Inimigo::perseguirJogador(sf::Vector2f posJogador,
                               const sf::Vector2f posInimigo) {}
}  // namespace Entidades::Personagens
