#ifndef GRAVITY_ROOMS_H
#define GRAVITY_ROOMS_H

#include"Listas/lista.h"
#include"Entidades/Personagens/jogador.h"
#include"Gerenciadores/gerenciador_grafico.h"

class Lista;
class Jogador;
class Gerenciador_Grafico;


class Gravity_Rooms{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

        //Jogador pJog1;
        //Gerenciador_Grafico GG;
                

        // ===/===/===/===/ Outros  ===/===/===/===/

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