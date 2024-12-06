#include "Gerenciadores/gerenciador_colisoes.h"

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

// Construtor (FALTA) 
// O construtor inicializa a janela e a lista de objetos gráficos.
Gerenciador_Grafico::Gerenciador_Grafico()
: m_window(sf::VideoMode(WIDTH,HEIGHT), nomeJanela)
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
    m_window.setFramerateLimit(fps);

}

void Gerenciador_Grafico::adicionarObjetos( /*Alguma coisa*/ )
{


}

 void Gerenciador_Grafico::desenhar()
 {
    // Limpa a tela com a cor preta
    m_window.clear(sf::Color::Black);

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