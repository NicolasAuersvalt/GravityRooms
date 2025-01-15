#ifndef ENTE_H
#define ENTE_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciadores/gerenciador_grafico.h"

using namespace std;

class GerenciadorGrafico;

class Ente{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        int id;
        static GerenciadorGrafico *pGG; // Ente utiliza Gerenciador Gráfico (Bidirecional)
        

        // ===/===/===/===/ Outros  ===/===/===/===/
        
        // Figura *pFig;
        sf::Texture *pFig; // Substituido


      public:

         // ===/===/===/===/ Obrigatório ===/===/===/===/

        Ente();
        ~Ente();
        virtual void executar() = 0; // Pois é abstrata

        virtual void desenhar() = 0; // Possui o endereço do gerenciador gráfico em protected, mas só UTILIZA o gerenciador
        sf::Texture* getFig(); // retorna o endereço da textura do protected sf::Texture *pFig
        void setSprite(std::string local);
        // ===/===/===/===/ Outros  ===/===/===/===/
        

};

#endif