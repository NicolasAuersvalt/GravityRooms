#ifndef ANDROIDE_H
#define ANDROIDE_H

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

namespace Entidades::Personagens{

    class Androide : public Inimigo{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            //float raio;

            bool movingRight;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
            Androide(const sf::Vector2f pos, Tripulante* tripulante);
            ~Androide();

            using Ente::setSprite;

            void danificar(Tripulante* p)override;

            virtual void executar() override; 
			virtual void salvarDataBuffer(nlohmann::ordered_json& json) override; 
			virtual void mover() override; 

            // ===/===/===/===/ Outros  ===/===/===/===/
         void colidir(Entidade* outro, string  direction= "")override; 

    };

}

#endif