#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidades/entidade.h"

namespace Entidades::Personagens{

    class Personagem : public Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float velocidadeY = 0.f;
            float velocidadeX = 0.f;
            int num_vidas;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Personagem(pair<int,int>p, pair<int, int>d);
            ~Personagem();
            void salvar();

            // Métodos Virtuais
            virtual void executar() = 0;
            virtual void salvarDataBuffer(){


            }
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif