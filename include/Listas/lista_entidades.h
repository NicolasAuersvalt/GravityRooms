#ifndef LISTA_ENTIDADES_H
#define LISTA_ENTIDADES_H

#include"Listas/lista.h"
#include"Entidades/entidade.h"

#include"Entidades/Personagens/tripulante.h"

#include <iostream>
using namespace std;

using namespace Entidades;

namespace Listas {

    class Lista_Entidades {
    private:
        Lista<Entidade>* LEs;  // Lista de Entidades

    public:
        // Construtor
        Lista_Entidades() {
            //cout << "Construtor de Lista_Entidades" << endl;
            LEs = new Lista<Entidade>();
        }

        // Destruidor
        ~Lista_Entidades() {
            delete LEs;
        }

        // Incluir uma Entidade na lista
        void incluir(Entidade* pE) {
            LEs->incluir(pE);
        }

        // Percorrer todos os elementos da lista e desenhar cada um
        void desenharTodos() {
            //cout << "Desenhando todos os elementos..." << endl;

            LEs->percorrerLista([](Entidade* entidade) {

                entidade->desenhar();  // Chama o método desenhar() de cada Entidade
                
            });
        }
        void atualizarTodas() {
            LEs->percorrerLista([](Entidade* entidade) {
                    entidade->mover();
                
        });
}
    };

}

#endif // LISTA_ENTIDADES_H