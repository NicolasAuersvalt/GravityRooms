#ifndef CLONE_H
#define CLONE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

class Clone : public Inimigo {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  //   float raio;
  Projetil* projetil;
  Clock timerTiro;  // Timer to control shooting frequency

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Clone(const sf::Vector2f pos, Tripulante* tripulante, const IDs::IDs ID);
  ~Clone();
  using Ente::setSprite;

  void danificar(Tripulante* p) override;

  virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json& json) override;
  void mover() override;
  void setProjetil(Projetil* proj) { projetil = proj; }
  void atirar();  // New method to handle shooting

  // ===/===/===/===/ Outros  ===/===/===/===/
  //   void colidir(Entidade* outro, string direction = "") override;
};

}  // namespace Entidades::Personagens

#endif
