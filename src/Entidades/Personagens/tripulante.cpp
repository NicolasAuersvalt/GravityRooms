#include "Entidades/Personagens/Tripulante.h"
// #include "gerenciador_grafico.h"

#include <iostream>


using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens
{

    Tripulante::Tripulante() : Personagem(make_pair(-1, -1), make_pair(-1, -1))
    {
    }

    Tripulante::~Tripulante()
    {
    }
    void Tripulante::executar()
    {
    }
    // void Tripulante::atualizar()
    // {
    
    // }

    void Tripulante::mover() 
    {
            // Movimentação (sem física, apenas mover pela tela)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            getSprite().move(-5.f, 0.f); // Move para a esquerda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            getSprite().move(5.f, 0.f); // Move para a direita
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            getSprite().move(0.f, -5.f); // Move para cima
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            getSprite().move(0.f, 5.f); // Move para baixo
        }
    }
}