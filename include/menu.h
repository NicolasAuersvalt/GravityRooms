#ifndef MENU_H
#define MENU_H

#include "Ente.h"

class Jogo;

class Menu : protected Ente{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

        Jogo* pJog;
                

        // ===/===/===/===/ Outros  ===/===/===/===/

    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        
                

        // ===/===/===/===/ Outros  ===/===/===/===/


    public:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

        Menu();
        ~Menu();

        void executar() override;

        // ===/===/===/===/ Outros  ===/===/===/===/
        

};



#endif