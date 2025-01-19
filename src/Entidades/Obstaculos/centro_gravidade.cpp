#include "Entidades/Obstaculos/Centro_gravidade.h"

#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos
{

    Centro_Gravidade::Centro_Gravidade() : Obstaculo(make_pair(-1, -1), make_pair(-1, -1))
    {
    }

    Centro_Gravidade::~Centro_Gravidade()
    {
    }
    void Centro_Gravidade::executar()
    {
    }

    void Centro_Gravidade::mover() const
    {
    }

}