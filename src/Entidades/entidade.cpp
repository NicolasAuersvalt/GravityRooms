#include "Entidades/entidade.h"

#include <iostream>

using namespace std;
using namespace Entidades;


namespace Entidades{


    Entidade::Entidade(pair<int,int>p, pair<int,int>d):
    Ente(),
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
    void Entidade::atualizar() {
        // Movimentação (sem física, apenas mover pela tela)
        
        // Acessa o sprite diretamente
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            getSprite().move(-50.f, 0.f);  // Move para a esquerda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            getSprite().move(50.f, 0.f);   // Move para a direita
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            getSprite().move(0.f, -50.f);  // Move para cima
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            getSprite().move(0.f, 50.f);   // Move para baixo
        }
    }

}  