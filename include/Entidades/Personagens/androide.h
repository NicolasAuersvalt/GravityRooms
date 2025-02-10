#ifndef ANDROIDE_H
#define ANDROIDE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"

using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

// =====/=====/=====/=====/=====/=====/
// Requisitos Conceituais 4.1
// Requisitos Conceituais 5.2
// =====/=====/=====/=====/=====/=====/

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

  virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;

  void danificar(Tripulante *p) override;
  void mover() override;
  int getDano();
  Projetil *getProjetil() {
     return nullptr; 
    };

  void salvar(json &arquivo) override;
};

} // namespace Entidades::Personagens

#endif
