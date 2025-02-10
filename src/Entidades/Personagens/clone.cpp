#include "Entidades/Personagens/clone.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Clone::Clone(const Vector2f pos, Tripulante *tripulante, const IDs::IDs ID)
    : Inimigo(pos, Vector2f(100.0f, 100.0f), tripulante, ID) {
  this->pontosVida = 20;
  this->dano = 3;

  nivel_maldade = 3;
  setSprite("assets/clone.png", pos.x, pos.y);

  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  projetil =
      new Projetil(pos, Vector2f(50.0f, 54.0f), IDs::IDs::projetil_inimigo);
  setProjetil(projetil);
}

Clone::Clone(Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Inimigo(pos, Vector2f(100.0f, 100.0f), nullptr, ID) {
  this->pontosVida = 20;
  this->dano = 3;

  nivel_maldade = 3;
  setSprite("assets/clone.png", pos.x, pos.y);

  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
  projetil =
      new Projetil(pos, Vector2f(50.0f, 54.0f), IDs::IDs::projetil_inimigo);
  setProjetil(projetil);
}

Clone::~Clone() {}
void Clone::executar() {
  if (vivo)
    mover();
}

void Clone::salvarDataBuffer(nlohmann::ordered_json &json) {}
void Clone::mover() {
  if (vivo) {
    Inimigo::mover();
    if (timerTiro.getElapsedTime().asSeconds() >= 2.0f) {
      atirar();
      timerTiro.restart();
    }
  }
}

void Clone::danificar(Tripulante *p) {}

void Clone::atirar() {
  if (!projetil->getAtivo()) {
    Vector2f posClone = sprite.getPosition();
    Vector2f posTripulante = tripulante->getSprite().getPosition();

    Vector2f direcao = posTripulante - posClone;
    float magnitude = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    if (magnitude != 0) {
      direcao /= magnitude;
    }

    projetil->setPosicao(posClone.x, posClone.y);
    projetil->setVelocidade(direcao * 10.0f);
    projetil->setAtivo(true, posClone);
  }
}
int Clone::getDano() { return dano; }

void Clone::salvar(json &arquivo) override {
  arquivo["id"] = static_cast<int>(getID());
  arquivo["vida"] = getVida();
  arquivo["posicao"]["x"] = getPosicao().x;
  arquivo["posicao"]["y"] = getPosicao().y;
  arquivo["tipo"] = "clone";
  if (projetil) {
    arquivo["projetil"]["id"] = static_cast<int>(projetil->getID());

    arquivo["projetil"]["ativo"] = projetil->getAtivo();
    arquivo["projetil"]["posicao"]["x"] = projetil->getPosicao().x;
    arquivo["projetil"]["posicao"]["y"] = projetil->getPosicao().y;
    arquivo["projetil"]["tipo"] = "projetil";
  }
}

REGISTRAR_CLASSE(Clone, "clone")
} // namespace Entidades::Personagens
