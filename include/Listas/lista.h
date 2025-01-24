#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

namespace Listas {

    template <typename TL>
    class Lista {
    public:

        // Definição da classe aninhada Elemento
        template <typename TE>
        class Elemento {
            
        public:
            TE* pInfo;             // Dados do elemento
            Elemento<TE>* pProx;   // Ponteiro para o próximo elemento

            // Construtor
            Elemento() : pInfo(nullptr), pProx(nullptr) {
                //cout << "Construtor de Elemento" << endl;

            }

            // Método para incluir o próximo elemento
            void incluir(TE* p) {
                //cout << "Incluido com Sucesso" << endl;
                pInfo = p;
                pProx = nullptr;
            }

            // Definir o próximo elemento
            void setProx(Elemento<TE>* pE) {
                pProx = pE;
            }

            // Obter o próximo elemento
            Elemento<TE>* getProximo() {
                return pProx;
            }
        };

        // Atributos da lista
        Elemento<TL>* pPrimeiro;  // Ponteiro para o primeiro elemento
        Elemento<TL>* pUltimo;    // Ponteiro para o último elemento

        // Construtor
        Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {
            //cout << "Construtor de Lista" << endl;
        }

        // Método para limpar a lista
        void limpar() {
            //cout << "Limpando Lista..." << endl;
            Elemento<TL>* temp;
            while (pPrimeiro != nullptr) {
                temp = pPrimeiro;
                pPrimeiro = pPrimeiro->getProximo();
                delete temp;
            }
            pUltimo = nullptr;
        }

        // Método para incluir um elemento na lista
        void incluir(TL* p) {
            //cout << "Incluindo elemento na lista" << endl;
            Elemento<TL>* novoElemento = new Elemento<TL>();
            novoElemento->incluir(p);
            if (pUltimo != nullptr) {
                pUltimo->setProx(novoElemento);
            }
            pUltimo = novoElemento;
            if (pPrimeiro == nullptr) {
                pPrimeiro = novoElemento;
            }
        }

        // Método para obter o primeiro elemento
        Elemento<TL>* getPrimeiro() {
            return pPrimeiro;
        }

        // Método para percorrer a lista e aplicar uma função em cada elemento
        void percorrerLista(void (*funcao)(TL*)) {
            //cout << "Percorrendo a Lista..." << endl;

            Elemento<TL>* elem = pPrimeiro;
            while (elem != nullptr) {

                funcao(elem->pInfo);
                elem = elem->getProximo();

            }
        }
    };

}

#endif // LISTA_H
