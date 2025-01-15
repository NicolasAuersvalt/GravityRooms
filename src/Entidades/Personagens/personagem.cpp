#include "Entidades/Personagens/personagem.h"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;


// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Personagens{

    Personagem::Personagem():
    Entidade(make_pair(0, 0), make_pair(0, 0))
    {
        
    }

    Personagem::~Personagem(){


    }
    void Personagem::salvar(){


    }
}
