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

    // ===/===/===/===/ Obrigatórios ===/===/===/===/


    // Construtor (FALTA) 
    // O construtor inicializa a janela e a lista de objetos gráficos.
    Gerenciador_Grafico::Gerenciador_Grafico()
    {

        Gerenciador_Grafico janela = Gerenciador_Grafico::getInstancia();

        janela->inicializador();

    }

    // Destrutor (FALTA)
    // O destruidor libera recursos, como a janela.
    Gerenciador_Grafico::~Gerenciador_Grafico(){

        janela->fechar;
    }

    static Gerenciador_Grafico::Gerenciador_Grafico* getInstancia()
    {
        if (grafico == nullptr)
        {
            grafico = new Gerenciador_Grafico();
        }   
        return grafico;
    }


    void Gerenciador_Grafico::desenharEnte(Ente *pE)
    {
        if(pE)
        {
            // FAZ ALGO (FALTA)
            //jogador.setFillCollor(sf::Color::Blue);
            //jogador.setPosition(50.0f, 50.0f);

        }

    }

    // ===/===/===/===/ Outros ===/===/===/===/

     void Gerenciador_Grafico::inicializador()
    {
        // Desacoplamento
        start();

        // Define o Jogador
        sf::RectangleShape jogador (sf::Vector2f(50.0f, 50.0f));

        sf::Event event; // Declarar evento fora do loop

        while (window.isOpen()) // Usando window
        {
            while (window.pollEvent(event)) // Usando window
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    shutdown(); // Substituir pelo Método fechar
            }
            window.draw(jogador);
            window.display();
        }
    }

    void Gerenciador_Grafico::start(){

        // Desenha a Janela
        window(sf::VideoMode(WIDTH,HEIGHT), nomeJanela)

        // Definir framerate para 60fps
        window.setFramerateLimit(fps);

    }

    void Gerenciador_Grafico::shutdown(){
        window.close();
    }

    void Gerenciador_Grafico::adicionarObjetos( /*Alguma coisa*/ )
    {


    }

    void Gerenciador_Grafico::desenhar()
    {
        // Limpa a tela com a cor preta
        window.clear(sf::Color::Black);

        

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