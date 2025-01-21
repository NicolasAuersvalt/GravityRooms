#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Entidades/entidade.h"

namespace Entidades::Obstaculos{

    class Obstaculo:public Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            bool danoso;
            bool colidindo;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Obstaculo(pair<int,int>p, pair<int, int>d);
            ~Obstaculo();
            void salvar();

        
            virtual void executar() = 0;
            virtual void salvarDataBuffer() {
                
            }

            // ===/===/===/===/ Outros  ===/===/===/===/

            bool getColidindo(){
                return colidindo;
            }

            void setColidindo(bool colide){
                colidindo = colide;

            }
                

    };

}

#endif