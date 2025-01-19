#include "Gravity_rooms.h"
#include "Ente.h"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;


// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Gravity_Rooms::Gravity_Rooms():
GG(), pJog1(), plataforma()
{
    Ente::setGerenciador(&GG);
    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms(){

}

void Gravity_Rooms::executar(){

    pJog1.setSprite("assets/tripulanteG.png", 50, 50, 20, 20);
    plataforma.setSprite("assets/plataforma.png", 100, 100, 20, 20);
    GG.executar(); 
    while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
         // Atualiza a janela e lida com os eventos
        pJog1.desenhar();
        plataforma.desenhar();
    }

}


    // ===/===/===/===/ Outros  ===/===/===/===/