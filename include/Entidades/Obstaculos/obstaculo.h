#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Entidades/Entidade.h"

namespace Entidades::Obstaculos{

    class Obstaculo:public Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            bool danoso;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Obstaculo(pair<int,int>p, pair<int, int>d);
            ~Obstaculo();

            virtual void mover() = 0;
            virtual void executar() = 0;
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif