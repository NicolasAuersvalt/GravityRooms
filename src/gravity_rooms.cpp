#include "gravity_rooms.h"
#include "ente.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// #include "Listas/lista_entidades.cpp"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;

// ===/===/===/===/ Obrigatório ===/===/===/===/

// Construtor
Gravity_Rooms::Gravity_Rooms() : GG(),
        pJog1(),
        pAnd1(),
        pAnd2(),
        plataforma(),
        LJog1(),
        GC()
{
    Ente::setGerenciador(&GG);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/nave1.jpg"))
    {
        std::cerr << "Erro ao carregar o background!" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(25, 25);

    pJog1.setSprite("assets/tripulanteG.png", 0, 0);

    LJog1.incluir(static_cast<Entidade *>(&pJog1));

    plataforma.setSprite("assets/plataformaG.png", 0, 0);
    LJog1.incluir(static_cast<Entidade *>(&plataforma));

    pAnd1.setSprite("assets/androidG.png", 0, 0);
    LJog1.incluir(static_cast<Entidade *>(&pAnd1));

    pJog1.setListaEntidades(&LJog1);

    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms()
{
}

void Gravity_Rooms::executar()
{

    GG.executar();
    GC.incluirTripulante(pJog1);
    GC.incluirInimigo(static_cast<Inimigo *>(&pAnd1));
    
    while (GG.estaAberta())
    { // Enquanto a janela estiver aberta
        sf::Event evento;

        while (GG.processarEvento(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                GG.fechar();
            }
        }

        GG.limpar(); // Limpa a tela antes de desenhar qualquer coisa

        // Desenha os objetos na ordem correta
        //GG.desenhar(backgroundSprite); // Desenha o fundo primeiro

        // GG.desenharEnte(&pJog1);  // Desenha o Tripulante 1 (ou qualquer outro ente)

        LJog1.desenharTodos(); // Desenha os outros sprites da lista
        GC.executar();

        GG.exibir(); // Exibe a tela com todos os objetos desenhados

        // Atualiza os objetos, caso necessário (atualização de movimentos, animações, etc.)
        LJog1.atualizarTodas();
    }
}


// ===/===/===/===/ Outros  ===/===/===/===/