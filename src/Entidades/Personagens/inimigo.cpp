#include "Entidades/Personagens/inimigo.h"

#include <iostream>

using namespace std;
using namespace sf;

using Entidades::Personagens::Inimigo;

namespace Entidades::Personagens {

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, Tripulante* tripulante)
    : Personagem(pos, tam), tripulante(tripulante), relogio() {
  inicializar();

  // Inicializa a semente do gerador de numeros aleatorios
  srand(time(NULL));
  // Gera uma direcao aleatoria inicial (0-3) para o movimento
  moverAleatorio = rand() % 4;
}
Inimigo::~Inimigo() {}

void Inimigo::inicializar() { vel = {2.f, 2.f}; }

void Inimigo::executar() {}

void Inimigo::mover() {
  // Obtem as posicoes do Tripulante e do inimigo

  Vector2f posJogador = tripulante->getSprite().getPosition();
  Vector2f posInimigo = getSprite().getPosition();
  cout << "jogador: " << posJogador.x << " " << posJogador.y << endl;
  cout << "inimigo: " << posInimigo.x << " " << posInimigo.y << endl;
  // Verifica se o Tripulante esta dentro do raio de perseguicao
  if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X &&
      fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
    // Se estiver dentro do raio, persegue o Tripulante
    perseguirTripulante(posJogador, posInimigo);
  } else {
    // Se estiver fora do raio, move-se aleatoriamente
    movimentarAleatorio();
  }
}
void Inimigo::salvarDataBuffer(nlohmann::ordered_json& json) {}
// Pode sobrescrever se quiser (com algum multiplicador)

void Inimigo::perseguirTripulante(Vector2f posJogador,
                                  const Vector2f posInimigo) {
  cout << "perseguir aleatorio" << endl;
  // Se o Tripulante estiver a direita do inimigo, move para direita
  if (posJogador.x - posInimigo.x > 0.0f) {
    getSprite().move(vel.x, 0.0f);
  }
  // Se o Tripulante estiver a esquerda do inimigo, move para esquerda
  else {
    getSprite().move(-vel.x, 0.0f);
  }
  // Se o Tripulante estiver abaixo do inimigo, move para baixo
  if (posJogador.y - posInimigo.y > 0.0f) {
    getSprite().move(0.0f, vel.y);
  }
  // Se o Tripulante estiver acima do inimigo, move para cima
  else {
    getSprite().move(0.0f, -vel.y);
  }
}

void Inimigo::movimentarAleatorio() {
  cout << "movimentar aleatorio" << endl;
  // Move para cima quando moverAleatorio = 0
  if (moverAleatorio == 0) {
    getSprite().move(0.0f, -vel.y);
  }
  // Move para baixo quando moverAleatorio = 1
  else if (moverAleatorio == 1) {
    getSprite().move(0.0f, vel.y);
  }
  // Move para esquerda quando moverAleatorio = 2
  else if (moverAleatorio == 2) {
    getSprite().move(-vel.x, 0.0f);
  }
  // Move para direita quando moverAleatorio = 3
  else {
    getSprite().move(vel.x, 0.0f);
  }

  // Obtem o tempo decorrido desde o ultimo reinicio do relogio
  float dt = relogio.getElapsedTime().asSeconds();
  // A cada 1 segundo, gera uma nova direcao aleatoria
  if (dt >= 1.0f) {
    moverAleatorio = rand() % 4;
    relogio.restart();
  }
}
}  // namespace Entidades::Personagens
