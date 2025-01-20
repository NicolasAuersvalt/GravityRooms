#include "Entidades/Personagens/Jogador.h"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

namespace Entidades::Personagens
{

    Jogador::Jogador() : Personagem(make_pair(-1, -1), make_pair(-1, -1))
    {
    }

    Jogador::~Jogador()
    {
    }
    void Jogador::executar()
    {
    }

    void Jogador::salvarDataBuffer()
    {
    }

    // void Jogador::atualizar()
    // {
    // }
    // void Jogador::setListaEntidades(Listas::Lista_Entidades *lista)
    // {
    //     listaEntidades = lista;
    // }

    void Jogador::atirar()
    {
        Projetil *tiro = new Projetil();
        tiro->setSprite("assets/projetilG.png", 0, 0);

        // Get position directly from sprite
        sf::Vector2f pos = getSprite().getPosition();
        tiro->atirar(pos);

        // if (listaEntidades)
        // {
        //     listaEntidades->incluir(static_cast<Entidade *>(tiro));
        // }
    }
    void Jogador::mover()

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

        // Jogador atira
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            atirar();
        }
    }
    void Jogador::colidir(Entidades::Entidade *e)
    {
    }
}