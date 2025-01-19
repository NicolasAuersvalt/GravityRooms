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

    pJog1.setSprite("assets/tripulanteG.png", 0, 0, 150, 150);
    plataforma.setSprite("assets/plataformaG.png", 0, 0, 499, 150);

    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms(){

}

void Gravity_Rooms::executar(){
    
    GG.executar(); 
    while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
         // Atualiza a janela e lida com os eventos
        pJog1.desenhar();
        plataforma.desenhar();
    }

}


    // ===/===/===/===/ Outros  ===/===/===/===/