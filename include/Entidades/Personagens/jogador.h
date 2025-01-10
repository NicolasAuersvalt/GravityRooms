#ifndef JOGADOR_H
#define JOGADOR_H

#include "Entidades/Personagens/personagem.h"

namespace Entidades::Personagens{

    class Jogador : protected Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int pontos;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Jogador();
            ~Jogador();
            void executar() override;
            void mover() override;
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif