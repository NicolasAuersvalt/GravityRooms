#ifndef LISTA_ENTIDADES_H
#define LISTA_ENTIDADES_H

#include"Listas/Lista.h"
#include"Entidades/Entidade.h"

class Lista;
class Entidade;

namespace Listas{

    class Lista_Entidades{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Lista<Entidade> LEs;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Lista_Entidades();
            ~Lista_Entidades();
            void incluir(Entidade* pE);
            void percorrer();

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif