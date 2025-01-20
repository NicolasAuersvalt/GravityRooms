#include "Entidades/Personagens/Androide.h"

#include <iostream>
using namespace std;
using namespace Entidades::Personagens;
using namespace Entidades;
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
        mover();
    }

    void Androide::danificar(Jogador *p)
    {
    }

    void Androide::mover()
    {
        Inimigo::mover();
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
