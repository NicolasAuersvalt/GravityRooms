#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class Entidade {
public:
    virtual void atualizar(float deltaTempo) = 0;
    virtual void desenhar(sf::RenderWindow& janela) = 0;
};

class Plataforma : public Entidade {
public:
    sf::RectangleShape forma;

    Plataforma(float x, float y, float largura, float altura) {
        forma.setPosition(x, y);
        forma.setSize(sf::Vector2f(largura, altura));
        forma.setFillColor(sf::Color::Green);
    }

    void atualizar(float deltaTempo) override {}

    void desenhar(sf::RenderWindow& janela) override {
        janela.draw(forma);
    }
};

class Jogador : public Entidade {
public:
    sf::RectangleShape forma;
    float velocidadeY;
    bool noChao;

    Jogador() {
        forma.setSize(sf::Vector2f(50.f, 50.f));
        forma.setFillColor(sf::Color::Red);
        forma.setPosition(200.f, 200.f);
        velocidadeY = 0.f;
        noChao = false;
    }

    void atualizar(float deltaTempo) override {
        // Gravidade
        if (!noChao) {
            velocidadeY += 9.8f * deltaTempo;
        } else {
            velocidadeY = 0.f;
        }

        // Movimentação
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            forma.move(-200.f * deltaTempo, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            forma.move(200.f * deltaTempo, 0.f);
        }

        // Pulo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && noChao) {
            velocidadeY = -500.f;
            noChao = false;
        }

        // Atualizar a posição com base na gravidade
        forma.move(0.f, velocidadeY * deltaTempo);
    }

    void desenhar(sf::RenderWindow& janela) override {
        janela.draw(forma);
    }
};

class GerenciadorEntidades {
public:
    std::vector<Entidade*> entidades;

    ~GerenciadorEntidades() {
        for (auto* entidade : entidades) {
            delete entidade;
        }
    }

    void adicionarEntidade(Entidade* entidade) {
        entidades.push_back(entidade);
    }

    void atualizarTodas(float deltaTempo) {
        for (auto* entidade : entidades) {
            entidade->atualizar(deltaTempo);
        }
    }

    void desenharTodas(sf::RenderWindow& janela) {
        for (auto* entidade : entidades) {
            entidade->desenhar(janela);
        }
    }
};

class GerenciadorColisoes {
public:

    void verificarColisoes(Jogador& jogador, const std::vector<Entidade*>& entidades) {

        jogador.noChao = false;

        for (auto* entidade : entidades) {

            Plataforma* plataforma = dynamic_cast<Plataforma*>(entidade);

            if (plataforma && jogador.forma.getGlobalBounds().intersects(plataforma->forma.getGlobalBounds())) {

                // Colisão detectada
                if (jogador.velocidadeY > 0) { // Apenas se o jogador está caindo

                    jogador.forma.setPosition(jogador.forma.getPosition().x, plataforma->forma.getPosition().y - jogador.forma.getSize().y);
                    jogador.noChao = true;
                    
                    break;
                }
            }
        }
    }
};

class GerenciadorGraficos {
public:
    sf::RenderWindow janela;

    GerenciadorGraficos() : janela(sf::VideoMode(800, 600), "Jogo de Quadrado que Pula") {
        janela.setFramerateLimit(60);
    }

    void limpar() {
        janela.clear(sf::Color::Cyan);
    }

    void exibir() {
        janela.display();
    }

    bool estaAberta() const {
        return janela.isOpen();
    }

    bool processarEvento(sf::Event& evento) {
        return janela.pollEvent(evento);
    }

    void fechar() {
        janela.close();
    }
};

int main() {
    GerenciadorGraficos gerenciadorGraficos;
    GerenciadorEntidades gerenciadorEntidades;
    GerenciadorColisoes gerenciadorColisoes;

    Jogador* jogador = new Jogador();
    gerenciadorEntidades.adicionarEntidade(jogador);

    gerenciadorEntidades.adicionarEntidade(new Plataforma(100.f, 500.f, 600.f, 20.f));
    gerenciadorEntidades.adicionarEntidade(new Plataforma(200.f, 350.f, 200.f, 20.f));
    gerenciadorEntidades.adicionarEntidade(new Plataforma(500.f, 250.f, 200.f, 20.f));

    sf::Clock relogio;

    while (gerenciadorGraficos.estaAberta()) {
        sf::Time deltaTempo = relogio.restart();

        sf::Event evento;
        while (gerenciadorGraficos.processarEvento(evento)) {
            if (evento.type == sf::Event::Closed) {
                gerenciadorGraficos.fechar();
            }
        }

        gerenciadorEntidades.atualizarTodas(deltaTempo.asSeconds());
        gerenciadorColisoes.verificarColisoes(*jogador, gerenciadorEntidades.entidades);

        gerenciadorGraficos.limpar();
        gerenciadorEntidades.desenharTodas(gerenciadorGraficos.janela);
        gerenciadorGraficos.exibir();
    }

    return 0;
}
