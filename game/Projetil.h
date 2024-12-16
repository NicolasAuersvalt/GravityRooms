#ifndef PROJETIL_H
#define PROJETIL_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Projetil {
private:
    int id;
    float x, y;
    float dx, dy;
    sf::RectangleShape projetil; 
    bool ativo;

public:
    Projetil(int id, float x, float y,float dx, float dy);
    ~Projetil();

    void executar();
    bool estaAtivo() const;
    
    void desenhar(sf::RenderWindow& window); // Desenha o projetil na tela
};

#endif // PROJETIL_H
