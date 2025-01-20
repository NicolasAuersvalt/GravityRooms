#ifndef ANDROIDE_H
#define ANDROIDE_H

#include "Entidades/Personagens/Inimigo.h"

namespace Entidades::Personagens
{

    class Androide : public Inimigo
    {

    private:
        // ===/===/===/===/ Obrigatório ===/===/===/===/
        float raio;

        // ===/===/===/===/ Outros  ===/===/===/===/
        const float MOVE_SPEED = 5.0f;

    protected:
        // ===/===/===/===/ Obrigatório ===/===/===/===/

        // ===/===/===/===/ Outros  ===/===/===/===/

    public:
        // ===/===/===/===/ Obrigatório ===/===/===/===/
        using Ente::setSprite;
        Androide();
        ~Androide();
        void executar() override;
        void danificar(Jogador* p) override;
        void mover() override;

        // ===/===/===/===/ Outros  ===/===/===/===/
        void colidir(Entidade *outro, string direction);
        void salvar() override;
    };

}

#endif