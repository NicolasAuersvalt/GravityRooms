#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "ente.h"
#include <SFML/Graphics.hpp>

#include <utility> // Para usar pair
 
#include <sstream> // Para o ostringstream

namespace Entidades{

    class Entidade : public Ente{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            


            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            pair<int, int> pos; // Posição (x,y)
            pair<int, int> dim; // Dimensão (x,y)

            std::ostringstream buffer;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Entidade(pair<int,int>p, pair<int,int>d); // COM PARAMETRO
            virtual ~Entidade();

            // Métodos Virtuais
            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual void salvarDataBuffer(); // PODE SOBRESCREVER SE QUISER

            // ===/===/===/===/ Outros  ===/===/===/===/
            
    };

}

#endif