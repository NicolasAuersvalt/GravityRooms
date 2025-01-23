#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"

namespace Entidades::Personagens {

class Inimigo : public Personagem {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  int nivel_maldade;
  int dano = 10;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Inimigo();
  ~Inimigo();
  void salvarDataBuffer();
  virtual void danificar(Tripulante* p) = 0;

  virtual void executar() = 0;

  // ===/===/===/===/ Outros  ===/===/===/===/
  virtual void mover() = 0;
  virtual void colidir(Entidade* outro, string direction = "") = 0;

  // Pode reescrever se quiser (com algum multiplicador, por exemplo)
  virtual int getDano() {
    // Por exemplo, retornar o dano base multiplicado pelo nível de maldade
    return dano;
  }
};

}  // namespace Entidades::Personagens

#endif