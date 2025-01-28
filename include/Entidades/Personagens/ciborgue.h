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
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  int tamanho;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Ciborgue(const sf::Vector2f pos, Tripulante* tripulante, const IDs::IDs ID);
  ~Ciborgue();

  using Ente::setSprite;
  void executar() override;
  void danificar(Tripulante* p) override;
  void mover() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json& json) override;

  // void colidir(Entidade* outro, string direction = "") override;

  // ===/===/===/===/ Outros  ===/===/===/===/
};

}  // namespace Entidades::Personagens

#endif
