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
  Nave(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Nave();

  void criarInimMedios();
  void criarObstMedios();

  void criarFundo() override;
  void criarMapa() override;

  void desenhar() override;

  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["posicao"]["x"] = 0.0f;
    arquivo["posicao"]["y"] = 0.0f;
    arquivo["tipo"] = "nave";
  }
};
}  // namespace Fases

#endif
