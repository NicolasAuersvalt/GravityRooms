#ifndef ENTE_H
#define ENTE_H

#include <SFML/Graphics.hpp>
#include "gerenciador_grafico.h"

class Gerenciador_Grafico;

class Ente{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        int id;
        static Gerenciadores::Gerenciador_Grafico *pGG; // Ente utiliza Gerenciador Gráfico (Bidirecional)
        
                

        // ===/===/===/===/ Outros  ===/===/===/===/


      public:

         // ===/===/===/===/ Obrigatório ===/===/===/===/
        sf::Sprite *pFig;
        Ente();
        ~Ente();

        virtual void executar() = 0; // Pois é abstrata
        virtual void desenhar() = 0;

        sf::Sprite getFig();

        // ===/===/===/===/ Outros  ===/===/===/===/
        

};

#endif