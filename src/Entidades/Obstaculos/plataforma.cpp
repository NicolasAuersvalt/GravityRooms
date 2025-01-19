#include "Entidades/Obstaculos/Plataforma.h"


namespace Entidades::Obstaculos
{

    Plataforma::Plataforma():Obstaculo(make_pair(-1, -1), make_pair(-1, -1))
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

    void Plataforma::mover() const
    {
        // Implementation
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