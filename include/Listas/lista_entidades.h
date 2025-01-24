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
        ~Lista_Entidades();
        void incluir(Entidade* pE);
        void desenharTodos();
        void atualizarTodas();
    };
}

#endif