#include "Entidades/projetil.h"

// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
    : Entidade(pos, tam, ID),
      dano(10)  //, danoProjetil(10)
{}
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
int Projetil::getDano() { return danoProjetil; }

void Projetil::salvar() {}
void Projetil::mover() {}

void Projetil::colisao(Entidade *outraEntidade, sf::Vector2f ds) {}

}  // namespace Entidades