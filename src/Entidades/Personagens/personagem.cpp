#include "Entidades/Personagens/personagem.h"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;


// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Personagens{

    Personagem::Personagem(pair<int,int>p, pair<int, int>d):
    Entidade(p, d)
    {
        
    }

    Personagem::~Personagem(){


    }
    void Personagem::salvar(){


    }
}
