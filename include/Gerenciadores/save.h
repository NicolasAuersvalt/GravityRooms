#ifndef SAVE_H
#define SAVE_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>

#include "Gerenciadores/gerenciador_colisoes.h"
#include "Entidades/Personagens/tripulante.h"
#include "json.hpp"
#include "Fases/laboratorio.h"
#include "Fases/nave.h"
#include "Fases/fase.h"

using json = nlohmann::json;
using namespace std;
using namespace sf;
using Gerenciadores::Gerenciador_Colisoes;
using Fases::Fase;
using Fases::Laboratorio;
using Fases::Nave;



class Save  {
 private:

 public:
  Save();
  ~Save();

  void setJogador(Entidades::Personagens::Tripulante* jogador);
  Entidades::Personagens::Tripulante* getJogador();

  void salvar( Gerenciador_Colisoes& GC,  Lista_Entidades& listaPersonagem,  Lista_Entidades& listaObstaculo,  Fase& fase) ;
  void gravarDados();
  
bool carregar( Gerenciador_Colisoes& GC,  Lista_Entidades& listaPersonagem,  Lista_Entidades& listaObstaculo,  Fase*& fase) ;

};

#endif