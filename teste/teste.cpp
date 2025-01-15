#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class Platform {
public:
    sf::RectangleShape shape;
    
    Platform(float x, float y, float width, float height) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Green);
    }
};

class Player {
public:
    sf::RectangleShape shape;
    float velocityY;
    bool onGround;

    Player() {
        shape.setSize(sf::Vector2f(50.f, 50.f));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(200.f, 200.f);
        velocityY = 0.f;
        onGround = false;
    }

    void update(std::vector<Platform>& platforms, float deltaTime) {
        // Gravidade
        if (!onGround) {
            velocityY += 9.8f * deltaTime;
        } else {
            velocityY = 0.f;
        }

        // Movimentação
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-200.f * deltaTime, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(200.f * deltaTime, 0.f);
        }

        // Pulo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround) {
            velocityY = -500.f;  // Força do pulo
            onGround = false;
        }

        // Atualizar a posição com base na gravidade
        shape.move(0.f, velocityY * deltaTime);

        // Verificar colisões com plataformas
        onGround = false;
        for (auto& platform : platforms) {
            if (shape.getGlobalBounds().intersects(platform.shape.getGlobalBounds())) {
                // Colisão detectada
                if (velocityY > 0) {  // Apenas se o jogador está caindo
                    shape.setPosition(shape.getPosition().x, platform.shape.getPosition().y - shape.getSize().y);
                    onGround = true;
                    break;
                }
            }
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo de Quadrado que Pula");
    window.setFramerateLimit(60);

    Player player;
    std::vector<Platform> platforms;
    platforms.push_back(Platform(100.f, 500.f, 600.f, 20.f));  // Plataforma base
    platforms.push_back(Platform(200.f, 350.f, 200.f, 20.f));  // Plataforma no meio
    platforms.push_back(Platform(500.f, 250.f, 200.f, 20.f));  // Plataforma superior

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        // Processar eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Atualizar o jogador
        player.update(platforms, deltaTime.asSeconds());

        // Limpar a tela
        window.clear(sf::Color::Cyan);

        // Desenhar plataformas e jogador
        for (auto& platform : platforms) {
            window.draw(platform.shape);
        }
        window.draw(player.shape);

        // Exibir tudo
        window.display();
    }

    return 0;
}
