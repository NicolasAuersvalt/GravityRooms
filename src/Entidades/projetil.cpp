#include "Entidades/Projetil.h"

#include <iostream>

#include "Entidades/Personagens/Personagem.h"
#include "Entidades/projetil.h"
#define HEIGHT 720
#define WIDTH 1280

class Personagem;  // Forward declaration if needed

using namespace std;
using namespace Entidades;

// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil() : Entidade(make_pair(0, 0), make_pair(0, 0)) {}
Projetil::~Projetil() {}
void Projetil::executar() { atualizar(); }

void Projetil::mover() {
  if (!colidiu) {
    getSprite().move(direcao.x * vel_bala, direcao.y * vel_bala);
  }
}

void Projetil::salvar() {}

void Projetil::atualizar() {
  if (!colidiu) {
    // Mover o projetil
    getSprite().move(direcao.x * vel_bala, direcao.y * vel_bala);

    // Checa os limites da tela
    if (getSprite().getPosition().x < 0 ||
        getSprite().getPosition().x > WIDTH ||
        getSprite().getPosition().y < 0 ||
        getSprite().getPosition().y > HEIGHT) {
      colidiu = true;
    }
  }
}

// void Projetil::atirar()
// {
//     // // Set initial position
//     // getSprite().setPosition(pos);
//     // // Set direction vector
//     // direction = sf::Vector2f(1.0f, 0.0f); // Shooting right by default
//     // colidiu = false;
//     setPosition(posicao);
// }

void Projetil::atirar(const sf::Vector2f &posicao) {
  // cout<<"teste"<<endl;
  getSprite().setPosition(posicao);
  direcao = sf::Vector2f(1.0f, 0.0f);  // Default right direction
  colidiu = false;
}

void Projetil::setDirecao(const sf::Vector2f &dir) { direcao = dir; }

void Entidades::Projetil::setAtirador(Entidade *a) {}

void Entidades::Projetil::colisao(Entidade *e) {}

bool Entidades::Projetil::getColidir(Entidade *e) {
  if (e->getPosition().first > 1280 || e->getPosition().first < 0 ||
      e->getPosition().second > 920 || e->getPosition().second < 0)
    colidiu = true;
  return colidiu;
}

void Entidades::Projetil::danificar(Personagem *p) {}

}  // namespace Entidades
