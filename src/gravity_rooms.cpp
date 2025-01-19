#include "gravity_rooms.h"
#include "ente.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//#include "Listas/lista_entidades.cpp"
//#include "gerenciador_grafico.h"

#include <iostream>

using namespace std;


// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Gravity_Rooms::Gravity_Rooms():
GG(), pJog1(), LJog1()
{
    Ente::setGerenciador(&GG);
    

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/nave1.jpg")) {
        std::cerr << "Erro ao carregar o background!" << std::endl;
        return;
    }
    
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(25, 25);

    pJog1.setSprite("assets/tripulanteG.png", 25, 25);
    LJog1.incluir(static_cast<Entidade*>(&pJog1));

    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms(){

}

void Gravity_Rooms::executar() {
    
    // setSprite(sstring local, int posX, int posY)

    while (GG.estaAberta()) {  // Enquanto a janela estiver aberta
        
        GG.limpar();

        sf::Event evento;
        bool teclaPressionada = false;  // Variável para controlar se uma tecla foi pressionada
        
        while(GG.processarEvento(evento)){
            if (evento.type == sf::Event::Closed) {
                GG.fechar();
            }

            // Verifica se uma tecla foi pressionada
            if (evento.type == sf::Event::KeyPressed) {
                teclaPressionada = true;
            }
        }
        
        // Só prossegue se uma tecla foi pressionada

        GG.desenhar(backgroundSprite);  // Desenha o fundo
        LJog1.desenharTodos();
        LJog1.atualizarTodas();
        GG.exibir();

    }
}



    // ===/===/===/===/ Outros  ===/===/===/===/