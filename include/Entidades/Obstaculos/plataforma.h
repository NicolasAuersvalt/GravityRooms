#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Entidades/Obstaculos/obstaculo.h"

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
            void mover() override; 
            void salvar() override;
            // void desenhar(Gerenciador_Grafico pGG) override;
            // void atualizar() override;
            // void colisao(Entidade* outra) override;
    };
}
#endif