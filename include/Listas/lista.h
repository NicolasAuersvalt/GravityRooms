#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

namespace Listas {

template <typename TL>
class Lista {
 private:
  int tamanho;

 public:  // Definição da classe aninhada Elemento
  template <typename TE>
  class Elemento {
   public:
    TE* pInfo;            // Dados do elemento
    Elemento<TE>* pProx;  // Ponteiro para o próximo elemento

    // Construtor
    Elemento() : pInfo(nullptr), pProx(nullptr) {
      // cout << "Construtor de Elemento" << endl;
    }

    // Método para incluir o próximo elemento
    void incluir(TE* p) {
      // cout << "Incluido com Sucesso" << endl;
      pInfo = p;
      pProx = nullptr;
    }

    // Obter o elemento
    TE* getElemento() const { return pInfo; }

    // Definir o próximo elemento
    void setProx(Elemento<TE>* pE) { pProx = pE; }

    // Obter o próximo elemento
    Elemento<TE>* getProximo() { return pProx; }
  };

  // Atributos da lista
  Elemento<TL>* pPrimeiro;  // Ponteiro para o primeiro elemento
  Elemento<TL>* pUltimo;    // Ponteiro para o último elemento

  void removerElemento(TL* elemento, const bool deletar) {
    if (elemento == nullptr) {
      std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
      exit(1);
    }
    Elemento<TL>* aux = pPrimeiro;
    Elemento<TL>* aux2 = nullptr;
    while (aux != nullptr && aux->getElemento() != elemento) {
      aux2 = aux;
      aux = aux->getProximo();
    }
    if (aux && aux->getElemento() == elemento) {
      if (aux == pPrimeiro) {
        pPrimeiro = aux->getProximo();
      } else if (aux == pUltimo) {
        pUltimo = aux2;
      } else {
        aux2->setProx(aux->getProximo());
      }
      if (deletar) {
        delete (aux);
      }
      tamanho--;
    }
  };
  void removerElemento(int pos, const bool deletar) {
    TL* elemento = operator[](pos);
    return removerElemento(elemento, deletar);
  };

  // Construtor
  Lista() : pPrimeiro(nullptr), pUltimo(nullptr), tamanho(0) {
    // cout << "Construtor de Lista" << endl;
  }
  int getTam() const { return tamanho; }

  // Método para limpar a lista
  void limpar() {
    // cout << "Limpando Lista..." << endl;
    Elemento<TL>* temp;
    while (pPrimeiro != nullptr) {
      temp = pPrimeiro;
      pPrimeiro = pPrimeiro->getProximo();
      delete temp;
    }
    tamanho = 0;
    pUltimo = nullptr;
  }

  // Método para incluir um elemento na lista
  void incluir(TL* p) {
    // cout << "Incluindo elemento na lista" << endl;
    Elemento<TL>* novoElemento = new Elemento<TL>();
    novoElemento->incluir(p);
    if (pUltimo != nullptr) {
      pUltimo->setProx(novoElemento);
    }
    pUltimo = novoElemento;
    if (pPrimeiro == nullptr) {
      pPrimeiro = novoElemento;
    }
    tamanho++;
  }

  // Método para obter o primeiro elemento
  Elemento<TL>* getPrimeiro() { return pPrimeiro; }

  // Método para percorrer a lista e aplicar uma função em cada elemento
  void percorrerLista(void (*funcao)(TL*)) {
    // cout << "Percorrendo a Lista..." << endl;

    Elemento<TL>* elem = pPrimeiro;
    while (elem != nullptr) {
      funcao(elem->pInfo);
      elem = elem->getProximo();
    }
  }
  TL* operator[](int pos) {
    if (pos < 0 || !pPrimeiro) return nullptr;

    Elemento<TL>* atual = pPrimeiro;
    int count = 0;

    while (atual && count < pos) {
      atual = atual->pProx;
      count++;
    }

    return atual ? atual->pInfo : nullptr;
  }
};
// template <class TL>
// TL* Lista<TL>::operator[](int pos) {
//   if (pos >= (int)tam || pos < 0) {
//     std::cout << "ERROR::Lista pos eh maior que o tamanho da lista"
//               << std::endl;
//     exit(1);
//   }
//   Elemento<TL>* aux = pPrimeiro;
//   for (int i = 0; i < pos; i++) {
//     aux = aux->getProx();
//   }
//   return aux->getElemento();
// }
}  // namespace Listas

#endif  // LISTA_H
