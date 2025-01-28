#ifndef GERENCIADOR_FISICO_H
#define GERENCIADOR_FISICO_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
using namespace sf;

class Fisica {

private:

    Vector2f velocidade; // Velocidade do personagem
    Vector2f posicao;   // Posição do personagem
    
    float gravidade = 9.81f; // Gravidade (m/s^2)
    float tempo = 0.016f;    // Tempo de simulação (60 FPS por padrão)

    mutex mtx;          // Mutex para sincronização

public:
    Fisica(Vector2f posicaoInicial) : posicao(posicaoInicial), velocidade(0.f, 0.f) {}

    void aplicarGravidade() {
        // Aplica a gravidade ao objeto, alterando sua velocidade na direção Y
        velocidade.y += gravidade * tempo;  // Acelerando na direção Y devido à gravidade
    }

    void atualizarPosicao() {
        // Atualiza a posição do objeto com base na velocidade
        posicao.y += velocidade.y * tempo;

        // Se a posição chegar ao chão (y > 500, por exemplo), a velocidade é zerada para simular colisão com o chão
        if (posicao.y >= 500.f) {
            posicao.y = 500.f;
            velocidade.y = 0.f;
        }
    }

    void processarFisica() {
        while (true) {
            this_thread::sleep_for(chrono::milliseconds(16)); // Simula o tempo de cada frame

            lock_guard<mutex> lock(mtx); // Garante acesso seguro aos dados compartilhados
            aplicarGravidade();
            atualizarPosicao();
        }
    }

    // Getter para a posição (para renderizar no jogo)
    Vector2f getPosicao() const {
        return posicao;
    }

    // Setter para a posição (se necessário)
    void setPosicao(const Vector2f& novaPosicao) {
        posicao = novaPosicao;
    }


    /*
    
    // Verifica colisão com outro personagem ou objeto
    sf::FloatRect boundingBox = getSprite().getGlobalBounds();  // A caixa delimitadora do personagem

    // Exemplo de outro objeto ou personagem
    sf::FloatRect boundingBoxOutroPersonagem = outroPersonagem.getSprite().getGlobalBounds();

    if (verificarColisao(boundingBox, boundingBoxOutroPersonagem)) {
        // Se colidir com outro personagem, faça algo, por exemplo:
        std::cout << "Colisão detectada!" << std::endl;
        // Impedir o movimento ou aplicar outra lógica
    }

    */
};

#endif