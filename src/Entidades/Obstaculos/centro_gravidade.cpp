#include "Entidades/Obstaculos/centro_gravidade.h"

#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos
{

    Centro_Gravidade::Centro_Gravidade(const sf::Vector2f pos, const sf::Vector2f tam) : Obstaculo(pos, tam)
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