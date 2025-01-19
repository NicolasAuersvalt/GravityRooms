#ifndef ESPINHO_H
#define ESPINHO_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos{

    class Espinho : protected Obstaculo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float largura;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Espinho();
            ~Espinho();
            void executar() override;
            void mover() override;

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif