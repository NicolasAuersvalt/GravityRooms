#ifndef NAVE_H
#define NAVE_H

#include "Fases/fase.h"

using namespace std;
using namespace sf;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  3
// Requisitos Funcionais  5
// Requisitos Funcionais  7
// =====/=====/=====/=====/=====/=====/

namespace Fases {

class Nave : public Fase {
private:
  const int maxInimMedios = 2;

protected:
public:
  Nave(const IDs::IDs ID);
  ~Nave();

  void criarInimMedios();
  void criarObstMedios();

  void criarFundo() override;
  void criarMapa() override;

  void desenhar() override;
};
} // namespace Fases

#endif
