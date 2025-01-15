#include "ente.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/

Gerenciadores::Gerenciador_Grafico* Ente::pGG = nullptr;


// Construtor
Ente::Ente() :
pFig(nullptr), id(-1)
{
    cout << "CONSTRUTOR" << endl;
}

// Destrutor
Ente::~Ente(){

    pFig = nullptr;

}
void Ente::desenhar(){

    cout << "Desenhar" << endl;
    pGG->desenharEnte(this);
    
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
void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico* gg) {
    pGG = gg;
}


    // ===/===/===/===/ Outros  ===/===/===/===/