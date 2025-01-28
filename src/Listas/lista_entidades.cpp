#include "Listas/lista_entidades.h"

#include <iostream>

namespace Listas {

Lista_Entidades::Lista_Entidades() {
  // cout << "Construtor de Lista_Entidades" << endl;
  LEs = new Lista<Entidade>();
}

// Destruidor
Lista_Entidades::~Lista_Entidades() {
  delete LEs;
  limparLista();
}

// Incluir uma Entidade na lista
void Lista_Entidades::incluir(Entidade* pE) { LEs->incluir(pE); }

// Percorrer todos os elementos da lista e desenhar cada um
void Lista_Entidades::desenharTodos() {
  // cout << "Desenhando todos os elementos..." << endl;

  LEs->percorrerLista([](Entidade* entidade) {
    entidade->desenhar();  // Chama o método desenhar() de cada Entidadep
  });
}
void Lista_Entidades::atualizarTodas() {
  LEs->percorrerLista([](Entidade* entidade) { entidade->mover(); });
}
// void Lista_Entidades::limparLista() { objListaEntidade.limpar(); }
// const int Lista_Entidades::getTamanho() {
//   return objListaEntidade.getTamanho();
// }

// Entidades::Entidade* Listas::Lista_Entidades::operator[](int pos) {
//   return objListaEntidade.operator[](pos);
// }
void Lista_Entidades::limparLista() { LEs->limpar(); }

const int Lista_Entidades::getTamanho() { return LEs->getTam(); }

Entidades::Entidade* Listas::Lista_Entidades::operator[](int pos) {
  return LEs->operator[](pos);
}

}  // namespace Listas
