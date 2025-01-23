#ifndef CIBORGUE_H
#define CIBORGUE_H

#include "Entidades/Personagens/inimigo.h"

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
            void danificar(Tripulante* p);
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif