#include "Entidades/projetil.h"

// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;

namespace Entidades {

Projetil::Projetil()
    : Entidade(pos, tam, IDs::IDs::projetil_inimigo),
      dano(10)  //, danoProjetil(10)
{}
Projetil::~Projetil() {}
/*void Projetil::executar()
{
}
*/

void Projetil::atualizar() {}

void Projetil::setAtirador(Entidade *a) {}

void Projetil::colisao(Entidade *e) {}
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

}  // namespace Entidades
