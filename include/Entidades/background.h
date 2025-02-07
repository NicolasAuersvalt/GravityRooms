#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

#include "Entidades/entidade.h"
#include "IDs/IDs.h"
#include "json.hpp"
using namespace sf;
using namespace std;

namespace Entidades {

class Background : public Entidade {
protected:
public:
<<<<<<< HEAD
  Background(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
      : Entidade(Vector2f(0.0f, 0.0f), Vector2f(0.0f, 0.0f), ID) {
    if ((ID == IDs::IDs::fase_nave)) {
      setSprite("assets/nave.png", 50.0f, 50.0f);
    } else if (ID == IDs::IDs::fase_laboratorio) {
      setSprite("assets/lab.png", 50.0f, 50.0f);
    }
=======
  Background(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
>>>>>>> psave

  ~Background();

  void mover() override;
  void colisao(Entidade *outraEntidade, sf::Vector2f ds) override;
  void atualizarPosicao();

  std::string getTipo() const override;
  void salvar(json &arquivo) override;
  void carregar(json &arquivo) override;
};

} // namespace Entidades

#endif
