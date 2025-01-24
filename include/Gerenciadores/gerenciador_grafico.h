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
using namespace sf;

class Ente;

namespace Gerenciadores {

    class Gerenciador_Grafico {
    private:
    
        static Gerenciador_Grafico* grafico;  // Instância única

        string nomeJanela = "GravityRooms"; // Nome da janela
        RenderWindow window;  // Janela de renderização
        const int fps = 60;  // Limite de frames por segundo

        const int largura = 1280;
        const int altura = 920;

        // Adicionar o mutex para proteger acesso a recursos compartilhados entre as threads, se necessário
        mutex mtx;

        // Impedir cópia SINGLETON
        Gerenciador_Grafico(const Gerenciador_Grafico&) = delete;
        Gerenciador_Grafico& operator=(const Gerenciador_Grafico&) = delete;

    public:

        // Construtor 
        Gerenciador_Grafico();

        // Destrutor
        ~Gerenciador_Grafico();

        // Método para obter a instância única
        static Gerenciador_Grafico* getInstancia();

        // Desenhar um ente OBRIGATÓRIO
        void desenharEnte(Ente* pE);

        void desenhar(Sprite& sprite);

        bool processarEvento(Event& event);

        // Verificar se a janela está aberta
        const bool estaAberta();

        // Inicializador de janela
        void inicializador();

        void fechar();

        void limpar();

        void exibir();

        void atualizar();

        void executar();

    };

} using namespace Gerenciadores;

#endif
