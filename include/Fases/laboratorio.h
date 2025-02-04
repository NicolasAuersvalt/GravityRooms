#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "Fases/fase.h"

using namespace std;
using namespace sf;

namespace Fases {

class Laboratorio : public Fase {
 private:
  Sprite backgroundSprite;
  Texture bgTexture;

 protected:
 public:
  const int maxChefoes = 1;

  Laboratorio(const IDs::IDs ID);
  ~Laboratorio();

  void criarProjeteis();

  void criarFundo() override;
  void desenhar() override;
  void criarMapa() override;
};
}  // namespace Fases

#endif
