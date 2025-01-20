#ifndef CIBORGUE_H
#define CIBORGUE_H

#include "Entidades/Personagens/Inimigo.h"

namespace Entidades::Personagens{

    class Ciborgue : protected Inimigo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int tamanho;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Ciborgue();
            ~Ciborgue();
            void executar() override;
            void danificar(Jogador* p);
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif