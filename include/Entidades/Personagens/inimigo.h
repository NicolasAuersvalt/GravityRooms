#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidades/Personagens/Personagem.h"

class Jogador;

namespace Entidades::Personagens{

    class Inimigo : public Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int nivel_maldade;
            bool movingRight;

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
            
            virtual void executar()= 0;
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            void mover();
            virtual void colidir(Entidade* outro, string  direction = "") = 0; 
    };

}

#endif