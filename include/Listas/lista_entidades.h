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
        Lista_Entidades();

        // Destruidor
        ~Lista_Entidades();

        // Incluir uma Entidade na lista
        void incluir(Entidade* pE);

        // Percorrer todos os elementos da lista e desenhar cada um
        void desenharTodos();

        void atualizarTodas();

    };

}

#endif // LISTA_ENTIDADES_H