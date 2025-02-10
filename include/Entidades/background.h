#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

#include "Entidades/entidade.h"
#include "Fases/fase.h"
#include "IDs/IDs.h"
#include "json.hpp"

using namespace sf;
using namespace std;

namespace Fases {
class Fase;
}

// =====/=====/=====/=====/=====/=====/
// Requisitos Conceituais 2.1
// Requisitos Conceituais 3.1
// =====/=====/=====/=====/=====/=====/

namespace Entidades {

class Background : public Entidade {

private:
  Fases::Fase *fase;

public:
  Background(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);

  ~Background();

  void mover() override;
  void colisao(Entidade *outraEntidade, Vector2f ds) override;
  void atualizarPosicao();

  void lerSprite();
  void setFase(Fases::Fase *fase);

  std::string getTipo() const override;
  void salvar(json &arquivo) override;
  void carregar(json &arquivo) override;
};

} // namespace Entidades

#endif
