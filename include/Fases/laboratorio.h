#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "Fases/fase.h"

using namespace std;
using namespace sf;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  3
// Requisitos Funcionais  5
// Requisitos Funcionais  7
// =====/=====/=====/=====/=====/=====/

namespace Fases {

class Laboratorio : public Fase {
 private:
  Sprite backgroundSprite;
  Texture bgTexture;

 protected:
 public:
  const int maxChefoes = 1;

  Laboratorio(const IDs::IDs ID);
  Laboratorio(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);

  ~Laboratorio();

  void criarProjeteis();

  void criarFundo() override;
  void desenhar() override;
  void criarMapa() override;

  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["posicao"]["x"] = 0.0f;
    arquivo["posicao"]["y"] = 0.0f;
    arquivo["tipo"] = "laboratorio";
  }
};
}  // namespace Fases

#endif
