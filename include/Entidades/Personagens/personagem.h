#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidades/Entidade.h"

namespace Entidades::Personagens{

    class Personagem : public Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            int num_vidas;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

            int vel;
            bool vivo;


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Personagem(pair<int,int>p, pair<int, int>d);
            ~Personagem();
            void salvar();

            // Métodos Virtuais
            virtual void executar() = 0;
            virtual void salvarDataBuffer()=0;
            virtual void mover() = 0;
            virtual void colidir(Entidades::Entidade* e) = 0;

            // ===/===/===/===/ Outros  ===/===/===/===/
            void setVida(const int n);
            const int getVida() const;
            bool getVivo();            

            

    };

}

#endif