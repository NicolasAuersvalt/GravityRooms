
#ifndef BOTAO_H
#define BOTAO_H

#include "ente.h"

using namespace sf;
using namespace std;

// =====/=====/=====/=====/=====/=====/
// Requisitos Conceituais 6.1
// =====/=====/=====/=====/=====/=====/

namespace Menus {

namespace Botoes {

class Botao : public Ente {
private:
  const Vector2f tamMax;
  const Vector2f tamInicial;
  bool aumentando;

protected:
  RectangleShape caixa;
  Texture *textura;
  Vector2f pos;
  Vector2f tam;

  const float tempoTroca;
  float tempo;

public:
  Botao(const Vector2f tam, const Vector2f pos, const IDs::IDs ID,
        const float tempoTroca = 0.0f,
        const Vector2f tamMax = Vector2f(0.0f, 0.0f));
  virtual ~Botao();
  virtual void desenhar();
  virtual void atualizarPosicaoCaixa(const Vector2f pos);
  void setTextura(Texture *textura);
  const Vector2f getPos() const;
  string getTipo() const override { return "Botao"; }
  void carregar(json &arquivo) {}
  void salvar(json &arquivo) override {}
};

} // namespace Botoes

} // namespace Menus

#endif
