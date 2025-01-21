#ifndef JOGADOR_H
#define JOGADOR_H

#include "Entidades/Personagens/Personagem.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Projetil.h"

namespace Entidades::Personagens
{

    class Jogador : public Personagem
    {

    private:
        // ===/===/===/===/ Obrigatório ===/===/===/===/
        int pontos;
        Listas::Lista_Entidades* listaEntidades;

        // ===/===/===/===/ Outros  ===/===/===/===/

    protected:
        // ===/===/===/===/ Obrigatório ===/===/===/===/

        // ===/===/===/===/ Outros  ===/===/===/===/

    public:
        // ===/===/===/===/ Obrigatório ===/===/===/===/

        Jogador();
        ~Jogador();
        void executar() override;

        // ===/===/===/===/ Outros  ===/===/===/===/
        //void setListaEntidades(Listas::Lista_Entidades* lista);
        void salvarDataBuffer();
        void colidir(Entidades::Entidade *e);
        void mover();
        Projetil* atirar();
    };

}

#endif