#include "ente.h"

Gerenciadores::Gerenciador_Grafico *Ente::pGG = nullptr;

// Construtor
Ente::Ente(const IDs::IDs ID) : ID(ID), texture(nullptr) {}

// Destrutor
Ente::~Ente() { texture = nullptr; }
void Ente::desenhar() { pGG->desenharEnte(this); }

void Ente::setSprite(std::string local, int posX, int posY) {
  if (!texture) {
    texture = new sf::Texture();
  }

  // Tenta carregar a textura inteira, mas com um recorte específico se
  // necessário
  if (!texture->loadFromFile(local)) {
    std::cerr << "Erro ao carregar a textura: " << local << std::endl;
  } else {
    sprite.setTexture(*texture); // Associa a textura ao sprite
    // Se for necessário recortar a imagem para o sprite
  }
}

// Retorna o ponteiro da textura
sf::Texture *Ente::getTexture() { return texture; }

// Retorna uma cópia do sprite
sf::Sprite &Ente::getSprite() { return sprite; }

void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico *gg) { pGG = gg; }

const IDs::IDs Ente::getID() const { return ID; }
