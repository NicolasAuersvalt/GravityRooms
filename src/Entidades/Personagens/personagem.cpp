#include "Entidades/Personagens/personagem.h"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Personagens {

Personagem::Personagem(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID)
    : Entidade(pos, tam, ID), noChao(false), vivo(true), pontosVida(10) {}

Personagem::~Personagem() {}
void Personagem::salvar() {}

const RectangleShape& Personagem::getCorpo() const { return RectangleShape(); }

/*
   const RectangleShape& Personagem::getCorpo() {
   return corpo;
   }
   */

int Personagem::getVida() { return pontosVida; }

void Personagem::setVida(int life) {
  pontosVida = life;
  vivo = true;
}

void Personagem::recebeDano(int dano) {
  pontosVida -= dano;

  if (!verificarVivo()) {
    cout << "bli" << endl;
    morrer();
  }
}

bool Personagem::verificarVivo() { return (pontosVida > 0); }

void Personagem::morrer() { vivo = false; }

void Personagem::setPisando(bool pisa) { noChao = pisa; }

bool Personagem::getPisando() { return noChao; }

void Entidades::Personagens::Personagem::atualizarPosicao() {
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

void Personagem::setVelFinal(const sf::Vector2f velFinal) {
  this->velFinal = velFinal;
}
const sf::Vector2f Personagem::getVelFinal() const { return velFinal; }
}  // namespace Entidades::Personagens
