#include "Listas/Lista_Entidades.h"

#include <iostream>

using namespace std;
using namespace Listas;

namespace Listas
{

    Lista_Entidades::Lista_Entidades()
    {
        LEs = new Lista<Entidade>();
    }

    Lista_Entidades::~Lista_Entidades()
    {
        delete LEs;
    }
    void Lista_Entidades::incluir(Entidade *pE)
    {
        LEs->incluir(pE);
    }
    void Lista_Entidades::desenharTodos()
    {
        LEs->percorrerLista([](Entidade *entidade)
                            {
                                // cout << "Desenhando todos os elementos..." << endl;

                                entidade->desenhar(); // Chama o método desenhar() de cada Entidade
                            });
    }
    void Lista_Entidades::atualizarTodas()
    {
        LEs->percorrerLista([](Entidade *entidade)
                            { entidade->mover(); });
    }
}