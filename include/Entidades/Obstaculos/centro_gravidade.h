#ifndef CENTRO_GRAVIDADE_H
#define CENTRO_GRAVIDADE_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos {

class Centro_Gravidade : public Obstaculo {
 private:
  float forca;

 protected:
 public:
  using Ente::setSprite;
  Centro_Gravidade(const sf::Vector2f pos, const sf::Vector2f tam,
                   const IDs::IDs ID);
  ~Centro_Gravidade();
  void executar() override;
  void mover() override;

  void carregar(json &arquivo) override {};
  std::string getTipo() const override { return "Centro_Gravidade"; }
  void colisao(Entidade *outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  int getDano();
  REGISTRAR_CLASSE(Centro_Gravidade, "centro_gravidade",
                   sf::Vector2f(data["posicao"]["x"], data["posicao"]["y"]),
                   sf::Vector2f(10, 10), static_cast<IDs::IDs>(data["id"]));
};

}  // namespace Entidades::Obstaculos

#endif
