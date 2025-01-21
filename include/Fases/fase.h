#ifndef FASE_H
#define FASE_H

#include "ente.h"
#include "Gerenciadores/gerenciador_colisoes.h"

class Jogo;
class Gerenciador_Colisoes;

namespace Fases{

    class Fase : protected Ente{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            // Gerenciador_Colisoes GC;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Fase();
            ~Fase();

            virtual void executar() = 0;
            void gerenciar_colisoes();
            void cirarInimFaceis();
            void criarPlataformas();

            virtual void criarInimigos() = 0;
            virtual void criarObstaculo() = 0;
            void criarCenario();


            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };
}


#endif