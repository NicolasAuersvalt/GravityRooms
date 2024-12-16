#ifndef MIMICO_H
#define MIMICO_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Jogador; // Declaração antecipada para Jogador (não definida ainda)

class Mimico : public Ente{
    private:
        bool transformado; // Indica se o mímico está transformado
        float raio;        // Raio do mímico (pode representar alcance ou tamanho)

    public:

        sf::Texture texture;

        // Construtor padrão
        Mimico();

        // Destrutor
        ~Mimico();

        // Método para danificar um jogador (ainda não implementado)
        void danificar(Jogador* p);
            // Método vazio, pois Jogador não foi definido
        

        // Método para executar o comportamento do mímico
        void executar();
            // Código do comprtamento do mímico (a ser definido futuramente)
        

        void setSprite(const sf::Texture& texture);

        void carregarTextura(const std::string& caminhoTexture);


        void Mimico::desenhar(Gerenciador_Grafico* pGG) override;
        /*
        // Métodos getters para possíveis acessos externos
        bool isTransformado() const { return transformado; }
        float getRaio() const { return raio; }
        void Mimico::desenhar(Gerenciador_Grafico* gerador);
        */
};

#endif