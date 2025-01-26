#ifndef LISTA_ENTIDADES_H
#define LISTA_ENTIDADES_H

#include <iostream>

#include "Entidades/Personagens/tripulante.h"
#include "Entidades/entidade.h"
#include "Listas/lista.h"

using namespace std;
using namespace Entidades;

namespace Listas {

class Lista_Entidades {
 private:  // Lista de Entidades
  Lista<Entidade> objListaEntidade;

 public:
  Lista<Entidade>* LEs;
  // Construtor
  Lista_Entidades();
  ~Lista_Entidades();
  void incluir(Entidade* pE);
  void desenharTodos();
  void atualizarTodas();
  void limparLista();
};
}  // namespace Listas

#endif