#include "Entidades/Personagens/Androide.h"

#include <iostream>
using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens
{

    Androide::Androide()
    {
    }

    Androide::~Androide()
    {
    }
    void Androide::executar()
    {
    }

    void Androide::danificar(Tripulante *p)
    {
    }

    void Androide::mover()
    { 
        
    float currentX = getSprite().getPosition().x;
    
    // Check boundaries and change direction
    if (currentX <= 0) {
        movingRight = true;
    }
    else if (currentX >= 1280 - getSprite().getGlobalBounds().width) {
        movingRight = false;
    }
    
    // Move based on direction
    if (movingRight) {
        getSprite().move(5.0f, 0.f);
    }
    else {
        getSprite().move(-5.0f, 0.f);
    }
    }
    void Androide::colidir(Entidade *outro, string direction)
    {
        // int index = other->get_id();
        // switch (index)
        // {
        // case 1:
        //     other->inflict_damage(damage);
        //     break;
        // case 11:
        //     if (direction == "Right" || direction == "Left")
        //     {
        //         vel = sf::Vector2f(-CR * vel.x, vel.y);
        //     }
        //     else
        //     {
        //         vel = sf::Vector2f(vel.x, -CR * vel.y);
        //     }
        //     break;

        // default:
        //     break;
        // }
    }
}
