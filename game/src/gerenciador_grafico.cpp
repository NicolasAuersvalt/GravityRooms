#include "gerenciador_grafico.h"
#include <iostream>

namespace Gerenciadores {

    // Inicializar o atributo estático
    Gerenciador_Grafico* Gerenciador_Grafico::grafico = nullptr;

    // Construtor
    Gerenciador_Grafico::Gerenciador_Grafico()
    : width(1280), height(920)  // Inicialização das variáveis membro
    {
        inicializador();
    }

    // Destrutor
    Gerenciador_Grafico::~Gerenciador_Grafico() {
        shutdown();
    }

    // Método estático para obter a instância única
    Gerenciador_Grafico* Gerenciador_Grafico::getInstancia() {
        if (grafico == nullptr) {
            grafico = new Gerenciador_Grafico();
        }
        return grafico;
    }

    // Inicializador de janela
    void Gerenciador_Grafico::inicializador() {
        // Corrigido para criar a janela corretamente
        window.create(sf::VideoMode(width, height), nomeJanela);

        // Definir framerate para 60fps
        window.setFramerateLimit(fps);

        // Define o Jogador
        sf::RectangleShape jogador(sf::Vector2f(50.0f, 50.0f));  // Jogador com tamanho 50x50

        sf::Event event; // Declarar evento fora do loop

        // Loop principal de renderização
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                // "close requested" event: fecha a janela
                if (event.type == sf::Event::Closed) {
                    shutdown();
                }
            }
            
            // Desenha o jogador na tela
            window.clear(sf::Color::Black);  // Limpa a tela com a cor preta
            window.draw(jogador);  // Desenha o objeto jogador
            window.display();  // Exibe o que foi desenhado
        }
    }

    void Gerenciador_Grafico::executar(const sf::Vector2f& posAlvo) {
    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                shutdown();
            }
        }

        // Atualizar o comportamento de todos os objetos
        for (auto& objeto : objetos) {
            objeto->executar(posAlvo); // Atualiza cada objeto, supondo que todos suportem o método executar
        }

        // Desenha os objetos
        desenhar();
    }
}




    // Fechar a janela
    void Gerenciador_Grafico::shutdown() {
        window.close();
    }

    // Desenhar um ente (entidade)
    void Gerenciador_Grafico::desenharEnte(Ente* pE) {
    if (pE) {
        pE->desenharNaTela(window); // Desenha qualquer ente, incluindo o mimico
    }
}


    void Gerenciador_Grafico::adicionarObjetos(Ente* objeto) {
    if (objeto) {
        objetos.push_back(objeto);
    }
}



    void Gerenciador_Grafico::desenhar() {
    window.clear(sf::Color::Black);

    for (auto& objeto : objetos) {
        objeto->desenharNaTela(window); // Cada objeto sabe como se desenhar
    }

    window.display();
}




    // Atualizar a janela (captura eventos)
    void Gerenciador_Grafico::atualizar() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                shutdown();
            }
        }
    }

    // Verificar se a janela está aberta
    const bool Gerenciador_Grafico::estaAberta() {
        return window.isOpen();
    }

    // Sobrecarga de operador (futuro uso)
    void Gerenciador_Grafico::operator+(int val) {
        // Implementar lógica quando necessário
    }

}