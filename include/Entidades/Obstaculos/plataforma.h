#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#define TAMANHO_PLATAFORMA_X 350.0f
#define TAMANHO_PLATAFORMA_Y 50.0f

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos {

class Plataforma : public Obstaculo {
 private:
  int altura;

 protected:
 public:
  using Ente::setSprite;
  Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
  ~Plataforma();

  void executar() override;
  void mover() override;

  std::string getTipo() const override { return "Plataforma"; }
  void carregar(std::ifstream& arquivo) {}
  // void desenhar(Gerenciador_Grafico pGG) override;
  // void atualizar() override;
  // void colisao(Entidade* outra) override;
  void colisao(Entidade* outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  int getDano();
};
}  // namespace Entidades::Obstaculos
#endif
