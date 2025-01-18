/*#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "Listas/lista.h"

namespace Listas {  // Mantendo dentro do namespace Listas

    template <typename TE>

    class Elemento {

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Elemento<TE>* pProx;  // Ponteiro para o próximo elemento
            TE* pinfo;  // Ponteiro para o tipo de dado

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

        

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Elemento();  // Construtor
            ~Elemento();  // Destruidor

            void incluir(TE* p);
            void setProx(Elemento<TE>* pE);
            const Elemento<TE>* getProximo() const;

            // ===/===/===/===/ Outros  ===/===/===/===/

    };

}

#endif
*/