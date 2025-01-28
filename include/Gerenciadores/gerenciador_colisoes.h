#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include "Entidades/projetil.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Listas/lista_entidades.h"
// Precisa conhecer entidade
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "Entidades/entidade.h"

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
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  vector<Inimigo*> LIs;
  list<Obstaculo*> LOs;
  set<Projetil*> LPs;
  Lista_Entidades* listaPersonagem;
  Lista_Entidades* listaObstaculo;
  // ===/===/===/===/ Outros ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatórios ===/===/===/===/

  Tripulante* pJog1;
  // // Construtor (FALTA)
  // Gerenciador_Colisoes();

  // // Destrutor (FALTA)
  // ~Gerenciador_Colisoes();
  void setLista_Entidades(Lista_Entidades* listaPersonagem,
                          Lista_Entidades* listaObstaculo) {
    this->listaPersonagem = listaPersonagem;
    this->listaObstaculo = listaObstaculo;
  }
  // const bool verificarColisao(Entidade *pe1, Entidade *pe2);
  // void tratarColisoesJogsObstacs();
  // void tratarColisoesJogsInimgs();
  // void ColisoesJogsProjeteis();
  // void incluirInimigo(Inimigo *pi);
  // void incluirObstaculo(Obstaculo *po);
  // void incluirProjetil(Projetil *pj);
  // void executar();

  // // ===/===/===/===/ Outros  ===/===/===/===/

  // void incluirTripulante(Tripulante &Tripulante) { pJog1 = &Tripulante; }
  /*------------------------------------------------------------------------------------------------*/
  Gerenciador_Colisoes(Lista_Entidades* listaPersonagem,
                       Lista_Entidades* listaObstaculo);
  ~Gerenciador_Colisoes();
  const sf::Vector2f calculaColisao(Entidades::Entidade* ent1,
                                    Entidades::Entidade* ent2);
  void executar(Lista_Entidades* listaPer, Lista_Entidades* listaObs);

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros ===/===/===/===/
};

}  // namespace Gerenciadores

#endif
