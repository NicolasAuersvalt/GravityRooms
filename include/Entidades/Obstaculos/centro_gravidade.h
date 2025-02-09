#ifndef CENTRO_GRAVIDADE_H
#define CENTRO_GRAVIDADE_H

#include "Entidades/Obstaculos/obstaculo.h"

using namespace std;
using namespace sf;

namespace Entidades::Obstaculos {

class Centro_Gravidade : public Obstaculo {
private:
  float forca;

protected:
public:
  using Ente::setSprite;
  Centro_Gravidade(const Vector2f pos, const Vector2f tam,
                   const IDs::IDs ID);
  ~Centro_Gravidade();
  void executar() override;
  void mover() override;

  void carregar(json &arquivo) override {};
  string getTipo() const override { return "Centro_Gravidade"; }
  void colisao(Entidade *outraEntidade,
               Vector2f ds = Vector2f(0.0f, 0.0f));
  int getDano();
  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "centro_gravidade";
  }
};

} // namespace Entidades::Obstaculos

#endif
