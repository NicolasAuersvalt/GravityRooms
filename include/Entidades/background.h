#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Entidades/background.h"

using namespace sf;

namespace Entidades {

	class Background : public Entidade {
		protected:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			
			// ===/===/===/===/ Outros  ===/===/===/===/

		public:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			Background(const Vector2f pos, const Vector2f tam,
				const IDs::IDs ID)
				: Entidade(Vector2f(0.0f, 0.0f), Vector2f(0.0f, 0.0f), ID) 
				{
				
					setSprite("assets/nave.png", 50.0f, 50.0f);
					setTamanho(sf::Vector2f(1280.0f, 920.0f));
					setPosicao(50.0f, 50.0f);

            	}

			~Background(){

            }
				

			void mover() override{}
			void salvar() override{}
			void colisao(Entidade* outraEntidade, sf::Vector2f ds) override{}

			// ===/===/===/===/ Outros  ===/===/===/===/

			
	};

}  // namespace Entidades::Obstaculos

#endif
