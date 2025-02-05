#ifndef ESPINHO_H
#define ESPINHO_H

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/entidade.h"

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
  // using Ente::setSprite;
  Espinho(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
  ~Espinho();
  void executar();
  void mover();
  // void salvar() override;
  //  ===/===/===/===/ Outros  ===/===/===/===/
  void colisao(Entidade* outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  int getDano();

  REGISTRAR_CLASSE(Espinho, "espinho",
                   sf::Vector2f(data["posicao"]["x"], data["posicao"]["y"]),
                   sf::Vector2f(10, 10), static_cast<IDs::IDs>(data["id"]));

  void carregar(json& arquivo) {}
  std::string getTipo() const override { return "Espinho"; }
};

}  // namespace Entidades::Obstaculos

#endif
