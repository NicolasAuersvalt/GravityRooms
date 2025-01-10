#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "ente.h"
#include <sstream> // Para o ostringstream

namespace Entidades{

    class Entidade : protected Ente{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int x;
            int y;
            std::ostringstream buffer;


            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Entidade();
            virtual ~Entidade();

            // Métodos Virtuais
            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual void salvarDataBuffer() = 0;

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif