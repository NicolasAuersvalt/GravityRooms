#include "gravity_rooms.h"
#include "ente.h"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;


// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Gravity_Rooms::Gravity_Rooms():
GG(), pJog1()
{
    Ente::setGerenciador(&GG);
    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms(){

}

void Gravity_Rooms::executar(){
    pJog1.setSprite("assets/tripulanteG.png", 0, 0, 0, 0);
    pJog1.desenhar();
}


    // ===/===/===/===/ Outros  ===/===/===/===/