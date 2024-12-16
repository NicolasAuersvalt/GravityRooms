#include "stdafx.h"
//#include "jogo.h"
#include "gerenciador_grafico.h"
#include "Projetil.h"


int main() {
    // Inicializa o gerenciador gráfico
    Gerenciadores::Gerenciador_Grafico graficos;

    // Cria a janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "Projetil");

    // Variável para controlar o ID dos projéteis
    int id = 1;
    
    // Variáveis para controle de teclas
    bool wPressed = false, aPressed = false, sPressed = false, dPressed = false;

    // Velocidade do projétil
    const float velocidade = 0.2f;

    // Vetor de projéteis
    std::vector<Projetil> projetis;

    // Loop principal do jogo
    while (window.isOpen()) {
        // Verifica eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Fecha a janela
            }

            // Detecta a liberação de teclas
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::W) wPressed = false;
                if (event.key.code == sf::Keyboard::S) sPressed = false;
                if (event.key.code == sf::Keyboard::A) aPressed = false;
                if (event.key.code == sf::Keyboard::D) dPressed = false;
            }
        }

        // Cria um projétil quando as teclas são pressionadas, mas apenas uma vez
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !wPressed) {
            projetis.push_back(Projetil(id++, 100, 200, 0.0f, -velocidade));  // Projétil movendo para cima
            wPressed = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sPressed) {
            projetis.push_back(Projetil(id++, 100, 200, 0.0f, velocidade));   // Projétil movendo para baixo
            sPressed = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !aPressed) {
            projetis.push_back(Projetil(id++, 100, 200, -velocidade, 0.0f));  // Projétil movendo para a esquerda
            aPressed = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !dPressed) {
            projetis.push_back(Projetil(id++, 100, 200, velocidade, 0.0f));   // Projétil movendo para a direita
            dPressed = true;
        }

        // Atualiza a posição dos projéteis
        for (auto& projetil : projetis) {
            projetil.executar();  // Move o projétil de acordo com sua direção constante
        }

        // Remove projéteis que saíram da tela
        projetis.erase(std::remove_if(projetis.begin(), projetis.end(),
            [](Projetil& p) { return !p.estaAtivo(); }), projetis.end());

        // Limpa a janela
        window.clear();

        // Desenha os projéteis e seus IDs
        for (auto& projetil : projetis) {
            projetil.desenhar(window);
        }

        window.display();  // Exibe o conteúdo da janela
    }

    return 0;
    /* // ===/===/===/===/ Obrigatório ===/===/===/===/

    //Jogo GravityRooms;

    // ===/===/===/===/ Outros ===/===/===/===/

    Gerenciadores::Gerenciador_Grafico graficos;

    return 0;*/
}