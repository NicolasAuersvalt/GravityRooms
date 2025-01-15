#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <thread>  // Para usar std::thread
#include <mutex>   // Para usar std::mutex, se necessário

#include <iostream>
#include <string>

using namespace std; 

class Ente;

namespace Gerenciadores {

    class Gerenciador_Grafico {
    private:
    
        static Gerenciador_Grafico* grafico;  // Instância única

        string nomeJanela = "GravityRooms"; // Nome da janela
        sf::RenderWindow window;  // Janela de renderização
        const int fps = 60;  // Limite de frames por segundo

        const int width;
        const int height;

        // Impedir cópia SINGLETON
        Gerenciador_Grafico(const Gerenciador_Grafico&) = delete;
        Gerenciador_Grafico& operator=(const Gerenciador_Grafico&) = delete;

        sf::Event event;

        // Adicionar o mutex para proteger acesso a recursos compartilhados entre as threads, se necessário
        std::mutex mtx;

    public:

        // Construtor 
        Gerenciador_Grafico();

        // Destrutor
        ~Gerenciador_Grafico();

        // Método para obter a instância única
        static Gerenciador_Grafico* getInstancia();

        // Inicializador de janela
        void inicializador();

        // Encerrar a janela
        void shutdown();

        // Desenhar um ente OBRIGATÓRIO
        void desenharEnte(Ente* pE);

        // Adicionar objetos
        void adicionarObjetos(/*Alguma coisa*/);

        // Desenhar todos os objetos
        void desenhar();

        void executar();

        // Atualizar a janela
        void atualizar();

        void atualizarEventos();

        // Verificar se a janela está aberta
        const bool estaAberta();

        // Sobrecarga de operador (futuro uso)
        void operator+(int val);
    };

} using namespace Gerenciadores;

#endif
