#include "Entidades/projetil.h"

#include "Entidades/Personagens/inimigo.h"
// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Entidade(pos, tam, ID), dano(3), ativo(false) {
  setSprite("assets/projetil.png", pos.x, pos.y);
  setTamanho(Vector2f(50.0f, 25.0f));
  setPosicao(-12000.f, -12000.f);
  sprite.setPosition(-12000.f, -12000.f);
}
Projetil::~Projetil() {}
void Projetil::executar() {
  if (ativo) {
    mover();
  }
}

void Projetil::setVelocidade(const Vector2f &vel) { velocidade = vel; }

void Projetil::atualizar() {}

void Projetil::setAtirador(Entidade *a) {}

int Projetil::getDano() { return dano; }

bool Projetil::getAtivo() { return ativo; }

void Projetil::mover() {
  if (ativo) {
    getSprite().move(20.0f, 0.0f);
    if (getSprite().getPosition().x > 1280 || getSprite().getPosition().x < 0 ||
        getSprite().getPosition().y > 920 || getSprite().getPosition().y < 0) {
      setAtivo(false, {-150.f, -150.f});
    }
  }
}

void Projetil::colisao(Entidade *outraEntidade, Vector2f ds) {
  // Verifica se a entidade passada é nula
  if (!outraEntidade) {
    return;
  }
  // Verifica o ID da entidade com a qual o projétil colidiu
  switch (outraEntidade->getID()) {
  case (IDs::IDs::clone): {                    // Caso a entidade seja um clone
    if (ID == IDs::IDs::projetil_tripulante) { // Verifica se o projétil é do
                                               // tripulante
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
      inimigo->recebeDano(dano);

      getSprite().setPosition(-130.f, -130.f);
      ativo = false;
    }
    break;
  }
  case (IDs::IDs::ciborgue): { // Caso a entidade seja um ciborgue
    if (ID == IDs::IDs::projetil_tripulante) { // Verifica se o projétil é do
                                               // tripulante
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

      if (inimigo) {
        try {
          inimigo->recebeDano(dano);

        } catch (const exception &e) {
        }
      }

      setAtivo(false, Vector2f(-130.f, -130.f));
    }
    break;
  }
  case (IDs::IDs::androide): { // Caso a entidade seja um androide
    if (ID == IDs::IDs::projetil_tripulante) { // Verifica se o projétil é do
                                               // tripulante
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

      if (inimigo) {
        inimigo->recebeDano(dano);

        ativo = false;
        sprite.setPosition(-130.f, -130.f);
        setPosicao(-130.f, -130.f);

      } else {
        cout << "Failed to cast enemy" << endl;
      }
    }
    break;
  }
  case (IDs::IDs::tripulante): { // Caso a entidade seja um tripulante
    if (ID == IDs::IDs::projetil_inimigo) { // Verifica se o projétil é de um
                                            // inimigo
      Entidades::Personagens::Tripulante *tripulante =
          dynamic_cast<Entidades::Personagens::Tripulante *>(outraEntidade);
      tripulante->recebeDano(dano);
      getSprite().setPosition(-130.f, -130.f);
      ativo = false;
    }
  } break;
  }
}

void Projetil::setAtivo(bool status, const Vector2f pos) {
  ativo = status;
  setSprite("assets/projetil.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  sprite.setPosition(pos.x, pos.y);
}

void Projetil::salvar(json &arquivo) override {
  arquivo["id"] = static_cast<int>(getID());
  arquivo["ativo"] = getAtivo();
  arquivo["posicao"]["x"] = getPosicao().x;
  arquivo["posicao"]["y"] = getPosicao().y;
  arquivo["tipo"] = "projetil";
}

REGISTRAR_CLASSE(Projetil, "projetil")
} // namespace Entidades