#include "Entidades/Personagens/Inimigo.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;


namespace Entidades::Personagens{


    Inimigo::Inimigo():
    Personagem(make_pair(-1, -1), make_pair(-1, -1))
    {
        
    }

    Inimigo::~Inimigo(){


    }
    void Inimigo::executar(){

    }
    void Inimigo::salvarDataBuffer(){


    }
}  