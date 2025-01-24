#include "Entidades/Personagens/inimigo.h"

#include <iostream>

using namespace std;
using namespace sf;

using Entidades::Personagens::Inimigo;

namespace Entidades::Personagens {


Inimigo::Inimigo(const Vector2f pos, const Vector2f tam,
                 Tripulante* tripulante)
    : Personagem(pos, tam), tripulante(tripulante), relogio() {

  inicializar();
  
  // Inicializa a semente do gerador de numeros aleatorios
  srand(time(NULL));
  // Gera uma direcao aleatoria inicial (0-3) para o movimento
  moverAleatorio = rand() % 4;
}
Inimigo::~Inimigo() {


}

void Inimigo::inicializar() {


}

void Inimigo::executar() {


}

void Inimigo::mover() {
  cout << "Inimigo Movendo" << endl;
  // Obtem as posicoes do Tripulante e do inimigo
  Vector2f posJogador = tripulante->getCorpo().getPosition();
  Vector2f posInimigo = corpo.getPosition();

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
void Inimigo::salvarDataBuffer(nlohmann::ordered_json& json) {
    cout << "BLZ" << endl;
}
// Pode sobrescrever se quiser (com algum multiplicador)

void Inimigo::perseguirTripulante(Vector2f posJogador,
                               const Vector2f posInimigo) {
  cout << "Inimigo Perseguinto Tripulante" << endl;
  // Se o Tripulante estiver a direita do inimigo, move para direita
  if (posJogador.x - posInimigo.x > 0.0f) {
    corpo.move(vel.x, 0.0f);
  }
  // Se o Tripulante estiver a esquerda do inimigo, move para esquerda
  else {
    corpo.move(-vel.x, 0.0f);
  }
  // Se o Tripulante estiver abaixo do inimigo, move para baixo
  if (posJogador.y - posInimigo.y > 0.0f) {
    corpo.move(0.0f, vel.y);
  }
  // Se o Tripulante estiver acima do inimigo, move para cima
  else {
    corpo.move(0.0f, -vel.y);
  }
}

void Inimigo::movimentarAleatorio() {
  cout << "Inimigo Movimentando Aleatóriamente" << endl;
  // Move para cima quando moverAleatorio = 0
  if (moverAleatorio == 0) {
    corpo.move(0.0f, -vel.y);
  }
  // Move para baixo quando moverAleatorio = 1
  else if (moverAleatorio == 1) {
    corpo.move(0.0f, vel.y);
  }
  // Move para esquerda quando moverAleatorio = 2
  else if (moverAleatorio == 2) {
    corpo.move(-vel.x, 0.0f);
  }
  // Move para direita quando moverAleatorio = 3
  else {
    corpo.move(vel.x, 0.0f);
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
