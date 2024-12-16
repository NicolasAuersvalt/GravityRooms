#include <iostream>
#include "mimico.h" // Arquivo de cabeçalho da classe Mimico

// Construtor padrão
Mimico::Mimico() : transformado(false), raio(0.0f) {
    // Associa um sprite
    pFig = new sf::Sprite(); // or other initialization logic

}

// Destrutor
Mimico::~Mimico() {


}

// Método para danificar um jogador (ainda não implementado)
void Mimico::danificar(Jogador* p) {
    // Método vazio, pois Jogador não foi definido
}

// Método para executar o comportamento do mímico
void Mimico::executar() {
    // Comportamento do mímico pode ser definido aqui futuramente
    std::cout << "Executando comportamento do mímico..." << std::endl;
}

void carregarTextura(const std::string& caminhoTexture) {
        if (!texture.loadFromFile(caminhoTexture)) {
            // Lidar com erro ao carregar a textura
        }
        pFig->setTexture(texture);
    }

void setSprite(const sf::Texture& texture) {
    pFig->setTexture(texture);
}

// Método para desenhar o sprite do mímico no GeradorGrafico
void Mimico::desenhar(Gerenciador_Grafico* pGG){
    // Aqui é chamado o sprite do mímico para ser renderizado
    if (gerador) {
        std::cout << "Desenhando sprite do mímico..." << std::endl;
        pGG->desenharEnte(this); // Passa o mímico como entidade para o gerador gráfico
    }
}
