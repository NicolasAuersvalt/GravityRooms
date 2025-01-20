#include "Entidades/Personagens/Inimigo.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens
{

    Inimigo::Inimigo() : Personagem(make_pair(-1, -1), make_pair(-1, -1))
    {
    }

    Inimigo::~Inimigo()
    {
    }
    void Inimigo::executar()
    {
    }
    void Inimigo::mover()
    {
        float currentX = getSprite().getPosition().x;

        // Check boundaries and change direction
        if (currentX <= 0)
        {
            movingRight = true;
            getSprite().setScale(1.0f, 1.0f);
        }
        else if (currentX >= 1280 - getSprite().getGlobalBounds().width)
        {
            movingRight = false;
            getSprite().setScale(-1.0f, 1.0f);
        }

        // Move based on direction
        if (movingRight)
        {
            getSprite().move(5.0f, 0.f);
        }
        else
        {
            getSprite().move(-5.0f, 0.f);
        }
    }
    void Inimigo::salvarDataBuffer()
    {
    }
}
