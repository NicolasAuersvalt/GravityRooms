#include "Entidades/Personagens/tripulante.h"

#include <SFML/Graphics.hpp>

#include "json.hpp"

using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Tripulante::Tripulante(const Vector2f pos, const Vector2f tam)
    : Personagem(pos, tam), pontos(0) {
  setSprite("assets/tripulanteG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(150.0f, 150.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
  std::cout << "Position: " << pos.x << " " << pos.y << std::endl;
}

Tripulante::~Tripulante() {}

// Implementação da função executar()
/*
void Tripulante::executar() {
    // Implementação do comportamento da função
}
*/

void Tripulante::mover() {
  // Movimentação (sem física, apenas mover pela tela)
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    getSprite().move(-5.f, 0.f);  // Move para a esquerda
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    getSprite().move(5.f, 0.f);  // Move para a direita
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    getSprite().move(0.f, -5.f);  // Move para cima
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    getSprite().move(0.f, 5.f);  // Move para baixo
  }
}

void Tripulante::salvarDataBuffer(nlohmann::ordered_json& json) {
  Vector2f pos = getPosicao();  // Desempacota a posição

  json = {

      {"posicao", {{"x", pos.x}, {"y", pos.y}}},

      {"vida", getVida()},

      {"pontos", getPontos()}

  };
}

void Tripulante::carregarDataBuffer(const nlohmann::ordered_json& json) {
  if (json.contains("posicao")) {
    int posicaoX = json["posicao"]["x"].get<int>();
    int posicaoY = json["posicao"]["y"].get<int>();

    setPosicao(posicaoX, posicaoY);
  }

  if (json.contains("vida")) {
    setVida(json["vida"].get<int>());
  }
  if (json.contains("pontos")) {
    setPontos(json["pontos"].get<int>());
  }
}

int Tripulante::getPontos() { return pontos; }

void Tripulante::setPontos(int ponto) { pontos = ponto; }
}  // namespace Entidades::Personagens