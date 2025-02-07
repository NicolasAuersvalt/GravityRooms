#include "Entidades/projetil.h"

#include "Entidades/Personagens/inimigo.h"
// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Entidade(pos, tam, ID), dano(3), ativo(false) {
  setSprite("assets/projetil.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(50.0f, 25.0f));
  setPosicao(-12000.f, -12000.f);
  sprite.setPosition(-12000.f, -12000.f);
}
Projetil::~Projetil() {}
void Projetil::executar() {
  if (ativo) {
    mover();
  }
}

void Projetil::setVelocidade(const sf::Vector2f &vel) { velocidade = vel; }

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

void Projetil::colisao(Entidade *outraEntidade, sf::Vector2f ds) {
  // Verifica se a entidade passada é nula
  if (!outraEntidade) {
    std::cout << "Warning: Null entity in collision" << std::endl;
    return;
<<<<<<< HEAD
  } // TESTE
  switch (outraEntidade->getID()) {
  case (IDs::IDs::clone): {
    if (ID == IDs::IDs::projetil_tripulante) {
=======
  }
  // Verifica o ID da entidade com a qual o projétil colidiu
  switch (outraEntidade->getID()) {
  case (IDs::IDs::clone): {                    // Caso a entidade seja um clone
    if (ID == IDs::IDs::projetil_tripulante) { // Verifica se o projétil é do
                                               // tripulante
>>>>>>> psave
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
      inimigo->recebeDano(dano);

      getSprite().setPosition(-130.f, -130.f);
      ativo = false;
    }
    break;
  }
<<<<<<< HEAD
  case (IDs::IDs::ciborgue): {
    if (ID == IDs::IDs::projetil_tripulante) {
=======
  case (IDs::IDs::ciborgue): { // Caso a entidade seja um ciborgue
    if (ID == IDs::IDs::projetil_tripulante) { // Verifica se o projétil é do
                                               // tripulante
>>>>>>> psave
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

      if (inimigo) {
        try {
          inimigo->recebeDano(dano);

        } catch (const std::exception &e) {
        }
      }

      setAtivo(false, Vector2f(-130.f, -130.f));
    }
    break;
  }
<<<<<<< HEAD
  case (IDs::IDs::androide): {
    if (ID == IDs::IDs::projetil_tripulante) {
=======
  case (IDs::IDs::androide): { // Caso a entidade seja um androide
    if (ID == IDs::IDs::projetil_tripulante) { // Verifica se o projétil é do
                                               // tripulante
>>>>>>> psave
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

      if (inimigo) {
        inimigo->recebeDano(dano);

        ativo = false;
        sprite.setPosition(-130.f, -130.f);
        setPosicao(-130.f, -130.f);

      } else {
        std::cout << "Failed to cast enemy" << std::endl;
      }
    }
    break;
  }
<<<<<<< HEAD
  case (IDs::IDs::tripulante): {
    if (ID == IDs::IDs::projetil_inimigo) {
=======
  case (IDs::IDs::tripulante): { // Caso a entidade seja um tripulante
    if (ID == IDs::IDs::projetil_inimigo) { // Verifica se o projétil é de um
                                            // inimigo
>>>>>>> psave
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

<<<<<<< HEAD
=======
REGISTRAR_CLASSE(Projetil, "projetil")
>>>>>>> psave
} // namespace Entidades