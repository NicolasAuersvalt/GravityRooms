#include "Entidades/Entidade.h"

#include <iostream>

using namespace std;
using namespace Entidades;

namespace Entidades
{

    Entidade::Entidade(pair<int, int> p, pair<int, int> d) : Ente(),
                                                             pos(p)
    {
    }
    Entidade::~Entidade()
    {
        pos = make_pair(-1, -1);
    }

    void Entidade::salvarDataBuffer()
    {
    }
    void Entidade::atualizar()
    {
       
    }

    pair<int, int> Entidade::getPosition()
    {
        return pos;
    }
    pair<int, int> Entidade::getDirection()
    {
        return dim;
    }
}
