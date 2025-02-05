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
#include "Fases/laboratorio.h"
#include "Fases/nave.h"
#include "Gerenciadores/gerenciador_colisoes.h"
#include "Gerenciadores/gerenciador_eventos.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Gerenciadores/gerenciador_json.h"
#include "Gerenciadores/save.h"
#include "IDs/IDs.h"
#include "Listas/lista_entidades.h"
#include "Menus/menuGameOver.h"
#include "Menus/menuPause.h"
#include "Menus/menuPrincipal.h"
#include "Menus/ranking.h"
#include "ente.h"

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
using Menus::Menu;
using Menus::MenuPause;
using Menus::MenuPrincipal;

// Includes de Fases
using Fases::Fase;
using Fases::Laboratorio;
using Fases::Nave;

// Includes gerais
using namespace std;
using namespace sf;

class Gravity_Rooms {
 private:
  Gerenciador_Grafico GG;
  Gerenciador_Colisoes GC;
  Gerenciador_Eventos GE;
  Fase *fase;
  Menu *menu;
  Save save;

  enum GameState { MAIN, PLAYING, PAUSE, COLOCACAO, GAMEOVER };

  Lista_Entidades listaPersonagem;
  Lista_Entidades listaObstaculo;
  Sprite backgroundSprite;
  Texture backgroundTexture;
  bool player2Active;
  Gerenciador_Eventos *pGE;
  GameState currentState = MAIN;
  int currentPontos;

 protected:
 public:
  Gravity_Rooms();
  ~Gravity_Rooms();
  bool ligarMenu(IDs::IDs pMenu);

  void salvarEntidades(const std::string &nomeArquivo);
  void executar();
  void criarJogadorDois();
  void criarFases(IDs::IDs faseSelecionada);
  void carregarEntidades(const std::string &nomeArquivo);
  Lista_Entidades listaBackgrounds;
};

#endif