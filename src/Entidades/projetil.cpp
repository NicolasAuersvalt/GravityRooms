#include "Entidades/projetil.h"
#include "Entidades/Personagens/personagem.h"
#include <iostream>

class Personagem;  // Forward declaration if needed

using namespace std;
using namespace Entidades;

// Definição da Variável Estática Dano
int Projetil::danoProjetil = 10;  

namespace Entidades
{

    Projetil::Projetil() : 
    Entidade(pos, tam)
    {
    }
    Projetil::~Projetil()
    {
    }
    /*void Projetil::executar()
    {
    }
    */

    void Projetil::atualizar()
    {
    }

    void Entidades::Projetil::setAtirador(Entidade *a)
    {
    }

    void Entidades::Projetil::colisao(Entidade *e)
    {
    }
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

    void Entidades::Projetil::danificar(Personagem *p)
    {
    }

}
