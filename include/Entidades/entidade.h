#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <utility>

#include "ente.h"
#include "json.hpp"

using namespace sf;
using namespace std;
using namespace IDs;

class Gerenciador_Grafico;

namespace Entidades {

class Entidade : public Ente {
 private:
 protected:
  Vector2f pos;  // Posição (x,y)
  Vector2f tam;  // Dimensão (x,y)

  ostringstream buffer;

  RectangleShape corpo;

 public:
  Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  virtual ~Entidade();

  virtual void salvar() = 0;
  virtual void mover() = 0;

  void setPosicao(int x, int y);
  void setTamanho(const Vector2f tam);

  const Vector2f getPosicao() const;
  const Vector2f getTamanho() const;
  virtual void atualizarPosicao() = 0;
  virtual void colisao(Entidade *outraEntidade,
                       sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
};

}  // namespace Entidades

#endif
