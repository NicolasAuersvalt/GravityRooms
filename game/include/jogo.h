#ifndef JOGO_H
#define JOGO_H

#include "gerenciador_grafico.h"
#include "mimico.h"

using namespace Gerenciadores;


class Gerenciador_Grafico;
class Mimico;


class Jogo{

    private:
        // Tripulante pJog1;
        Gerenciador_Grafico GG;
       
        // Temporario
        Mimico inimigo;

    public:
        Jogo();
        ~Jogo();
        void executar();
        
};

#endif