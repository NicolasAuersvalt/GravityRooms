#include "Entidades/Obstaculos/espinhoRetratil.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

EspinhoRetratil::EspinhoRetratil(const sf::Vector2f pos, const sf::Vector2f tam,
                                 const IDs::IDs ID)
    : Obstaculo(pos, tam, ID), ligado(false) {
  this->dano = 2;
  setSprite("assets/espinhoretratil_verde.png", pos.x, pos.y);

  setTamanho(sf::Vector2f(90.0f, 90.0f));
  sprite.setOrigin(45.0f, 45.0f);
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

EspinhoRetratil::~EspinhoRetratil() {}
void EspinhoRetratil::executar() {
  mover();
  desenhar();
}
void EspinhoRetratil::mover() {
  float deltaTime =
      relogio.restart().asSeconds();  // Assumindo 60 FPS (16ms por frame)

  tempoDesdeUltimaAlternancia += deltaTime;
  if (tempoDesdeUltimaAlternancia >= 2.0f) {  // Alterna a cada 5 segundos
    ligado = !ligado;
    tempoDesdeUltimaAlternancia = 0.0f;

    // Altera o sprite dependendo do estado
    if (ligado) {
      setSprite("assets/espinhoretratil_vermelho.png", getPosicao().x,
                getPosicao().y);
    } else {
      setSprite("assets/espinhoretratil_verde.png", getPosicao().x,
                getPosicao().y);
    }
  }
}

void EspinhoRetratil::colisao(Entidade* outraEntidade, sf::Vector2f ds) {}
int EspinhoRetratil::getDano() { return dano; }

bool EspinhoRetratil::estaLigado() const { return ligado; }

REGISTRAR_CLASSE(EspinhoRetratil, "espinhoRetratil")
}  // namespace Entidades::Obstaculos
