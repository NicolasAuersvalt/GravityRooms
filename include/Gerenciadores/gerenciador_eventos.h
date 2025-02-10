#ifndef GERENCIADOR_EVENTOS_H
#define GERENCIADOR_EVENTOS_H

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

// =====/=====/=====/=====/=====/=====/

// Requisitos Conceituais 1.1
// Requisitos Conceituais 1.2
// Requisitos Conceituais 6.4

// =====/=====/=====/=====/=====/=====/

namespace Gerenciadores {

class Gerenciador_Eventos {
public:
  void processarEventoJanela(Gerenciador_Grafico &GG, MenuPrincipal &menuGeral);
  string processarTecla(Keyboard::Key tecla);
  string isTeclaPressionada(const Keyboard::Key tecla);
  Vector2f obterMovimento();
};
} // namespace Gerenciadores

#endif
