#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "Fases/Fase.h"

class Fase;

namespace Fases{

    class Laboratorio : protected Fase{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            const int maxChefoes = 1;

            Laboratorio();
            ~Laboratorio();

            void criarChefoes();
            void criarObstMedios();
            void criarProjeteis();


            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };
}


#endif