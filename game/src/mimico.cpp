#include <iostream>
#include "Mimico.h" // Arquivo de cabeçalho da classe Mimico

// Construtor padrão
Mimico::Mimico() : transformado(false), raio(0.0f) {}

// Construtor com inicialização
Mimico::Mimico(bool t, float r) : transformado(t), raio(r) {}

// Destrutor
Mimico::~Mimico() {}

// Método para danificar um jogador (ainda não implementado)
void Mimico::danificar(Jogador* p) {
    // Método vazio, pois Jogador não foi definido
}

// Método para executar o comportamento do mímico
void Mimico::executar() {
    // Comportamento do mímico pode ser definido aqui futuramente
    std::cout << "Executando comportamento do mímico..." << std::endl;
}

// Método para desenhar o sprite do mímico no GeradorGrafico
void Mimico::desenhar(Gerenciador_Grafico* gerador) {
    // Aqui é chamado o sprite do mímico para ser renderizado
    if (gerador) {
        std::cout << "Desenhando sprite do mímico..." << std::endl;
        gerador->desenharEnte(this); // Passa o mímico como entidade para o gerador gráfico
    }
}
