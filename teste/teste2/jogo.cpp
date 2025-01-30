#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <filesystem>
#include "json.hpp" // Inclua a biblioteca nlohmann/json

using json = nlohmann::json;

// Mutex para sincronização
std::mutex mtx;

// Classe Item
class Item {
public:
    std::string nome;
    int quantidade;

    Item(std::string nome = "Item", int quantidade = 1)
        : nome(nome), quantidade(quantidade) {}

    // Serializa o Item para JSON
    json toJson() const {
        return {
            {"nome", nome},
            {"quantidade", quantidade}
        };
    }

    // Desserializa o Item a partir de JSON
    void fromJson(const json& j) {
        nome = j.at("nome").get<std::string>();
        quantidade = j.at("quantidade").get<int>();
    }
};

// Classe Inventario
class Inventario {
public:
    std::vector<Item> itens;

    // Adiciona um item ao inventário
    void adicionarItem(const Item& item) {
        itens.push_back(item);
    }

    // Serializa o Inventário para JSON
    json toJson() const {
        json j_itens = json::array();
        for (const auto& item : itens) {
            j_itens.push_back(item.toJson());
        }
        return {{"itens", j_itens}};
    }

    // Desserializa o Inventário a partir de JSON
    void fromJson(const json& j) {
        for (const auto& item_json : j.at("itens")) {
            Item item;
            item.fromJson(item_json);
            itens.push_back(item);
        }
    }
};

// Classe Jogador
class Jogador {
public:
    float x, y;
    std::string nome;
    sf::RectangleShape shape;
    Inventario inventario; // Relacionamento: Jogador tem um Inventário

    Jogador(float x = 100, float y = 100, std::string nome = "Jogador")
        : x(x), y(y), nome(nome) {
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
    }

    void mover(float dx, float dy) {
        x += dx;
        y += dy;
        shape.setPosition(x, y);
    }

    // Serializa o Jogador e seu Inventário para JSON
    json toJson() const {
        return {
            {"x", x},
            {"y", y},
            {"nome", nome},
            {"inventario", inventario.toJson()} // Inclui o inventário no JSON
        };
    }

    // Desserializa o Jogador e seu Inventário a partir de JSON
    void fromJson(const json& j) {
        x = j.at("x").get<float>();
        y = j.at("y").get<float>();
        nome = j.at("nome").get<std::string>();
        inventario.fromJson(j.at("inventario")); // Carrega o inventário
        shape.setPosition(x, y);
    }

    void salvar(const std::string& arquivo) {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueia o acesso concorrente
        std::ofstream file(arquivo);
        if (file.is_open()) {
            json j = toJson(); // Converte o objeto para JSON
            file << j.dump(4); // Salva o JSON no arquivo
            file.close();
        }
    }

    void carregar(const std::string& arquivo) {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueia o acesso concorrente
        std::ifstream file(arquivo);
        if (file.is_open()) {
            json j;
            file >> j; // Lê o JSON do arquivo
            fromJson(j); // Converte o JSON de volta para o objeto
            file.close();
        }
    }
};

// Função para salvar o estado do jogador em uma thread separada
void salvarJogador(Jogador& jogador, const std::string& arquivo) {
    jogador.salvar(arquivo);
    std::cout << "Jogador e Inventário salvos!\n";
}

// Função para verificar se o arquivo existe
bool arquivoExiste(const std::string& caminho) {
    return std::filesystem::exists(caminho);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo SFML");

    // Verifica se o arquivo de salvamento existe
    std::string arquivoSalvamento = "jogador_save.json";
    Jogador jogador; // Posição inicial padrão

    if (arquivoExiste(arquivoSalvamento)) {
        std::cout << "Arquivo de salvamento encontrado. Carregando estado do jogador...\n";
        jogador.carregar(arquivoSalvamento);
    } else {
        std::cout << "Nenhum arquivo de salvamento encontrado. Iniciando do início.\n";
    }

    jogador.inventario.adicionarItem(Item("Espada", 1));
    jogador.inventario.adicionarItem(Item("Poção", 5));

    bool pausado = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Menu de Pausa
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    pausado = !pausado;
                    if (pausado) {
                        // Salva o estado do jogador em uma thread separada
                        std::thread t(salvarJogador, std::ref(jogador), arquivoSalvamento);
                        t.detach(); // Executa em segundo plano
                    }
                }
            }
        }

        if (!pausado) {
            // Movimentação do jogador
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) jogador.mover(-0.8f, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) jogador.mover(0.8f, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) jogador.mover(0, -0.8f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) jogador.mover(0, 0.8f);
        }

        // Renderização
        window.clear();
        window.draw(jogador.shape);
        window.display();
    }

    return 0;
}
