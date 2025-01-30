#ifndef NAVE_H
#define NAVE_H

#include "Fases/fase.h"

using namespace std;
using namespace sf;

//class Fase;

namespace Fases {

	class Nave : public Fase {

		private:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			const int maxInimMedios = 2;

			// ===/===/===/===/ Outros  ===/===/===/===/

		protected:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			// ===/===/===/===/ Outros  ===/===/===/===/

		public:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			Nave(const IDs::IDs ID);
			~Nave();

			void criarInimMedios();
			void criarObstMedios();

			void criarFundo() override;
			void criarMapa() override;

			void desenhar() override;

			// ===/===/===/===/ Outros  ===/===/===/===/
	};
}  // namespace Fases

#endif
