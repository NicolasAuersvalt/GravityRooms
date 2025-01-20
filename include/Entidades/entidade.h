#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <SFML/Graphics.hpp>

#include "Ente.h"
#include <utility> // Para usar pair
#include <sstream> // Para o ostringstream

class Gerenciador_Grafico;

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
            virtual void mover() = 0;   
            
            pair<int, int>  getPosition(); 
            pair<int, int>  getDirection(); 

            // ===/===/===/===/ Outros  ===/===/===/===/
            
    };

}

#endif