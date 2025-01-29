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
#include "Gerenciadores/gerenciador_eventos.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Listas/lista_entidades.h"
#include "Menus/MenuPrincipal.h"
#include "ente.h"

using namespace std;
using namespace sf;

// Temporário
#include "Gerenciadores/gerenciador_colisoes.h"

using Entidades::Obstaculos::Plataforma;
using Entidades::Personagens::Androide;
using Entidades::Personagens::Tripulante;
using Gerenciadores::Gerenciador_Colisoes;
using Gerenciadores::Gerenciador_Eventos;
using Gerenciadores::Gerenciador_Grafico;
using Listas::Lista_Entidades;
using Menus::MenuPrincipal;

class Gravity_Rooms {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Gerenciador_Grafico GG;
  Gerenciador_Colisoes GC;
  Gerenciador_Eventos GE;
  Fases::Fase* fase;
  MenuPrincipal menuGeral;

  // ===/===/===/===/ Outros  ===/===/===/===/

  Lista_Entidades listaPersonagem;
  Lista_Entidades listaObstaculo;
  Sprite backgroundSprite;

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Gravity_Rooms();
  ~Gravity_Rooms();
  bool ligarMenu();
  void executar();

  // ===/===/===/===/ Outros  ===/===/===/===/
  void criarFases(IDs::IDs faseSelecionada);
};

#endif