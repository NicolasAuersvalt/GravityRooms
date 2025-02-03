#ifndef ESPINHO_H
#define ESPINHO_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos {

class Espinho : public Obstaculo {
private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  float largura;

  // ===/===/===/===/ Outros  ===/===/===/===/

protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  using Ente::setSprite;
  Espinho(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
  ~Espinho();
  void executar() override;
  void mover() override;
  void salvar() override;
  // ===/===/===/===/ Outros  ===/===/===/===/
  void colisao(Entidade *outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  int getDano();
};

} // namespace Entidades::Obstaculos

#endif
