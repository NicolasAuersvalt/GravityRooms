#ifndef CIBORGUE_H
#define CIBORGUE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

class Ciborgue : public Inimigo {
 private:
  int tamanho;

 protected:
 public:
  Ciborgue(const sf::Vector2f pos, Tripulante *tripulante, const IDs::IDs ID);
  ~Ciborgue();

  using Ente::setSprite;
  void executar() override;
  void danificar(Tripulante *p) override;
  void mover() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  int getDano();
};

}  // namespace Entidades::Personagens

#endif
