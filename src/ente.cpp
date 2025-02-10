#include "ente.h"

Gerenciadores::Gerenciador_Grafico *Ente::pGG = nullptr;

// Construtor
Ente::Ente(const IDs::IDs ID) : ID(ID), texture(nullptr) {}

// Destrutor
Ente::~Ente() { texture = nullptr; }
void Ente::desenhar() { pGG->desenharEnte(this); }

void Ente::setSprite(string local, int posX, int posY) {
  if (!texture) {
    texture = new Texture();
  }

  // Tenta carregar a textura inteira, mas com um recorte específico se
  // necessário
  if (!texture->loadFromFile(local)) {
    cerr << "Erro ao carregar a textura: " << local << endl;
  } else {
    sprite.setTexture(*texture); // Associa a textura ao sprite
    // Se for necessário recorta a imagem para o sprite
  }
}

// Retorna o ponteiro da textura
Texture *Ente::getTexture() { return texture; }

// Retorna uma cópia do sprite
Sprite &Ente::getSprite() { return sprite; }

void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico *gg) { pGG = gg; }

const IDs::IDs Ente::getID() const { return ID; }
