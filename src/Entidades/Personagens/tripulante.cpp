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

void Tripulante::mover(const Vector2f& deslocamento) {
  // Movimentação (sem física, apenas mover pela tela)
  getSprite().move(deslocamento);  // Move para a esquerda
  
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