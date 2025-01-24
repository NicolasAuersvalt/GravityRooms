#include "Entidades/Personagens/inimigo.h"

#include <iostream>

#include "inimigo.h"

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

// Inimigo::Inimigo() : Personagem(make_pair(-1, -1), make_pair(-1, -1)) {}
Inimigo::Inimigo(cosnt sf::Vector2f pos, const sf::Vector2f tam,
                 Jogador::Jogador* pJog)
    : personagem(pos, tam), relogio(), jogador(pJog) {
  inicializa();
  // Inicializa a semente do gerador de números aleatórios
  srand(time(NULL));
  // Gera uma direção aleatória inicial (0-3) para o movimento
  moverAleatorio = rand() % 4;
}
Inimigo::~Inimigo() {}

void Inimigo::executar() {}

void Inimigo::mover() {
  // Obtém as posições do jogador e do inimigo
  sf::Vector2f posJogador = pJog->getCorpo().getPosition();
  sf::Vector2f posInimigo = corpo.getPosition();

  // Verifica se o jogador está dentro do raio de perseguição
  if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X &&
      fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
    // Se estiver dentro do raio, persegue o jogador
    perseguirJogador(posJogador, posInimigo);
  } else {
    // Se estiver fora do raio, move-se aleatoriamente
    movimentarAleatorio();
  }
}
void Inimigo::salvarDataBuffer() {}
// Pode sobrescrever se quiser (com algum multiplicador)

// Função responsável por fazer o inimigo perseguir o jogador
void Inimigo::perseguirJogador(sf::Vector2f posJogador,
                               const sf::Vector2f posInimigo) {
  // Se o jogador estiver à direita do inimigo, move para direita
  if (posJogador.x - posInimigo.x > 0.0f) {
    corpo.move(vel.x, 0.0f);
  }
  // Se o jogador estiver à esquerda do inimigo, move para esquerda
  else {
    corpo.move(-vel.x, 0.0f);
  }
  // Se o jogador estiver abaixo do inimigo, move para baixo
  if (posJogador.y - posInimigo.y > 0.0f) {
    corpo.move(0.0f, vel.y);
  }
  // Se o jogador estiver acima do inimigo, move para cima
  else {
    corpo.move(0.0f, -vel.y);
  }

  void Inimigo::movimentarAleatorio() {
    // Move para cima
    if (moverAleatorio == 0) {
      corpo.move(0.0f, -vel.y);
    }
    // Move para baixo
    else if (moverAleatorio == 1) {
      corpo.move(0.0f, vel.y);
    }
    // Move para esquerda
    else if (moverAleatorio == 2) {
      corpo.move(-vel.x, 0.0f);
    }
    // Move para direita
    else {
      corpo.move(vel.x, 0.0f);
    }
  }
}  // namespace Entidades::Personagens
