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

using namespace std;
using namespace sf;

using json = nlohmann::json;
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
              Lista_Entidades &listaObstaculo,
              Lista_Entidades &listaBackgrounds, Fase *&fase,
              const string &nomeArquivo);

  void gravarDados();
  bool carregar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                Lista_Entidades &listaObstaculo,
                Lista_Entidades &listaBackgrounds, Fase *&fase,
                const string &nomeArquivo);
};

#endif