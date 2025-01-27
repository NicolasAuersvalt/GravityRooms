#include "Entidades/Obstaculos/centro_gravidade.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

Centro_Gravidade::Centro_Gravidade(const sf::Vector2f pos,
                                   const sf::Vector2f tam)
    : Obstaculo(pos, tam) {
  setSprite("assets/gravidadeG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(45.0f, 150.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
  std::cout << "Position: " << pos.x << " " << pos.y << std::endl;
}

Centro_Gravidade::~Centro_Gravidade() {}
void Centro_Gravidade::executar() {
  // mover(); NICOLAS COMENTOU PARA PODER COMPILAR
  desenhar();
}

void Centro_Gravidade::mover(const Vector2f& deslocamento) {}
void Centro_Gravidade::salvar() {}
}  // namespace Entidades::Obstaculos