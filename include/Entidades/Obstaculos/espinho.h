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

  Espinho(const sf::Vector2f pos, const sf::Vector2f tam);
  ~Espinho();
  void executar() override;
  void mover() override;
  void salvar() override;
  // ===/===/===/===/ Outros  ===/===/===/===/
};

}  // namespace Entidades::Obstaculos

#endif