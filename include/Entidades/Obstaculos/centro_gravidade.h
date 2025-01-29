#ifndef CENTRO_GRAVIDADE_H
#define CENTRO_GRAVIDADE_H

#include "Entidades/Obstaculos/obstaculo.h"

namespace Entidades::Obstaculos {

	class Centro_Gravidade : public Obstaculo {
		private:
			// ===/===/===/===/ Obrigatório ===/===/===/===/
			float forca;

			// ===/===/===/===/ Outros  ===/===/===/===/

		protected:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			// ===/===/===/===/ Outros  ===/===/===/===/

		public:
			// ===/===/===/===/ Obrigatório ===/===/===/===/
			using Ente::setSprite;
			Centro_Gravidade(const sf::Vector2f pos, const sf::Vector2f tam,
					const IDs::IDs ID);
			~Centro_Gravidade();
			void executar() override;
			void mover() override;
			void salvar() override;
			// ===/===/===/===/ Outros  ===/===/===/===/
			void colisao(Entidade* outraEntidade,
					sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
			int getDano();
	};

}  // namespace Entidades::Obstaculos

#endif
