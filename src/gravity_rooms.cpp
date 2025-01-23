#include "gravity_rooms.h"
#include "ente.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// #include "Listas/lista_entidades.cpp"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;

// ===/===/===/===/ Obrigatório ===/===/===/===/

// Construtor
Gravity_Rooms::Gravity_Rooms() : GG(),
        pJog1(),
        pAnd1(),
        pAnd2(),
        plataforma(),
        LJog1(),
        GC()
{
    Ente::setGerenciador(&GG);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/nave1.jpg"))
    {
        std::cerr << "Erro ao carregar o background!" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(25, 25);

    
    std::ifstream arquivo("dados_salvos.json");
            if (arquivo.is_open()) {
                nlohmann::ordered_json buffer;
                arquivo >> buffer;
                arquivo.close();
                pJog1.carregarDataBuffer(buffer);
                std::cout << "Dados carregados de 'dados_salvos.json'.\n";
            } else {
                std::cerr << "Erro ao abrir o arquivo para carregar os dados.\n";
            }


    pair pos = pJog1.getPosition();

    pJog1.setSprite("assets/tripulanteG.png", pos.first, pos.second);

    LJog1.incluir(static_cast<Entidade *>(&pJog1));

    plataforma.setSprite("assets/plataformaG.png", 0, 0);
    LJog1.incluir(static_cast<Entidade *>(&plataforma));

    pAnd1.setSprite("assets/androidG.png", 0, 0);
    LJog1.incluir(static_cast<Entidade *>(&pAnd1));

    executar();
}

// Destrutor
Gravity_Rooms::~Gravity_Rooms()
{
}

void Gravity_Rooms::executar()
{

    GG.executar();
    GC.incluirTripulante(pJog1);
    GC.incluirInimigo(static_cast<Inimigo *>(&pAnd1));
    
    while (GG.estaAberta())
    { // Enquanto a janela estiver aberta
        sf::Event evento;

        while (GG.processarEvento(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                GG.fechar();
            }

            if (evento.type == sf::Event::KeyPressed) {
        // Verifica se a tecla pressionada foi 'Y'
        if (evento.key.code == sf::Keyboard::Y) {
            // Chama o método de salvar buffer do objeto PJog1
            nlohmann::ordered_json buffer;
            pJog1.salvarDataBuffer(buffer);
            // Exemplo: Salvar o buffer em um arquivo
            std::ofstream arquivo("dados_salvos.json");
            if (arquivo.is_open()) {
                arquivo << buffer.dump(4); // Salva com indentação de 4 espaços
                arquivo.close();
                std::cout << "Dados salvos em 'dados_salvos.json'.\n";
            } else {
                std::cerr << "Erro ao abrir o arquivo para salvar os dados.\n";
            }
        }
        
    }
            
        }

        GG.limpar(); // Limpa a tela antes de desenhar qualquer coisa

        // Desenha os objetos na ordem correta
        //GG.desenhar(backgroundSprite); // Desenha o fundo primeiro

        // GG.desenharEnte(&pJog1);  // Desenha o Tripulante 1 (ou qualquer outro ente)

        LJog1.desenharTodos(); // Desenha os outros sprites da lista
        GC.executar();

        GG.exibir(); // Exibe a tela com todos os objetos desenhados

        // Atualiza os objetos, caso necessário (atualização de movimentos, animações, etc.)
        LJog1.atualizarTodas();
    }
}


// ===/===/===/===/ Outros  ===/===/===/===/