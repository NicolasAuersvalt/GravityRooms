#include "Entidades/Obstaculos/Obstaculo.h"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;


// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Obstaculos{

    Obstaculo::Obstaculo(pair<int, int> p, pair<int, int> d) :  Entidade(p, d)
    {
        
    }

    Obstaculo::~Obstaculo(){


    }
}
