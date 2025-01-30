#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <mutex>

std::mutex mtx;

class SaveManager {
public:
    static void save(const sf::Vector2f& position) {
        std::lock_guard<std::mutex> lock(mtx);
        std::ofstream file("player_save.txt");
        if (file.is_open()) {
            file << position.x << " " << position.y;
            file.close();
        }
    }

    static sf::Vector2f load() {
        std::lock_guard<std::mutex> lock(mtx);
        std::ifstream file("player_save.txt");
        sf::Vector2f position(100, 100);
        if (file.is_open()) {
            file >> position.x >> position.y;
            file.close();
        }
        return position;
    }
};

class Player {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Player() {
        shape.setSize({50, 50});
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(SaveManager::load());
    }

    void move(float dx, float dy) {
        velocity.x = dx;
        velocity.y = dy;
    }

    void update(float dt) {
        shape.move(velocity * dt);
    }

    void save() {
        SaveManager::save(shape.getPosition());
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
    Player player;
    sf::Clock clock;
    bool paused = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    paused = !paused;
                    if (paused) player.save();
                }
            }
        }

        if (!paused) {
            float dt = clock.restart().asSeconds();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) player.move(-100, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(100, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player.move(0, -100);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) player.move(0, 100);
            player.update(dt);
        }

        window.clear();
        window.draw(player.shape);
        window.display();
    }
    return 0;
}
