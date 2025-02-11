#include "Entidades/Personagens/androide.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens {

Androide::Androide(const Vector2f pos, Tripulante *tripulante,
                   const IDs::IDs ID)
    : Inimigo(pos, Vector2f(100.0f, 100.0f), tripulante, ID) {
  this->dano = 2;
  this->pontosVida = 10;
  nivel_maldade = 2;
  setSprite("assets/androide.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
}
Androide::Androide(Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Inimigo(pos, Vector2f(100.0f, 100.0f), nullptr, ID) {
  this->dano = 2;
  this->pontosVida = 10;
  nivel_maldade = 2;
  setSprite("assets/androide.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
}
Androide::~Androide() {}
void Androide::executar() {
  if (vivo)
    mover();
}

void Androide::danificar(Tripulante *p) {}

void Androide::mover() {
  if (vivo) {
    Inimigo::mover();
  }
}

int Androide::getDano() { 
  return dano; 
}

void Androide::salvar(json &arquivo) {
  arquivo["id"] = static_cast<int>(getID());
  arquivo["vida"] = getVida();
  arquivo["posicao"]["x"] = getPosicao().x;
  arquivo["posicao"]["y"] = getPosicao().y;
  arquivo["tipo"] = "androide";
}

void Androide::salvarDataBuffer(nlohmann::ordered_json &json) {}

REGISTRAR_CLASSE(Androide, "androide")
} // namespace Entidades::Personagens
