#ifndef GERENCIADOR_EVENTOS
#define GERENCIADOR_EVENTOS

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

using namespace std; 
using namespace sf;

class Gerenciador_Eventos {

    public:
        // Função para processar eventos e gerenciar a janela
        void processarEventos(RenderWindow* window, bool& rodando) {

            Event evento;

            while (window->pollEvent(evento)) {
                if (evento.type == Event::Closed) {
                    rodando = false;
                    window->close();
                }

                // Processar apenas eventos de teclado
                if (evento.type == Event::KeyPressed || evento.type == Event::KeyReleased) {
                    eventKey.processarEventoTeclado(evento);
                }
            }
        }

        Vector2f calcularDeslocamento() {
            Vector2f deslocamento(0.f, 0.f);

            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                deslocamento.x -= 5.f;  // Esquerda
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                deslocamento.x += 5.f;  // Direita
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                deslocamento.y -= 5.f;  // Cima
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                deslocamento.y += 5.f;  // Baixo
            }

            return deslocamento;
        }
    };
}




#endif