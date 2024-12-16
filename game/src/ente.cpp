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
    
    if(pFig){
        // Desenha a entidade na tela;
        desenhar();
    }
}

// Destrutor
Ente::~Ente(){
    pFig = NULL;

}

void Ente::desenhar(){
    Gerenciador_Grafico::desenharEnte(&this);

}

sf::Sprite getFig(){


}
    // ===/===/===/===/ Outros  ===/===/===/===/
