#ifndef ENTE_H
#define ENTE_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciadores/gerenciador_grafico.h"

using namespace std;
using Gerenciadores::Gerenciador_Grafico;

class Gerenciador_Grafico;

class Ente{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        int id;
        static Gerenciador_Grafico *pGG; // Ente utiliza Gerenciador Gráfico (Bidirecional)
        

        // ===/===/===/===/ Outros  ===/===/===/===/
        
        // Figura *pFig;
        sf::Texture *texture; // Substituido
        sf::Sprite sprite;

      public:

         // ===/===/===/===/ Obrigatório ===/===/===/===/

        Ente();
        ~Ente();

        virtual void executar() = 0; // Pois é abstrata
        void desenhar(); // Possui o endereço do gerenciador gráfico em protected, mas só UTILIZA o gerenciador

        // ===/===/===/===/ Outros  ===/===/===/===/

        void setSprite(std::string local, int posX, int posY);
        sf::Texture* getTexture(); // retorna o endereço da textura do protected sf::Texture *pFig
        sf::Sprite& getSprite(); // retorna o endereço da textura do protected sf::Texture *pFig
        
        static void setGerenciador(Gerenciadores::Gerenciador_Grafico* gg);
        

};

#endif