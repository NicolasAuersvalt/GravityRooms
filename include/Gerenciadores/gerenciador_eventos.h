#ifndef GERENCIADOR_EVENTOS
#define GERENCIADOR_EVENTOS

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "Gerenciadores/gerenciador_grafico.h"
#include "Menus/menuPrincipal.h"

using namespace std;
using namespace sf;

using Menus::MenuPrincipal;

namespace Gerenciadores {

	class Gerenciador_Eventos {
		public:
			void processarEventoJanela(Gerenciador_Grafico &GG,
					MenuPrincipal &menuGeral);

			string processarTecla(Keyboard::Key tecla);

			string isTeclaPressionada(const Keyboard::Key tecla);

			Vector2f obterMovimento();
	};
}  // namespace Gerenciadores

#endif
