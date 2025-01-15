#include "Entidades/entidade.h"

#include <iostream>

using namespace std;
using namespace Entidades;


namespace Entidades{


    Entidade::Entidade(pair<int,int>p, pair<int,int>d):
    pos(p), dim(d)
    {
        
    }
    Entidade::~Entidade()
    {
        pos = make_pair(-1, -1);
        dim = make_pair(-1, -1);
        
    }

    

    void Entidade::salvarDataBuffer()
    {

        
    }
}  