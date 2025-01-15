#ifndef CLONE_H
#define CLONE_H

#include "Entidades/Personagens/inimigo.h"

namespace Entidades::Personagens{

    class Clone : protected Inimigo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float raio;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Clone();
            ~Clone();
            void executar() override;
            void danificar(Jogador* p);

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif