#include"Gerenciadores/ranking.h"

Ranking::Ranking(){

}

Ranking::~Ranking(){
    
}

void Ranking::setJogador(Entidades::Personagens::Tripulante* jogador) {
        if (jogador) {
            pJog1 = jogador;
        }
    }

Entidades::Personagens::Tripulante* Ranking ::getJogador() {
    return pJog1;
}