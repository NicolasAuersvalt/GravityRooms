#ifndef CIBORGUE_H
#define CIBORGUE_H

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include <SFML/Graphics.hpp>

namespace Entidades::Personagens{

    class Ciborgue : public Inimigo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int tamanho;

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Ciborgue(const sf::Vector2f pos, Tripulante* tripulante);
            ~Ciborgue();
            void executar() override;
            void danificar(Tripulante* p);
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif