#ifndef OBSTACULO_H
#define OBSTACULO_H

class Jogador;

namespace Entidades::Obstaculos{

    class Obstaculo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            bool danoso;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Obstaculo();
            ~Obstaculo();

            virtual void mover() = 0;
            virtual void executar() = 0;
            
            virtual void obstacular(Jogador* p) = 0;

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif