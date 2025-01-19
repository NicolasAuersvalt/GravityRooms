#include "gravity_rooms.h"
#include "ente.h"
//#include "Listas/lista_entidades.cpp"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;


// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Gravity_Rooms::Gravity_Rooms():
GG(), pJog1()//, LJog1()
{
    Ente::setGerenciador(&GG);
    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms(){

}

void Gravity_Rooms::executar(){

    pJog1.setSprite("assets/tripulanteG.png", 500, 500, 200, 200);
    // LJog1.incluir(static_cast<Entidade*>(&pJog1));  // Passando referência como ponteiro


    while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
        GG.executar();  // Atualiza a janela e lida com os eventos
        pJog1.desenhar();
        cout << "BELZ" << endl;
    }

}


    // ===/===/===/===/ Outros  ===/===/===/===/