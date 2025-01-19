#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Entidades/Obstaculos/Obstaculo.h"

namespace Entidades::Obstaculos {

    class Plataforma : public Obstaculo {
        private:
            int altura;

        public:
            Plataforma(std::pair<int,int> p = std::make_pair(0,0), 
                      std::pair<int,int> d = std::make_pair(0,0));
            ~Plataforma();
            
            void executar() override;
            void mover() override; // Removed const to match base class


            // void desenhar(Gerenciador_Grafico pGG) override;
            // void atualizar() override;
            // void colisao(Entidade* outra) override;
    };
}
#endif