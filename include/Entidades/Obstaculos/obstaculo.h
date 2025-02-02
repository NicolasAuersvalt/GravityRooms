#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Entidades/Personagens/personagem.h"
#include "Entidades/entidade.h"

using namespace sf;
using Entidades::Personagens::Personagem;

namespace Entidades::Obstaculos {

class Obstaculo : public Entidade {
 protected:
  bool danoso;
  bool colidindo;
  int dano;

 public:
  Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Obstaculo();
  void salvarDataBuffer() {};
  virtual void executar() = 0;
  virtual int getDano() = 0;
  void atualizarPosicao() {};
  bool getColidindo();
  void setColidindo(bool colide);
  virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds) = 0;
  virtual void colisaoObstaculo(Vector2f ds, Personagem* pPersonagem);
};

}  // namespace Entidades::Obstaculos

#endif
