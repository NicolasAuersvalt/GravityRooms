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
  Androide(const sf::Vector2f pos, Tripulante *tripulante, const IDs::IDs ID);
  ~Androide();

  using Ente::setSprite;

  void danificar(Tripulante *p) override;

  virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  void mover() override;
  int getDano();
};

} // namespace Entidades::Personagens

#endif
