#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#define TAMANHO_PLATAFORMA_X 350.0f
#define TAMANHO_PLATAFORMA_Y 50.0f

#include "Entidades/Obstaculos/obstaculo.h"

using namespace std;
using namespace sf;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  6
// =====/=====/=====/=====/=====/=====/

namespace Entidades::Obstaculos {

class Plataforma : public Obstaculo {
private:
  int altura;

protected:
public:
  using Ente::setSprite;
  Plataforma(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Plataforma();

  void executar() override;
  void mover() override;

  string getTipo() const override { return "Plataforma"; }
  void carregar(json &arquivo) {}
  void colisao(Entidade *outraEntidade, Vector2f ds = Vector2f(0.0f, 0.0f));
  int getDano();

  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "plataforma";
  }
};
} // namespace Entidades::Obstaculos
#endif
