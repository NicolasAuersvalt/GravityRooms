#ifndef ANDROIDE_H
#define ANDROIDE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"

using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

class Androide : public Inimigo {
 private:
  bool movingRight;

 protected:
 public:
  Androide(const Vector2f pos, Tripulante *tripulante, const IDs::IDs ID);
  Androide(Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Androide();

  using Ente::setSprite;

  void danificar(Tripulante *p) override;

  virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  void mover() override;
  int getDano();
  Projetil *getProjetil() { return nullptr; };

  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["vida"] = getVida();
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "androide";
  }
};

}  // namespace Entidades::Personagens

#endif
