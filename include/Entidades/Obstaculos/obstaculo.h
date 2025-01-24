#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Entidades/entidade.h"

using namespace sf;

namespace Entidades::Obstaculos{

    class Obstaculo:public Entidade{

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            bool danoso;
            bool colidindo;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Obstaculo(const Vector2f pos, const Vector2f tam);
            ~Obstaculo();
            void salvar();

        
            virtual void executar() = 0;
            virtual void salvarDataBuffer() {
                
            }

            // ===/===/===/===/ Outros  ===/===/===/===/

            bool getColidindo();
            void setColidindo(bool colide);
                

    };

}

#endif