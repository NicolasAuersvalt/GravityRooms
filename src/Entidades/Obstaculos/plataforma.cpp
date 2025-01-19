#include "Entidades/Obstaculos/Plataforma.h"

namespace Entidades::Obstaculos
{

    Plataforma::Plataforma(std::pair<int, int> p, std::pair<int, int> d) : Obstaculo(p, d), altura(0)
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