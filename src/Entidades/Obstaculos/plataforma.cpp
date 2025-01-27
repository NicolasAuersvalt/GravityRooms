#include "Entidades/Obstaculos/plataforma.h"

#include <SFML/Graphics.hpp>
namespace Entidades::Obstaculos {

Plataforma::Plataforma(sf::Vector2f pos, const sf::Vector2f tam)
    : Obstaculo(pos, tam) {
  setSprite("assets/plataformaG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(500.0f, 150.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
  // Implementation
  // mover(); NICOLAS REMOVEU PARA COMPILAR
  desenhar();
}

void Plataforma::mover(const Vector2f& deslocamento) {
  // Implementation
}
void Plataforma::salvar() {
  // Implementation for saving state
}

// void Plataforma::mover()
// {
//     position.first += velocity.first;
//     position.second += velocity.second;
// }

// void Plataforma::desenhar(Gerenciador_Grafico pGG)
// {
// }
// void Plataforma::atualizar()
// {
//     // Add update implementation
// }

// void Plataforma::colisao(Entidade *outra)
// {
//     // Add collision implementation
// }
}  // namespace Entidades::Obstaculos