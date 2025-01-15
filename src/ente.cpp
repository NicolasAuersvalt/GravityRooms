#include "ente.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/


// Construtor
Ente::Ente() :
pFig(nullptr), id(-1)
{

}

// Destrutor
Ente::~Ente(){

    pFig = nullptr;

}
void Ente::desenhar(){


}

void Ente::setSprite(std::string local, int posX, int posY, int width, int height) {
        if (!pFig) {
            pFig = new sf::Texture(); // Aloca memória para o ponteiro, se necessário
        }
        if (!pFig->loadFromFile(local, sf::IntRect(posX, posY, width, height))) {
            std::cerr << "Erro ao carregar a textura: " << local << std::endl;
        }
    }

sf::Texture* Ente::getFig() {
        return pFig;
}


    // ===/===/===/===/ Outros  ===/===/===/===/