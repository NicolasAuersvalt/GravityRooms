#include "Entidades/Obstaculos/plataforma.h"


namespace Entidades::Obstaculos
{

    Plataforma::Plataforma(sf::Vector2f pos, const sf::Vector2f tam):Obstaculo(pos, tam)
    {
    }

    Plataforma::~Plataforma()
    {
    }

    void Plataforma::executar()
    {
        // Implementation
        mover();
        desenhar();
    }

    void Plataforma::mover() 
    {
        // Implementation
    }
        void Plataforma::salvar() {
        // Implementation for saving state
    }

    // void Plataforma::mover()
    // {
    //     position.first += velocity.first;
    //     position.second += velocity.second;
    // }

    // void Plataforma::desenhar(Gerenciador_Grafico pGG)
    // {
    // }
    // void Plataforma::atualizar()
    // {
    //     // Add update implementation
    // }

    // void Plataforma::colisao(Entidade *outra)
    // {
    //     // Add collision implementation
    // }
}