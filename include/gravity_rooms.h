#ifndef GRAVITY_ROOMS_H
#define GRAVITY_ROOMS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>

#include "Entidades/Obstaculos/plataforma.h"
#include "Entidades/Personagens/androide.h"
#include "Entidades/Personagens/tripulante.h"
#include "Fases/fase.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Menus/menu.h"
#include "ente.h"

using namespace std;
using namespace sf;

// Temporário
#include "Gerenciadores/gerenciador_colisoes.h"

using Entidades::Obstaculos::Plataforma;
using Entidades::Personagens::Androide;
using Entidades::Personagens::Tripulante;
using Gerenciadores::Gerenciador_Colisoes;
using Gerenciadores::Gerenciador_Grafico;
using Listas::Lista_Entidades;
using Menus::Menu;

class Gravity_Rooms {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Androide pAnd1;
  Androide pAnd2;
  Gerenciador_Grafico GG;
  Gerenciador_Colisoes GC;
  Fases::Fase* fase;
  Menu menuGeral;

  // ===/===/===/===/ Outros  ===/===/===/===/

  Lista_Entidades LJog1;
  Sprite backgroundSprite;

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Gravity_Rooms();
  ~Gravity_Rooms();

  void executar();

  // ===/===/===/===/ Outros  ===/===/===/===/
  void criarFases(int faseSelecionada);
};

#endif