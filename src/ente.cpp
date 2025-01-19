#include "Ente.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/

Gerenciadores::Gerenciador_Grafico* Ente::pGG = nullptr;


// Construtor
Ente::Ente() :
texture(nullptr), id(-1)
{
    cout << "CONSTRUTOR" << endl;
}

// Destrutor
Ente::~Ente(){

    texture = nullptr;

}
void Ente::desenhar(){

    pGG->desenharEnte(this);
    
}

void Ente::setSprite(std::string local, int posX, int posY, int width, int height) {
        if (!texture) {
            texture = new sf::Texture();
        }
        if (!texture->loadFromFile(local, sf::IntRect(posX, posY, width, height))) {
            std::cerr << "Erro ao carregar a textura: " << local << std::endl;
        } else {
            sprite.setTexture(*texture);  // Associa a textura ao sprite
        }
    }

  // Retorna o ponteiro da textura
sf::Texture* Ente::getTexture() {
        return texture;
    }

    // Retorna uma cópia do sprite
sf::Sprite Ente::getSprite() {
        return sprite;
    }

void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico* gg) {
    pGG = gg;
}


    // ===/===/===/===/ Outros  ===/===/===/===/