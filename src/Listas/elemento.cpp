// elemento.cpp
#include "Listas/elemento.h"
#include <iostream>

namespace Listas {

    template <typename TE>
    Elemento<TE>::Elemento() : pProx(nullptr) {
        // Inicialização padrão
    }

    template <typename TE>
    Elemento<TE>::~Elemento() {
        // Destruição do objeto, se necessário
    }

    template <typename TE>
    void Elemento<TE>::incluir(TE* p) {
        // Lógica de inclusão, dependendo de como você quer manipular o tipo TE
    }

    template <typename TE>
    void Elemento<TE>::setProx(Elemento<TE>* pE) {
        pProx = pE;  // Definindo o próximo elemento
    }

    template <typename TE>
    const Elemento<TE>* Elemento<TE>::getProximo() const {
        return pProx;  // Retorna o próximo elemento
    }

} 

