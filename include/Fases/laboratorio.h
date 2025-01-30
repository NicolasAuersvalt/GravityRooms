#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "Fases/fase.h"

using namespace std;
using namespace sf;

namespace Fases {

	class Laboratorio : public Fase {
		private:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			// ===/===/===/===/ Outros  ===/===/===/===/
			Sprite backgroundSprite;
			Texture bgTexture;

		protected:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			// ===/===/===/===/ Outros  ===/===/===/===/

		public:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			const int maxChefoes = 1;

			Laboratorio(const IDs::IDs ID);
			~Laboratorio();

			void criarProjeteis();

			void criarFundo() override;
			void desenhar() override;
			void criarMapa() override;

			// ===/===/===/===/ Outros  ===/===/===/===/
	};
}  // namespace Fases

#endif
