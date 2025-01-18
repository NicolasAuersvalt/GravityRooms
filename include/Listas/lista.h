#ifndef LISTA_H
#define LISTA_H

namespace Listas {

    template <typename TL>
    class Lista {

        private:

            template <typename TE>
            class Elemento {
                private:
                    Elemento<TE>* pProx;
                    TE* pInfo;

                public:
                    Elemento();  // Construtor
                    ~Elemento(); // Destruidor

                    void incluir(TE* p);
                    void setProx(Elemento<TE>* pE);
                    const Elemento<TE>* getProximo() const;
            };

            Elemento<TL>* pPrimeiro;
            Elemento<TL>* pUltimo;

        public:
            Lista();
            ~Lista();

            void incluir(TL* p);
            void limpar();
    };

    // Implementação dos métodos de Lista
    template <typename TL>
    Lista<TL>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

    template <typename TL>
    Lista<TL>::~Lista() {
        limpar();
    }

    template <typename TL>
    void Lista<TL>::incluir(TL* p) {
        Elemento<TL>* novo = new Elemento<TL>(); // Cria um novo elemento
        novo->incluir(p);

        if (!pPrimeiro) {
            pPrimeiro = novo;
            pUltimo = novo;
        } else {
            pUltimo->setProx(novo);
            pUltimo = novo;
        }
    }

    template <typename TL>
void Lista<TL>::limpar() {
    Elemento<TL>* atual = pPrimeiro;

    while (atual) {
        const Elemento<TL>* proximo = atual->getProximo();  // Modifique para const
        delete atual;
        atual = const_cast<Elemento<TL>*>(proximo);  // Converter o const de volta, se necessário
    }

    pPrimeiro = nullptr;
    pUltimo = nullptr;
}


    // Implementação dos métodos de Elemento
    template <typename TL>
    template <typename TE>
    Lista<TL>::Elemento<TE>::Elemento() : pProx(nullptr), pInfo(nullptr) {}

    template <typename TL>
    template <typename TE>
    Lista<TL>::Elemento<TE>::~Elemento() {
        delete pInfo;
    }

    template <typename TL>
    template <typename TE>
    void Lista<TL>::Elemento<TE>::incluir(TE* p) {
        pInfo = p;
    }

    template <typename TL>
    template <typename TE>
    void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pE) {
        pProx = pE;
    }

    template <typename TL>
    template <typename TE>
    const typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getProximo() const {
        return pProx;
    }

}

#endif // LISTA_H
