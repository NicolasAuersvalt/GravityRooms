#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>

std::mutex mtx;
sf::Vector2f position(100.f, 100.f);

void moveCircle() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::lock_guard<std::mutex> lock(mtx);
        position.x += 5.f;
        if (position.x > 800) position.x = 0;
    }
}

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Mutex Example");

    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Green);

    std::thread movementThread(moveCircle);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        {
            std::lock_guard<std::mutex> lock(mtx);
            circle.setPosition(position);
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    movementThread.detach();
    return 0;
}
