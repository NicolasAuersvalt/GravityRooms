#include <iostream>
#include "ente.h"
#include "gerenciador_grafico.h"


using namespace std;
using namespace Gerenciadores;

 
// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Ente::Ente() 
: pFig(), id(-1) // id (-1) pois não fará sentido id negativo no jogo
{

}

// Destrutor
Ente::~Ente(){
    pFig = NULL;

}


sf::Sprite getFig(){

}
    // ===/===/===/===/ Outros  ===/===/===/===/
