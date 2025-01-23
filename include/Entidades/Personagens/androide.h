#ifndef ANDROIDE_H
#define ANDROIDE_H

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens{

    class Androide : public Inimigo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float raio;

            bool movingRight;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            using Ente::setSprite;
            
            Androide();
            ~Androide();

            void executar() override;
            void danificar(Tripulante* p);
            void mover();

            // ===/===/===/===/ Outros  ===/===/===/===/
         void colidir(Entidade* outro, string  direction); 

    };

}

#endif