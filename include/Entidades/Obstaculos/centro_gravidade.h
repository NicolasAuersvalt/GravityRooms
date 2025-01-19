#ifndef CENTRO_GRAVIDADE_H
#define CENTRO_GRAVIDADE_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos{

    class Centro_Gravidade : protected Obstaculo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float forca;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Centro_Gravidade();
            ~Centro_Gravidade();
            void executar() override;
            void mover() const;

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif