#include "Entidades/Personagens/Tripulante.h"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Tripulante::Tripulante() : Personagem(make_pair(-1, -1), make_pair(-1, -1)) {}

Tripulante::~Tripulante() {}
void Tripulante::executar() {}
// void Jogador::atualizar()
// {
// }
// void Jogador::setListaEntidades(Listas::Lista_Entidades *lista)
// {
//     listaEntidades = lista;
// }

Projetil* Jogador::atirar() {
  // Projetil *tiro = new Projetil();
  // tiro->setSprite("assets/projetilG.png", 0, 0);

  // // Get position directly from sprite
  // sf::Vector2f pos = getSprite().getPosition();
  // tiro->atirar(pos);

  // if (listaEntidades)
  // {
  //     listaEntidades->incluir(static_cast<Entidade *>(tiro));
  // }
  Projetil* tiro = new Projetil();
  tiro->setSprite("assets/projetilG.png", 0, 0);

  sf::Vector2f pos = getSprite().getPosition();
  tiro->atirar(pos);

  return tiro;
}
void Tripulante::mover()

{
  // Movimentação (sem física, apenas mover pela tela)
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    getSprite().move(-5.f, 0.f);  // Move para a esquerda
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    getSprite().move(5.f, 0.f);  // Move para a direita
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    getSprite().move(0.f, -5.f);  // Move para cima
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    getSprite().move(0.f, 5.f);  // Move para baixo
  }

  // Jogador atira
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    if (listaEntidades) {
      Projetil* tiro = atirar();
      listaEntidades->incluir(static_cast<Entidade*>(tiro));
    }
  }
}
void Jogador::colidir(Entidades::Entidade* e) {}
}  // namespace Entidades::Personagens