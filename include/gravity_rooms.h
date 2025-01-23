#ifndef GRAVITY_ROOMS_H
#define GRAVITY_ROOMS_H

#include"Listas/lista_entidades.h"
#include"Entidades/Personagens/tripulante.h"
#include "Entidades/Personagens/androide.h"
#include "Entidades/Obstaculos/plataforma.h"
#include "Gerenciadores/gerenciador_grafico.h"

// Temporário
#include "Gerenciadores/gerenciador_colisoes.h"
using Gerenciadores::Gerenciador_Colisoes;
// Temporário

using Entidades::Obstaculos::Plataforma;

using Entidades::Personagens::Tripulante;
using Entidades::Personagens::Androide;

using Gerenciadores::Gerenciador_Grafico;
using Listas::Lista_Entidades;



class Gravity_Rooms
{

private:
    // ===/===/===/===/ Obrigatório ===/===/===/===/

    Tripulante pJog1;
    Androide pAnd1;
    Androide pAnd2;
    Plataforma plataforma;
    Gerenciador_Grafico GG;
    Gerenciador_Colisoes GC;

    // ===/===/===/===/ Outros  ===/===/===/===/
    Lista_Entidades LJog1;
    sf::Sprite backgroundSprite;

protected:
    // ===/===/===/===/ Obrigatório ===/===/===/===/

    // ===/===/===/===/ Outros  ===/===/===/===/

public:
    // ===/===/===/===/ Obrigatório ===/===/===/===/

    Gravity_Rooms();
    ~Gravity_Rooms();

    void executar();

    // ===/===/===/===/ Outros  ===/===/===/===/
};

#endif