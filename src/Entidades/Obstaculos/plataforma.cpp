#include "Entidades/Obstaculos/plataforma.h"

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/personagem.h"

namespace Entidades::Obstaculos {

Plataforma::Plataforma(Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Obstaculo(pos, tam, ID) {
  this->dano = 0;

  setSprite("assets/plataforma.png", pos.x, pos.y);
  setTamanho(Vector2f(266.0f, 80.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
  mover();
  desenhar();
}

void Plataforma::mover() {}

void Plataforma::colisao(Entidade *outraEntidade, Vector2f ds) {
  if (outraEntidade->getID() == IDs::IDs::clone ||
      outraEntidade->getID() == IDs::IDs::ciborgue ||
      outraEntidade->getID() == IDs::IDs::androide ||
      outraEntidade->getID() == IDs::IDs::tripulante) {
    colisaoObstaculo(
        ds, static_cast<Entidades::Personagens::Personagem *>(outraEntidade));
  }
}
int Plataforma::getDano() {
   return dano; 
  }

void Plataforma::salvar(json &arquivo) {
  arquivo["id"] = static_cast<int>(getID());
  arquivo["posicao"]["x"] = getPosicao().x;
  arquivo["posicao"]["y"] = getPosicao().y;
  arquivo["tipo"] = "plataforma";
}

REGISTRAR_CLASSE(Plataforma, "plataforma")

} // namespace Entidades::Obstaculos
