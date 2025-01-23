#ifndef ANDROIDE_H
#define ANDROIDE_H

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens {

class Androide : public Inimigo {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  float raio;

  // ===/===/===/===/ Outros  ===/===/===/===/
  const float MOVE_SPEED = 5.0f;

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  using Ente::setSprite;
  Androide();
  ~Androide();
  void executar() override;
  void danificar(Jogador* p);
  void mover();

  // ===/===/===/===/ Outros  ===/===/===/===/
  void colidir(Entidade* e) override;
  void salvar() override;
  void atualizar();
  void atirar();
  void salvarDataBuffer() override;
};

}  // namespace Entidades::Personagens

#endif