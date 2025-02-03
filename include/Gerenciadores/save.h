#ifndef SAVE_H
#define SAVE_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>

#include "Entidades/Personagens/tripulante.h"
#include "Fases/fase.h"
#include "Fases/laboratorio.h"
#include "Fases/nave.h"
#include "Gerenciadores/gerenciador_colisoes.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using namespace sf;
using Fases::Fase;
using Fases::Laboratorio;
using Fases::Nave;
using Gerenciadores::Gerenciador_Colisoes;

class Save {
private:
public:
  Save();
  ~Save();

  void setJogador(Entidades::Personagens::Tripulante *jogador);
  Entidades::Personagens::Tripulante *getJogador();

  void salvar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
              Lista_Entidades &listaObstaculo, Fase &fase);
  void gravarDados();

  bool carregar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                Lista_Entidades &listaObstaculo, Fase *&fase);
};

#endif