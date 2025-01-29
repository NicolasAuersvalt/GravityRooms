#include "Entidades/Obstaculos/plataforma.h"

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/personagem.h"

namespace Entidades::Obstaculos {

Plataforma::Plataforma(sf::Vector2f pos, const sf::Vector2f tam,
                       const IDs::IDs ID)
    : Obstaculo(pos, tam, ID) {
  this->dano = 0;
  // setSprite("assets/plataformaP.png", pos.x, pos.y);
  setSprite("assets/plataformaG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(500.0f, 150.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
  // Implementation
  mover();
  desenhar();
}

void Plataforma::mover() {
  // Implementation
}
void Plataforma::salvar() {
  // Implementation for saving state
}

void Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
  if (outraEntidade->getID() == IDs::IDs::clone ||
      outraEntidade->getID() == IDs::IDs::ciborgue ||
      outraEntidade->getID() == IDs::IDs::androide ||
      outraEntidade->getID() == IDs::IDs::tripulante) {
    colisaoObstaculo(
        ds, static_cast<Entidades::Personagens::Personagem*>(outraEntidade));
    // } else if (outraEntidade->getID() == IDs::IDs::projetil_inimigo) {
    //   Entidades::Projetil* projetil =
    //       dynamic_cast<Item::Projetil*>(outraEntidade);
    //   projetil->setColidiu(true);
    //   projetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
  }
}
int Plataforma::getDano() { return dano; }

}  // namespace Entidades::Obstaculos
