#include <iostream>

class Jogador; // Declaração antecipada para Jogador (não definida ainda)
class Gerenciador_Grafico;

class Mimico {
private:
    bool transformado; // Indica se o mímico está transformado
    float raio;        // Raio do mímico (pode representar alcance ou tamanho)

public:
    // Construtor padrão
    Mimico() : transformado(false), raio(0.0f) {}

    // Construtor com inicialização
    Mimico(bool t, float r) : transformado(t), raio(r) {}

    // Destrutor
    ~Mimico() {}

    // Método para danificar um jogador (ainda não implementado)
    void danificar(Jogador* p) {
        // Método vazio, pois Jogador não foi definido
    }

    // Método para executar o comportamento do mímico
    void executar() {
        // Código do comportamento do mímico (a ser definido futuramente)
    }

    // Métodos getters para possíveis acessos externos
    bool isTransformado() const { return transformado; }
    float getRaio() const { return raio; }
    void Mimico::desenhar(Gerenciador_Grafico* gerador);
};