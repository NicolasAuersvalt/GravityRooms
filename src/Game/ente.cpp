#include "Game/ente.h"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;


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
    //Gerenciadores::Gerenciador_Grafico::desenharEnte(this);

}


    // ===/===/===/===/ Outros  ===/===/===/===/