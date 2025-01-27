#ifndef NAVE_H
#define NAVE_H

#include "Fases/fase.h"

class Fase;

namespace Fases {

class Nave : public Fase {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  const int maxInimMedios = 2;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Nave();
  ~Nave();

  void criarInimMedios();
  void criarObstMedios();

  void criarFundo() override;
  void criarMapa() override;

  // ===/===/===/===/ Outros  ===/===/===/===/
};
}  // namespace Fases

#endif