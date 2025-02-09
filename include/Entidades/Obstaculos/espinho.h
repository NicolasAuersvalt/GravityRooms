#ifndef ESPINHO_H
#define ESPINHO_H

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/entidade.h"

using namespace std;
using namespace sf;

namespace Entidades::Obstaculos {
class Espinho : public Obstaculo {
private:
  float largura;

protected:
public:
  Espinho(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Espinho();
  void executar();
  void mover();
  void colisao(Entidade *outraEntidade,
               Vector2f ds = Vector2f(0.0f, 0.0f));
  int getDano();

  void carregar(json &arquivo) {}
  std::string getTipo() const override { return "espinho"; }
  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "espinho";
  }
};

} // namespace Entidades::Obstaculos

#endif
