#include "Entidades/projetil.h"

#include "Entidades/Personagens/inimigo.h"
// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Entidade(pos, tam, ID),
      dano(1),
      ativo(false)  //, danoProjetil(10)
{
  setSprite("assets/projetil.png", pos.x, pos.y);
  //   // setSprite("assets/projetilP.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(150.0f, 150.0f));
  setPosicao(-130.f, -130.f);
  sprite.setPosition(-130.f, -130.f);
  std::cout << "Projetil Position: " << pos.x << " " << pos.y << std::endl;
}
Projetil::~Projetil() {}
/*void Projetil::executar()
{
}
*/

void Projetil::atualizar() {}

void Projetil::setAtirador(Entidade *a) {}

/*
bool Entidades::Projetil::getColidir(Entidade* e)
{
    if (e->getPosition().first > 1280 ||
     e->getPosition().first < 0 ||
      e->getPosition().second > 920 ||
       e->getPosition().second < 0)
        colidiu = true;
    return colidiu;
}
*/

void Projetil::danificar(Personagem *p) {}

/*
    void Projetil::executar(){
        cout << "OK" << endl;

    }
    void Projetil::mover(){
        cout << "OK" << endl;
    }
*/
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
  switch (outraEntidade->getID()) {
    case (IDs::IDs::inimigo):
    case (IDs::IDs::clone):     // Add clone case
    case (IDs::IDs::androide):  // Add other enemy types
    case (IDs::IDs::ciborgue): {
      if (ID == IDs::IDs::projetil_tripulante) {
        Entidades::Personagens::Inimigo *inimigo =
            dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);

        inimigo->recebeDano(dano);

        getSprite().setPosition(-130.f, -130.f);
        ativo = false;
      }
    } break;
    case (IDs::IDs::tripulante): {
      if (ID == IDs::IDs::projetil_inimigo) {
        Entidades::Personagens::Tripulante *tripulante =
            dynamic_cast<Entidades::Personagens::Tripulante *>(outraEntidade);
        cout << "colisao" << endl;
        tripulante->recebeDano(dano);
        cout << "recebeu dano na colisao" << dano << endl;
        //  getSprite().setPosition(-130.f, -130.f);
        // ativo = false;
      }
    } break;
  }
}
void Projetil::setAtivo(bool i, const Vector2f pos) {
  cout << "herreeeeeee" << endl;
  ativo = i;
  setSprite("assets/projetilG.png", pos.x, pos.y);
  setPosicao(pos.x, pos.y);
  sprite.setPosition(pos.x, pos.y);
}

}  // namespace Entidades