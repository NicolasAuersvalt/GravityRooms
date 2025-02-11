#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

// =====/=====/=====/=====/=====/=====/

// Requisitos Conceituais 1.1
// Requisitos Conceituais 3.2
// Requisitos Conceituais 3.3

// =====/=====/=====/=====/=====/=====/

namespace Listas {

template <typename TL> class Lista {
private:
  int tamanho;

public: // Definição da classe aninhada Elemento
  template <typename TE> class Elemento {
  public:
    TE *pInfo;           // Dados do elemento
    Elemento<TE> *pProx; // Ponteiro para o próximo elemento

    // Construtor
    Elemento() : pInfo(nullptr), pProx(nullptr) {}

    // Método para incluir o próximo elemento
    void incluir(TE *p) {
      pInfo = p;
      pProx = nullptr;
    }

    // Obter o elemento
    TE *getElemento() const { return pInfo; }

    // Definir o próximo elemento
    void setProx(Elemento<TE> *pE) { pProx = pE; }

    // Obter o próximo elemento
    Elemento<TE> *getProximo() { return pProx; }
  };

  // Atributos da lista
  Elemento<TL> *pPrimeiro; // Ponteiro para o primeiro elemento
  Elemento<TL> *pUltimo;   // Ponteiro para o último elemento

  void removerElemento(TL *elemento, const bool deletar) {
    if (!elemento) {
      cout << "ERROR::Lista elemento eh nullptr" << endl;
      return;
    }

    Elemento<TL> *aux = pPrimeiro;
    Elemento<TL> *aux2 = nullptr;

    while (aux != nullptr && aux->getElemento() != elemento) {
      aux2 = aux;
      aux = aux->getProximo();
    }

    if (aux && aux->getElemento() == elemento) {
      if (aux == pPrimeiro) {
        pPrimeiro = aux->getProximo();
      } else {
        aux2->setProx(aux->getProximo());
      }

      if (aux == pUltimo) {
        pUltimo = aux2;
      }

      if (deletar) {
        delete aux->pInfo;
        aux->pInfo = nullptr;
      }
      delete aux;
      aux = nullptr;

      tamanho--;
    }
  }

  // Construtor
  Lista() : pPrimeiro(nullptr), pUltimo(nullptr), tamanho(0) {}
  int getTam() const { return tamanho; }

  // Método para limpar a lista
  void limpar() {
    Elemento<TL> *temp;
    while (pPrimeiro != nullptr) {
      temp = pPrimeiro;
      pPrimeiro = pPrimeiro->getProximo();
      delete temp;
    }
    tamanho = 0;
    pUltimo = nullptr;
  }

  // Método para incluir um elemento na lista
  void incluir(TL *p) {
    Elemento<TL> *novoElemento = new Elemento<TL>();
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
  Elemento<TL> *getPrimeiro() { 
    return pPrimeiro; 
  }

  // Método para percorrer a lista e aplicar uma função em cada elemento
  void percorrerLista(void (*funcao)(TL *)) {
    if (!pPrimeiro) {
      return;
    }

    Elemento<TL> *atual = pPrimeiro;
    while (atual != nullptr) {
      // Store next before processing current
      Elemento<TL> *proximo = atual->getProximo();

      if (atual && atual->pInfo) {
        try {
          funcao(atual->pInfo);
        } catch (const exception &e) {
          cerr << "Error in percorrerLista: " << e.what() << endl;
        }
      }
      atual = proximo;
    }
  }
  TL *operator[](int pos) {
    if (pos < 0 || !pPrimeiro)
      return nullptr;

    Elemento<TL> *atual = pPrimeiro;
    int count = 0;

    while (atual && count < pos) {
      atual = atual->pProx;
      count++;
    }

    return atual ? atual->pInfo : nullptr;
  }
};

} // namespace Listas

#endif // LISTA_H
