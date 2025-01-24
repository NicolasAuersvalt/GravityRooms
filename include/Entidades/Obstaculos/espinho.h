#ifndef ESPINHO_H
#define ESPINHO_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos{

    class Espinho : protected Obstaculo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float largura;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Espinho(const sf::Vector2f pos, const sf::Vector2f tam);
            ~Espinho();
            void executar() override;
            void mover() const;

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif