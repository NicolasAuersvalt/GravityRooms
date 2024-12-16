#ifndef JOGO_H
#define JOGO_H

#include "gerenciador_grafico.h"
#include "mimico.h"

class Jogo{

    private:
        // Tripulante pJog1;
        Gerenciadores::Gerenciador_Grafico* GG;
       
        // Temporario
        Mimico inimigo;

    public:
        Jogo();
        ~Jogo();
        void executar();
        
};

#endif