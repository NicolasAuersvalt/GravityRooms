#ifndef CLONE_H
#define CLONE_H

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include <SFML/Graphics.hpp>

namespace Entidades::Personagens{

	class Clone : protected Inimigo{

		private:

			// ===/===/===/===/ Obrigatório ===/===/===/===/
			float raio;



			// ===/===/===/===/ Outros  ===/===/===/===/

		protected:

			// ===/===/===/===/ Obrigatório ===/===/===/===/



			// ===/===/===/===/ Outros  ===/===/===/===/


		public:

			// ===/===/===/===/ Obrigatório ===/===/===/===/

			Clone(const sf::Vector2f pos, Tripulante* tripulante);
			~Clone();
			void executar() override;
			void danificar(Tripulante* p);

			// ===/===/===/===/ Outros  ===/===/===/===/


	};

}

#endif
