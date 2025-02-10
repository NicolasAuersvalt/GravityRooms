#include "Entidades/Obstaculos/obstaculo.h"

#include <iostream>

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"

using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Entidade(pos, tam, ID) {}

Obstaculo::~Obstaculo() {}

bool Obstaculo::getColidindo() { return colidindo; }

void Obstaculo::setColidindo(bool colide) { colidindo = colide; }

void Obstaculo::colisaoObstaculo(
    Vector2f ds, Entidades::Personagens::Personagem *pPersonagem) {
  // Obtém a posição e o tamanho do personagem envolvido na colisão
  Vector2f posOutro = pPersonagem->getPosicao();
  Vector2f tamOutro = pPersonagem->getTamanho();
  // Obtém a velocidade final do personagem
  Vector2f velFinal = pPersonagem->getVelFinal();

  // Verifica se houve colisão (ds.x e ds.y são negativos em caso de colisão)
  if (ds.x < 0.0f && ds.y < 0.0f) { // Houve colisão
    // Decide se a colisão foi mais horizontal (ds.x > ds.y) ou vertical (ds.y >
    // ds.x)
    if (ds.x > ds.y) {
      // Colisão horizontal
      if (posOutro.x < pos.x) { // Colisão à esquerda do obstáculo
        posOutro.x +=
            ds.x; // Ajusta a posição do personagem para fora do obstáculo
      } else {    // Colisão à direita do obstáculo
        posOutro.x -=
            ds.x; // Ajusta a posição do personagem para fora do obstáculo
      }
      velFinal.x =
          0.0f; // Zera a velocidade horizontal para evitar movimento contínuo
    } else {
      // Colisão vertical
      if (posOutro.y < pos.y) { // Colisão acima do obstáculo
        posOutro.y +=
            ds.y; // Ajusta a posição do personagem para fora do obstáculo
        // Se o personagem for um Tripulante, permite que ele pule novamente
        if (pPersonagem->getID() == IDs::IDs::tripulante) {
          using namespace Entidades::Personagens;
          Tripulante *pTripulante = static_cast<Tripulante *>(pPersonagem);
          pTripulante->podePular(); // Habilita o pulo do Tripulante
        }
      } else { // Colisão abaixo do obstáculo
        posOutro.y -=
            ds.y; // Ajusta a posição do personagem para fora do obstáculo
      }
      velFinal.y =
          0.0f; // Zera a velocidade vertical para evitar movimento contínuo
    }
  }

  // Atualiza a posição e a velocidade final do personagem após a colisão
  pPersonagem->setPosicao(posOutro.x, posOutro.y);
  pPersonagem->setVelFinal(velFinal);
}

} // namespace Entidades::Obstaculos
