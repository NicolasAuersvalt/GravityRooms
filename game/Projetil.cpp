#include "Projetil.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Carregar a textura uma vez
static sf::Texture projetilTexture;

Projetil::Projetil(int id, float x, float y, float dx, float dy) : id(id), dx(dx), dy(dy), ativo(true) {
    // Verifica se a textura foi carregada corretamente
    if (projetilTexture.getSize().x == 0) {
        // Carregar a textura apenas na primeira vez
        if (!projetilTexture.loadFromFile("projetil.png")) {  // Altere para o caminho correto da sua imagem
            std::cerr << "Erro ao carregar a imagem do projetil!" << std::endl;
            return;
        }
    }

    projetil.setSize(sf::Vector2f(50.0f, 50.0f));  // Tamanho do projetil
    projetil.setTexture(&projetilTexture);          // Atribui a textura carregada
    projetil.setPosition(x, y);                    // Posição inicial
    projetil.setOutlineThickness(0);                // Remove o contorno (borda) do projetil
}

Projetil::~Projetil() {
    std::cout << "Projetil destruído com ID: " << id << "\n";
}

void Projetil::executar() {
    if (ativo) {
        projetil.move(dx, dy);  // Move o projetil conforme a direção

        // Se o projetil sair da tela, torna-se inativo
        if (projetil.getPosition().x < 0 || projetil.getPosition().x > 750 ||
            projetil.getPosition().y < 0 || projetil.getPosition().y > 550) {
            std::cout << "Projetil ID: " << id << " saiu da tela\n";
            ativo = false;
        }
    }
}

bool Projetil::estaAtivo() const {
    return ativo;
}

void Projetil::desenhar(sf::RenderWindow& window) {
    if (ativo) {
        window.draw(projetil);  // Desenha o projetil na janela
    }
}

