#include "Entidades/Personagens/Personagem.h"
// #include "gerenciador_grafico.h"

#include <iostream>


using namespace std;
using namespace Entidades::Personagens;

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Personagens
{

    Personagem::Personagem(pair<int, int> p, pair<int, int> d) : Entidade(p, d), num_vidas(0)
    {
    }

    Personagem::~Personagem()
    {
    }
    void Personagem::salvar()
    {
    }

    void Personagem::setVida(const int n)
    {
        num_vidas = n;
    }

    const int Personagem::getVida() const
    {
        return num_vidas;
    }
    bool Personagem::getVivo()
    {
        // se saiu de tela morreu
        //return (num_vidas > 0 && position.y < 700);
    }
}
