#ifndef LISTA_H
#define LISTA_H

#include "Listas/elemento.h"

class Elemento;

namespace Listas{

    template <typename TL>

    class Lista{

        private:

            // Elemento<TL>* pPrimeiro;
            // Elemento<TL>* pUltimo;

        // ===/===/===/===/ Obrigatório ===/===/===/===/

            

        // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

        public:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
            Lista();
            ~Lista();

            void incluir(TL *p);
            void limpar();                

        // ===/===/===/===/ Outros  ===/===/===/===/

    };

}
#endif