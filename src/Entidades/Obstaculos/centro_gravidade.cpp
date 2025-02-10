#include "Entidades/Obstaculos/centro_gravidade.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Centro_Gravidade::Centro_Gravidade(const Vector2f pos, const Vector2f tam,
                                   const IDs::IDs ID)
    : Obstaculo(pos, tam, ID) {
  this->dano = 10;

  setSprite("assets/regiao_gravitacional.png", pos.x, pos.y);
  setTamanho(Vector2f(90.0f, 90.0f));

  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

Centro_Gravidade::~Centro_Gravidade() 
{

}

string Centro_Gravidade::getTipo() const 
  {
     return "Centro_Gravidade"; 
  
  }

void Centro_Gravidade::executar() 
{
  mover();
  desenhar();
}

void Centro_Gravidade::mover() 
{

}
void Centro_Gravidade::colisao(Entidade *outraEntidade, Vector2f ds) 
{}

int Centro_Gravidade::getDano() { 
  return dano; 
}

void Centro_Gravidade::salvar(json &arquivo){
  arquivo["id"] = static_cast<int>(getID());
  arquivo["posicao"]["x"] = getPosicao().x;
  arquivo["posicao"]["y"] = getPosicao().y;
  arquivo["tipo"] = "centro_gravidade";
}

REGISTRAR_CLASSE(Centro_Gravidade, "centro_gravidade")
} // namespace Entidades::Obstaculos
