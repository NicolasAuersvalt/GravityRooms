#include "Entidades/Personagens/ciborgue.h"
// #include "gerenciador_grafico.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Ciborgue::Ciborgue(const Vector2f pos, Tripulante *tripulante,
                   const IDs::IDs ID)
    : Inimigo(pos, Vector2f(100.0f, 100.0f), tripulante, ID) {
  this->pontosVida = 5;
  this->dano = 1;
  nivel_maldade = 1;
  setSprite("assets/ciborgue.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
}

Ciborgue::Ciborgue(Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Inimigo(pos, Vector2f(100.0f, 100.0f), nullptr, ID) {
  this->pontosVida = 5;
  this->dano = 1;
  nivel_maldade = 1;
  setSprite("assets/ciborgue.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
}

Ciborgue::~Ciborgue() {}
void Ciborgue::executar() {
  if (vivo) {
    mover();
    desenhar();
  }
}

void Ciborgue::danificar(Tripulante *p) {}

void Entidades::Personagens::Ciborgue::mover() {
  if (vivo) {
    Inimigo::mover();
  }
}
void Ciborgue::salvarDataBuffer(nlohmann::ordered_json &json) {}

int Ciborgue::getDano() { 
  return dano;
 }

 void Ciborgue::salvar(json &arquivo) override 
 {

   arquivo["id"] = static_cast<int>(getID());
   arquivo["vida"] = getVida();
   arquivo["posicao"]["x"] = getPosicao().x;
   arquivo["posicao"]["y"] = getPosicao().y;
   arquivo["tipo"] = "ciborgue";

 }


REGISTRAR_CLASSE(Ciborgue, "ciborgue")
} // namespace Entidades::Personagens
