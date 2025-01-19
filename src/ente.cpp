#include "ente.h"
#include<iostream>
// ===/===/===/===/ Obrigatório ===/===/===/===/

Gerenciadores::Gerenciador_Grafico* Ente::pGG = nullptr;


// Construtor
Ente::Ente() :
texture(nullptr), id(-1)
{
    //cout << "CONSTRUTOR" << endl;
}

// Destrutor
Ente::~Ente(){

    texture = nullptr;

}
void Ente::desenhar(){

    //cout << "Hora de Desenhar" << endl;
    pGG->desenharEnte(this);
    
}

void Ente::setSprite(std::string local, int posX, int posY) {
    if (!texture) {
        texture = new sf::Texture();
    }

    // Tenta carregar a textura inteira, mas com um recorte específico se necessário
    if (!texture->loadFromFile(local)) {
        std::cerr << "Erro ao carregar a textura: " << local << std::endl;
    } else {
        sprite.setTexture(*texture);  // Associa a textura ao sprite

        // Se for necessário recortar a imagem para o sprite
        sf::IntRect rect(posX, posY, texture->getSize().x - posX, texture->getSize().y - posY);
        sprite.setTextureRect(rect);  // Define o recorte do sprite
    }
}


  // Retorna o ponteiro da textura
sf::Texture* Ente::getTexture() {
        return texture;
    }

    // Retorna uma cópia do sprite
sf::Sprite& Ente::getSprite() {
        return sprite;
    }

void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico* gg) {
    pGG = gg;
}


    // ===/===/===/===/ Outros  ===/===/===/===/