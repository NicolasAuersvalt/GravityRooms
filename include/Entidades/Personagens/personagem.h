#ifndef PERSONAGEM_H
#define PERSONAGEM_H

namespace Entidades::Personagens{

    class Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            int num_vidas;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Personagem();
            ~Personagem();
            void salvarDataBuffer();
            virtual void mover() = 0;
            virtual void executar() = 0;
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif