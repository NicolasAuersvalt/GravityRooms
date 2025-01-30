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
#include "Gerenciadores/gerenciador_eventos.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Listas/lista_entidades.h"
#include "Menus/menuPrincipal.h"
#include "Fases/laboratorio.h"
#include "Fases/fase.h"
#include "Fases/nave.h"
#include "ente.h"
#include "Gerenciadores/gerenciador_colisoes.h"

#include "IDs/IDs.h"

using namespace std;
using namespace sf;

// Includes do projeto
using Entidades::Obstaculos::Plataforma;
using Entidades::Personagens::Androide;
using Entidades::Personagens::Tripulante;

// Includes de Gerenciadores
using Gerenciadores::Gerenciador_Colisoes;
using Gerenciadores::Gerenciador_Eventos;
using Gerenciadores::Gerenciador_Grafico;

// Includes de Listas e Menus
using Listas::Lista_Entidades;
using Menus::MenuPrincipal;

// Includes de Fases
using Fases::Laboratorio;
using Fases::Nave;
using Fases::Fase;

// Includes gerais
using namespace std;
using namespace sf;


class Gravity_Rooms {
  
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Gerenciador_Grafico GG;
  Gerenciador_Colisoes GC;
  Gerenciador_Eventos GE;
  Fase* fase;
  MenuPrincipal menuGeral;

  // ===/===/===/===/ Outros  ===/===/===/===/

  Lista_Entidades listaPersonagem;
  Lista_Entidades listaObstaculo;
  Sprite backgroundSprite;
  Texture backgroundTexture;

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