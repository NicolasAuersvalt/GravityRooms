#ifndef JOGADOR_H
#define JOGADOR_H

#include "Entidades/Personagens/personagem.h"

namespace Entidades::Personagens{

    class Jogador : public Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Jogador();
            ~Jogador();
            void executar() override;  
  

            // ===/===/===/===/ Outros  ===/===/===/===/

            void mover();
            
    };

}

#endif