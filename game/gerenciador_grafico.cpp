//#include "Gerenciadores/gerenciador_colisoes.h"
#include "gerenciador_grafico.h"
#include<string>
#include <iostream>

// Dos objetivos

/*
Criar e gerenciar a janela de exibição.
Desenhar objetos gráficos, como sprites ou formas.
Atualizar a tela a cada quadro.

*/

// Resolução da Janela
#define WIDTH 1280
#define HEIGHT 720

namespace Gerenciadores{

    // Construtor (FALTA) 
    // O construtor inicializa a janela e a lista de objetos gráficos.
    Gerenciador_Grafico::Gerenciador_Grafico()
    : window(sf::VideoMode(WIDTH,HEIGHT), nomeJanela)
    {
        // Inicializa a janela com o tamanho e largura e o nome

    }

    // Destrutor (FALTA)
    // O destruidor libera recursos, como a janela.
    Gerenciador_Grafico::~Gerenciador_Grafico(){


    }

    void Gerenciador_Grafico::desenharEnte(Ente *pE)
    {
        if(pE)
        {
            // FAZ ALGO (FALTA)

        }

    }

     void Gerenciador_Grafico::inicializador()
    {
        // Definir framerate para 60fps
        window.setFramerateLimit(fps);

        sf::Event event; // Declarar evento fora do loop

        while (window.isOpen()) // Usando window
        {
            while (window.pollEvent(event)) // Usando window
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }

    void Gerenciador_Grafico::adicionarObjetos( /*Alguma coisa*/ )
    {


    }

    void Gerenciador_Grafico::desenhar()
    {
        // Limpa a tela com a cor preta
        window.clear(sf::Color::Black);

        // Desenha todos os objetos na lista
        // ...

    }

    void Gerenciador_Grafico::atualizar()
    {


    }

    const bool Gerenciador_Grafico::estaAberta()
    {

    
    }

    
    void Gerenciador_Grafico::operator+(int val)
    {


    }
    
}