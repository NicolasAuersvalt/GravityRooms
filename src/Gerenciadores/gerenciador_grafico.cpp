#include "Gerenciadores/Gerenciador_grafico.h"
#include "Ente.h" // Substitua pelo caminho correto, se necessário
#include "Entidades/Personagens/Jogador.h"

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

    void Gerenciador_Grafico::inicializador() {
    // Cria a janela corretamente
    
    window.create(sf::VideoMode(width, height), nomeJanela);
    // Define o framerate para 60fps
    window.setFramerateLimit(fps);
}

    void Gerenciador_Grafico::executar() {
    sf::Event event;
    if (window.isOpen()) {
         if (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {                
                shutdown();
            }
        }
        
        window.clear(sf::Color::Black);  // Limpa a tela

        // Chame a função de desenho para desenhar os entes
        // Aqui você pode desenhar o jogador ou outros objetos
        window.display();  // Exibe a tela atualizada
    }
}


    // Fechar a janela
    void Gerenciador_Grafico::shutdown() {
        window.close();
    }

    void Gerenciador_Grafico::desenharEnte(Ente* pE) {
    if (pE && window.isOpen()) {  // Verifica se o ente e a janela são válidos
        // Obtém uma cópia do sprite do ente
        
        sf::Sprite sprite = pE->getSprite();
        // Agora você pode desenhar o sprite usando o método draw da janela
        
        window.clear(sf::Color::Black);  // Limpa a tela

        window.draw(sprite);
        // Chame a função de desenho para desenhar os entes
        // Aqui você pode desenhar o jogador ou outros objetos
        window.display();
    } else {
        throw std::runtime_error("Erro: Ente ou janela inválida!");
    }
    }



    // Adicionar objetos (vazio por enquanto)
    void Gerenciador_Grafico::adicionarObjetos(/*Alguma coisa*/) {
        // Lógica para adicionar objetos ao gerenciamento gráfico
    }

    // Desenhar todos os objetos na tela
    void Gerenciador_Grafico::desenhar() {
        window.clear(sf::Color::Black);  // Limpa a tela com a cor preta
        // Lógica para desenhar objetos na tela
        window.display();  // Exibe o conteúdo na tela
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
