#ifndef PROJETIL_H
#define PROJETIL_H

#include "Entidades/Entidade.h"

namespace Entidades{

    class Projetil : protected Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            bool ativo;


            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Projetil();
            virtual ~Projetil();

            // Métodos Virtuais
            void executar() override;

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif