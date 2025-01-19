#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Entidades/Obstaculos/Obstaculo.h"

namespace Entidades::Obstaculos {

    class Plataforma : public Obstaculo {
        private:
            int altura;
             

        // ===/===/===/===/ Outros  ===/===/===/===/


    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        
                

        // ===/===/===/===/ Outros  ===/===/===/===/


        public:
            Plataforma();
            ~Plataforma();
            
            void executar() override;
            void mover() const; 

            // void desenhar(Gerenciador_Grafico pGG) override;
            // void atualizar() override;
            // void colisao(Entidade* outra) override;
    };
}
#endif