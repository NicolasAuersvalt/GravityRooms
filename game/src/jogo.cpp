#include "jogo.h"


Jogo::Jogo()
    :GG(NULL)
{
    // Cria um Gerenciador Grafico;
    GG = new Gerenciador_Grafico();

    // Chama o executar
    executar();
}


Jogo::~Jogo(){



}


void Jogo::executar(){

    // Deve desenhar o mimico criado
    // Criando um objeto Mimico e carregando a textura
    Mimico mimico;
    mimico.carregarTextura("assets/monstro.png");

}