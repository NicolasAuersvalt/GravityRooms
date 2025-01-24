#include "Listas/lista_entidades.h"
#include <iostream>

namespace Listas{
    
    Lista_Entidades::Lista_Entidades() {
            //cout << "Construtor de Lista_Entidades" << endl;
            LEs = new Lista<Entidade>();
        }

        // Destruidor
        Lista_Entidades::~Lista_Entidades() {
            delete LEs;
        }

        // Incluir uma Entidade na lista
        void Lista_Entidades::incluir(Entidade* pE) {
            LEs->incluir(pE);
        }

        // Percorrer todos os elementos da lista e desenhar cada um
        void Lista_Entidades::desenharTodos() {
            //cout << "Desenhando todos os elementos..." << endl;

            LEs->percorrerLista([](Entidade* entidade) {

                entidade->desenhar();  // Chama o método desenhar() de cada Entidade
                
            });
        }
        void Lista_Entidades::atualizarTodas() {
            LEs->percorrerLista([](Entidade* entidade) {
                    entidade->mover();
                
        });
        }

}