#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include "Entidades/entidade.h"
#include "Entidades/projetil.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Listas/lista_entidades.h"

using Entidades::Projetil;
using Entidades::Obstaculos::Obstaculo;
using Entidades::Personagens::Inimigo;
using Entidades::Personagens::Tripulante;
using Gerenciadores::Gerenciador_Grafico;
using Listas::Lista_Entidades;

using namespace Entidades;

class Obstaculo;

namespace Gerenciadores {

class Gerenciador_Colisoes {
 private:
  vector<Inimigo *> LIs;
  list<Obstaculo *> LOs;
  set<Projetil *> LPs;
  Lista_Entidades *listaPersonagem;
  Lista_Entidades *listaObstaculo;

 public:
  Tripulante *pJog1;
  Tripulante *pJog2;

  void setLista_Entidades(Lista_Entidades *listaPersonagem,
                          Lista_Entidades *listaObstaculo);
  void incluirTripulante(Tripulante &jogador);
  Gerenciador_Colisoes(Lista_Entidades *listaPersonagem,
                       Lista_Entidades *listaObstaculo);
  ~Gerenciador_Colisoes();
  const sf::Vector2f calculaColisao(Entidades::Entidade *ent1,
                                    Entidades::Entidade *ent2);
  void executar(Lista_Entidades *listaPer, Lista_Entidades *listaObs);
};

}  // namespace Gerenciadores

#endif
