#include "Entidades/Personagens/personagem.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Personagem::Personagem(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID)
    : Entidade(pos, tam, ID), noChao(false), vivo(true), pontosVida(10) {}

Personagem::~Personagem() {}
const RectangleShape &Personagem::getCorpo() const { return corpo; }

int Personagem::getVida() { return pontosVida; }

void Personagem::setVida(int life) {
  pontosVida = life;
  vivo = true;
}

void Personagem::recebeDano(int dano) {
  pontosVida -= dano;

  if (!verificarVivo()) {
    morrer();
  }
}

bool Personagem::verificarVivo() {
   return (pontosVida > 0); 
  }

void Personagem::morrer() {
   vivo = false; 
  }

void Personagem::setPisando(bool pisa) {
   noChao = pisa; 
  }

bool Personagem::getPisando() {
   return noChao; 
  }

void Personagem::atualizarPosicao() {
  verificarLimitesTela();

  // Utiliza o conceito de MRU
  dt = relogio.getElapsedTime().asSeconds();
  float ds = velFinal.x * dt;
  if (paraEsquerda) {
    ds *= -1;
  }
  corpo.move(ds, 0.0f);
}

void Personagem::parar() { podeAndar = false; }
void Personagem::andar(const bool paraEsquerda) {
  podeAndar = true;
  this->paraEsquerda = paraEsquerda;
}

void Personagem::setVelFinal(const Vector2f velFinal) {
  this->velFinal = velFinal;
}
const Vector2f Personagem::getVelFinal() const { return velFinal; }

void Personagem::cair() {
  tempoSemColisao += 0.016f; // Incrementa o tempo sem colisão (60 FPS)
  if (tempoSemColisao >= TEMPO_MAX_SEM_COLISAO) {
    noChao = false;
  }
}

void Personagem::verificarLimitesTela() {
  Vector2f pos = getSprite().getPosition();
  Vector2f tamanho = getTamanho();
  // Limites horizontais (usar dimensões reais da janela)
  const float LARGURA_TELA = 1280.0f;
  const float ALTURA_TELA = 920.0f;

  // Limite esquerdo
  if (pos.x < 0.0f) {
    pos.x = 0.0f;
    velFinal.x = 0.0f;
  }
  // Limite direito
  if (pos.x + tamanho.x > LARGURA_TELA) {
    pos.x = LARGURA_TELA - tamanho.x;
    velFinal.x = 0.0f;
  }

  // Limite superior
  if (pos.y < 0.0f) {
    pos.y = 0.0f;
    velFinal.y = 0.0f;
  }
  // Limite inferior
  if (pos.y + tamanho.y > ALTURA_TELA) {
    pos.y = ALTURA_TELA - tamanho.y;
    velFinal.y = 0.0f;
    noChao = true;
  }

  // Atualiza as posições do sprite e da hitbox
  getSprite().setPosition(pos);
  setPosicao(pos.x, pos.y);
}

} // namespace Entidades::Personagens
