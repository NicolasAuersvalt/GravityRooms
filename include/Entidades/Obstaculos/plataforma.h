#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos{

    class Plataforma : protected Obstaculo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int altura;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Plataforma();
            ~Plataforma();
            void executar() override;
            void mover() override;
            void danificar(Jogador* p);

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif