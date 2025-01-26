#ifndef FASE_H
#define FASE_H

<<<<<<< HEAD
#include "Gerenciadores/gerenciador_colisoes.h"
#include "Listas/lista_entidades.h"
=======
>>>>>>> parent of 05a9e64 (fase de inicio)
#include "ente.h"
#include "Gerenciadores/gerenciador_colisoes.h"

class Jogo;
class Gerenciador_Colisoes;

namespace Fases{

    class Fase : protected Ente{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

<<<<<<< HEAD
  // ===/===/===/===/ Outros  ===/===/===/===/
  Gerenciadores::Gerenciador_Colisoes GC;
  Listas::Lista_Entidades* listaPersonagens;
  Listas::Lista_Entidades* listaObstaculos;
  Gerenciadores::Gerenciador_Colisoes* pColisao;
=======
            // Gerenciador_Colisoes GC;
                    
>>>>>>> parent of 05a9e64 (fase de inicio)

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