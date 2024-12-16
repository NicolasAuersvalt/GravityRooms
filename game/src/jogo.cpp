#include "jogo.h"


Jogo::Jogo()
    : GG()
{
    // Cria um Gerenciador Grafico;

    // Chama o executar
    Jogo::executar();
}


Jogo::~Jogo(){



}


void executar(){

    // Deve desenhar o mimico criado
    // Criando um objeto Mimico e carregando a textura
    Mimico mimico;
    mimico.carregarTextura("assets/monstro.png");

}