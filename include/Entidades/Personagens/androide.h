#ifndef ANDROIDE_H
#define ANDROIDE_H

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens{

    class Androide : protected Inimigo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float raio;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Androide();
            ~Androide();
            void executar() override;
            void danificar(Jogador* p);

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif