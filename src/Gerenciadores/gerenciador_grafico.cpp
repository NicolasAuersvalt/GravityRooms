#include "Gerenciadores/Gerenciador_grafico.h"
#include "Ente.h" // Substitua pelo caminho correto, se necessário

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
    
    while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                shutdown();
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
    if (!pE) {
        std::cerr << "Erro: Ponteiro para Ente é nulo!" << std::endl;
        return;
    }

    if (!window.isOpen()) {
        std::cerr << "Erro: A janela não está aberta!" << std::endl;
        return;
    }

    // Obtém o sprite do Ente
    sf::Sprite sprite = pE->getSprite();

    // Obtém a textura associada ao sprite
    const sf::Texture* texture = pE->getTexture();
    if (!texture) {
        std::cerr << "Erro: Ente não possui uma textura carregada!" << std::endl;

        // Teste: Tenta carregar uma textura padrão
        static sf::Texture texturaPadrao;
        if (!texturaPadrao.loadFromFile("textura_padrao.png")) {
            std::cerr << "Erro: Não foi possível carregar a textura padrão!" << std::endl;
            return;
        }

        // Associa a textura padrão ao sprite
        sprite.setTexture(texturaPadrao);
        std::cerr << "A textura padrão foi aplicada ao sprite do Ente." << std::endl;
    }

    // Desenha o sprite do Ente na janela
    try {
        window.draw(sprite);
        std::cout << "Sprite do Ente desenhado com sucesso!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao desenhar o sprite do Ente: " << e.what() << std::endl;
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
