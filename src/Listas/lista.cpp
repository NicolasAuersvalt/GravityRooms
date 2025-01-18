/*#include "Listas/lista.h"

#include <iostream>

using namespace std;
using namespace Listas;


namespace Listas {

// === Implementação de Lista ===

// Construtor
template <typename TL>
Lista<TL>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

// Destrutor
template <typename TL>
Lista<TL>::~Lista() {
    limpar();
}

// Método incluir: Adiciona um elemento ao final da lista
template <typename TL>
void Lista<TL>::incluir(TL* p) {
    Elemento<TL>* novo = new Elemento<TL>(); // Cria um novo elemento com o tipo TL
    novo->incluir(p);

    if (!pPrimeiro) {
        pPrimeiro = novo;
        pUltimo = novo;
    } else {
        pUltimo->setProx(novo);
        pUltimo = novo;
    }
}

// Método limpar: Remove todos os elementos
template <typename TL>
void Lista<TL>::limpar() {
    Elemento<TL>* atual = pPrimeiro;

    while (atual) {
        Elemento<TL>* proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }

    pPrimeiro = nullptr;
    pUltimo = nullptr;
}

// === Implementação de Elemento (aninhada) ===

// Construtor
template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>::Elemento() : pProx(nullptr), pInfo(nullptr) {}

// Destrutor
template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>::~Elemento() {
    delete pInfo; // Libera a memória do dado armazenado
}

// Método incluir
template <typename TL>
template <typename TE>
void Lista<TL>::Elemento<TE>::incluir(TE* p) {
    pInfo = p;
}

// Método setProx
template <typename TL>
template <typename TE>
void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pE) {
    pProx = pE;
}

// Método getProximo
template <typename TL>
template <typename TE>
const typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getProximo() const {
    return pProx;
}

} // namespace Listas
*/