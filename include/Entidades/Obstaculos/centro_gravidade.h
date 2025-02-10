#ifndef CENTRO_GRAVIDADE_H
#define CENTRO_GRAVIDADE_H

#include "Entidades/Obstaculos/obstaculo.h"

using namespace std;
using namespace sf;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  6
// =====/=====/=====/=====/=====/=====/

namespace Entidades::Obstaculos {

class Centro_Gravidade : public Obstaculo {
private:
  float forca;

protected:
public:
  using Ente::setSprite;
  Centro_Gravidade(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Centro_Gravidade();
  
  void executar() override;
  void mover() override;

  void carregar(json &arquivo) override
  {

  };
  string getTipo() const override;

  void colisao(Entidade *outraEntidade, Vector2f ds = Vector2f(0.0f, 0.0f));
  int getDano();

  void salvar(json &arquivo) override;
};

} // namespace Entidades::Obstaculos

#endif
