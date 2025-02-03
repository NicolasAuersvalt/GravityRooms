#include "Entidades/projetil.h"

#include "Entidades/Personagens/inimigo.h"
// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Entidade(pos, tam, ID), dano(3), ativo(false) {
  cout << "bliii" << endl;
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

void Projetil::danificar(Personagem *p) {}

int Projetil::getDano() { return dano; }

bool Projetil::getAtivo() { return ativo; }

void Projetil::salvar() {}
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
  if (!outraEntidade) {
    std::cout << "Warning: Null entity in collision" << std::endl;
    return;
  }  // TESTE
  switch (outraEntidade->getID()) {
    case (IDs::IDs::clone): {
      if (ID == IDs::IDs::projetil_tripulante) {
        Entidades::Personagens::Inimigo *inimigo =
            dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
        inimigo->recebeDano(dano);

        getSprite().setPosition(-130.f, -130.f);
        ativo = false;
      }
      break;
    }
    case (IDs::IDs::ciborgue): {
      if (ID == IDs::IDs::projetil_tripulante) {
        Entidades::Personagens::Inimigo *inimigo =
            dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

        if (inimigo) {
          try {
            inimigo->recebeDano(dano);

          } catch (const std::exception &e) {
          }
        }

        // Deactivate projectile after hit
        setAtivo(false, Vector2f(-130.f, -130.f));
      }
      break;
    }
    case (IDs::IDs::androide): {
      if (ID == IDs::IDs::projetil_tripulante) {
        // Entidades::Personagens::Inimigo *inimigo =
        //     dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
        // inimigo->recebeDano(dano);

        // getSprite().setPosition(-130.f, -130.f);
        // ativo = false;
        // std::cout << "Inimigo atingido pelo projetil do tripulante"
        //           << std::endl;
        std::cout << "Projectile collision with enemy type: "
                  << static_cast<int>(outraEntidade->getID()) << std::endl;

        Entidades::Personagens::Inimigo *inimigo =
            dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

        if (inimigo) {
          try {
            std::cout << "Enemy health before damage: " << inimigo->getVida()
                      << std::endl;
            inimigo->recebeDano(dano);
            std::cout << "Enemy health after damage: " << inimigo->getVida()
                      << std::endl;

            // Deactivate projectile first
            ativo = false;
            sprite.setPosition(-130.f, -130.f);
            setPosicao(-130.f, -130.f);

          } catch (const std::exception &e) {
            std::cerr << "Error damaging enemy: " << e.what() << std::endl;
          }
        } else {
          std::cout << "Failed to cast enemy" << std::endl;
        }
      }
      break;
    }
    case (IDs::IDs::tripulante): {
      // cout << "colisao com entidade ID: "
      //      << static_cast<int>(outraEntidade->getID()) << endl;
      if (ID == IDs::IDs::projetil_inimigo) {
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
  cout << "player 2 is Shooting projectile"
       << " Position: " << getSprite().getPosition().x << ", "
       << getSprite().getPosition().y << " " << endl;
}

}  // namespace Entidades