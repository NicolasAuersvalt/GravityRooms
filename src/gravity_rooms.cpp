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

    pJog1.setSprite("assets/tripulanteG.png", 50, 50, 20, 20);

    while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
        GG.executar();  // Atualiza a janela e lida com os eventos
        pJog1.desenhar();
    }

}


    // ===/===/===/===/ Outros  ===/===/===/===/