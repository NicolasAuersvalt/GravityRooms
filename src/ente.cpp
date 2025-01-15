#include "ente.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Ente::Ente() 
: pFig(nullptr), id(-1) // id (-1) pois não fará sentido id negativo no jogo
{

}

// Destrutor
Ente::~Ente(){

    pFig = NULL;

}

void Ente::setSprite(std::string local) {
    if (!pFig) {
        pFig = new sf::Texture(); // Aloca memória para o ponteiro, se necessário
    }
    if (!pFig->loadFromFile(local)) {
        std::cerr << "Erro ao carregar a textura: " << local << std::endl;
    }
}

sf::Texture* Ente::getFig() {
        return pFig;
}

    // ===/===/===/===/ Outros  ===/===/===/===/