#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include "stdafx.h"

class BiblioGrafica;
class Ente;

class Gerenciador_Grafico{


    private:

        // Obrigatório

        BiblioGrafica obj;

        // Outros

    protected:

        // Obrigatório


        // Outros 

        
    public:

        // Obrigatórios

           // Construtor (FALTA)
        Gerenciador_Grafico();

            // Destrutor (FALTA)
        ~Gerenciador_Grafico();

        void desenharEnte(Ente *pE);

        // Outros  


};


#endif
