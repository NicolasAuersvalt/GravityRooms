#include"Gerenciadores/save.h"

Save::Save(){

}

Save::~Save(){
    
}

void Save::setJogador(Entidades::Personagens::Tripulante* jogador) {
        if (jogador) {
            pJog1 = jogador;
        }
    }

Entidades::Personagens::Tripulante* Save ::getJogador() {
    return pJog1;
}

void Save::salvar()
{
    //json j = getJson(local, pJog1->getPosicao().x, pJog1->getPosicao().y);
    // salvarArquivo(local, j);
}

void Save::carregar()
{
    
    //carregarJson(const std::string& local, arquivoExiste(local))
    //pJog1->setPosicao(Gerenciador_Json::getPos().x, Gerenciador_Json::getPos().y)
}