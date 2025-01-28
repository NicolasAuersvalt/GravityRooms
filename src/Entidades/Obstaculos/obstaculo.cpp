#include "Entidades/Obstaculos/obstaculo.h"

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"

// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Obstaculos {

Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam,
                     const IDs::IDs ID)
    : Entidade(pos, tam, ID) {}

Obstaculo::~Obstaculo() {}
void Obstaculo::salvar() {}

bool Obstaculo::getColidindo() { return colidindo; }

void Obstaculo::setColidindo(bool colide) { colidindo = colide; }

void Obstaculo::colisaoObstaculo(
    Vector2f ds, Entidades::Personagens::Personagem* pPersonagem) {
  sf::Vector2f posOutro = pPersonagem->getPosicao();
  sf::Vector2f tamOutro = pPersonagem->getTamanho();
  sf::Vector2f velFinal = pPersonagem->getVelFinal();
  if (ds.x < 0.0f && ds.y < 0.0f) {  // houve colisao
    if (ds.x > ds.y) {
      if (posOutro.x < pos.x) {  // colisão em x
        posOutro.x += ds.x;
      } else {
        posOutro.x -= ds.x;
      }
      velFinal.x = 0.0f;
    } else {
      if (posOutro.y < pos.y) {  // colisão em y
        posOutro.y += ds.y;
        if (pPersonagem->getID() == IDs::IDs::tripulante) {
          using namespace Entidades::Personagens;
          Tripulante* pTripulante = static_cast<Tripulante*>(pPersonagem);
          pTripulante->podePular();
          // pTripulante->podePular();
          //;
        }
      } else {
        posOutro.y -= ds.y;
      }
      velFinal.y = 0.0f;
    }
  }
  pPersonagem->setPosicao(posOutro.x, posOutro.y);
  pPersonagem->setVelFinal(velFinal);
}

}  // namespace Entidades::Obstaculos
