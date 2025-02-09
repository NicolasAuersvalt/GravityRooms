#ifndef LISTA_ENTIDADES_H
#define LISTA_ENTIDADES_H

#include <iostream>

#include "Entidades/entidade.h"
#include "Listas/lista.h"

using namespace std;
using namespace Entidades;

namespace Listas {

class Lista_Entidades {
 private:  // Lista de Entidades
  Lista<Entidade> objListaEntidade;

 public:
  Lista<Entidade> *LEs;
  // Construtor
  Lista_Entidades();
  ~Lista_Entidades();
  void incluir(Entidade *pE);
  void desenharTodos();
  void atualizarTodas();
  void limparLista();
  const int getTamanho();
  Entidades::Entidade *operator[](int pos);
  void removerEntidade(Entidade *entidade, const bool deletar);
  Entidade *getElemento(int pos);
  bool contem(Entidade *entidade);
  void juntarListas(Lista_Entidades &other);

  template <typename T>
  bool contemTipo() const {
    if (!LEs) return false;

    auto atual = LEs->getPrimeiro();
    while (atual != nullptr) {
      // Store next pointer before any operations
      auto proximo = atual->getProximo();

      // Check if both the node and its info pointer are valid
      if (atual && atual->pInfo) {
        try {
          // Use typeid first to avoid dynamic_cast on invalid types
          if (typeid(*atual->pInfo) == typeid(T) ||
              dynamic_cast<T *>(atual->pInfo)) {
            return true;
          }
        } catch (const bad_cast &) {
          // Handle invalid cast gracefully
          cerr << "Warning: Invalid cast attempted in contemTipo()"
                    << endl;
        }
      }
      atual = proximo;
    }
    return false;
  }
};
}  // namespace Listas

#endif
