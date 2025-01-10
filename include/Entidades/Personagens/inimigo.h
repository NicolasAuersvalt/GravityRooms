#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidades/Personagens/personagem.h"

class Jogador;

namespace Entidades::Personagens{

    class Inimigo : protected Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int nivel_maldade;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Inimigo();
            ~Inimigo();
            void salvarDataBuffer();
            virtual void danificar(Jogador* p) = 0;

            virtual void executar() override;
            virtual void mover() override;
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif