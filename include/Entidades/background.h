#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

#include "Entidades/background.h"
#include "IDs/IDs.h"
using namespace sf;

namespace Entidades {

class Background : public Entidade {
 protected:
 public:
  Background(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
      : Entidade(pos, tam, ID) {
    if ((ID == IDs::IDs::fase_nave)) {
      setSprite("assets/nave.png", 50.0f, 50.0f);
    } else if (ID == IDs::IDs::fase_laboratorio) {
      setSprite("assets/lab.png", 50.0f, 50.0f);
    }

    setTamanho(sf::Vector2f(1280.0f, 920.0f));
    setPosicao(50.0f, 50.0f);
    sprite.setPosition(0.f, 0.f);
  }

  ~Background() {}

  void mover() override {}
  // void salvar() override {}
  void colisao(Entidade *outraEntidade, sf::Vector2f ds) override {}
  void atualizarPosicao() {};

  void salvar(json &arquivo) override {};
  void carregar(json &arquivo) override {};
  std::string getTipo() const override { return "Background"; }
};

}  // namespace Entidades

#endif
