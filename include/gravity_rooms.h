#ifndef GRAVITY_ROOMS_H
#define GRAVITY_ROOMS_H

#include"Listas/Lista_entidades.h"
#include"Entidades/Personagens/Jogador.h"

#include"Entidades/Obstaculos/Plataforma.h"
#include"Gerenciadores/Gerenciador_grafico.h"

using Entidades::Personagens::Jogador;
using Entidades::Obstaculos::Plataforma;
using Gerenciadores::Gerenciador_Grafico;
using Listas::Lista_Entidades;

class Gravity_Rooms{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

        Jogador pJog1;
        Plataforma plataforma;
        Gerenciador_Grafico GG; 
        

                

        // ===/===/===/===/ Outros  ===/===/===/===/
        Lista_Entidades LJog1;
        sf::Sprite backgroundSprite;


    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        
                

        // ===/===/===/===/ Outros  ===/===/===/===/


    public:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

        Gravity_Rooms();
        ~Gravity_Rooms();

        void executar();

        // ===/===/===/===/ Outros  ===/===/===/===/
        

};



#endif