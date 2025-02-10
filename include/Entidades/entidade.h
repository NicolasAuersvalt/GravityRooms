#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>

#include "ente.h"
#include "json.hpp"

using namespace sf;
using namespace std;
using namespace IDs;

class Gerenciador_Grafico;

// =====/=====/=====/=====/=====/=====/

// Requisitos Conceituais 1.1
// Requisitos Conceituais 1.2
// Requisitos Conceituais 2.3
// Requisitos Conceituais 5.2

// =====/=====/=====/=====/=====/=====/

namespace Entidades {

class Entidade : public Ente {
private:
protected:
  Vector2f pos; // Posição (x,y)
  Vector2f tam; // Dimensão (x,y)

  ostringstream buffer;

  RectangleShape corpo;

public:
  Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  virtual ~Entidade();

  virtual void mover() = 0;
  virtual void salvar(json &arquivo) = 0;
  void setPosicao(int x, int y);
  void setTamanho(const Vector2f tam);

  const Vector2f getPosicao() const;
  const Vector2f getTamanho() const;
  virtual void atualizarPosicao() = 0;
  virtual void colisao(Entidade *outraEntidade,
                       Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
};

} // namespace Entidades

#endif
