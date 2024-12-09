#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include "stdafx.h"


class BiblioGrafica;
class Ente;

namespace Gerenciadores
{

    class Gerenciador_Grafico
    {


        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            //BiblioGrafica obj;
            static Gerenciador_Grafico *grafico;


            // ===/===/===/===/ Outros  ===/===/===/===/

            // Nome do título da janela
            string nomeJanela =  "GravityRooms";

            sf::RenderWindow window;  // Padrão Singleton

            // Fps padrão
            const int fps = 60;

            void desenharEnte(Ente *pE);

            // Inicializador de janelas
            void inicializador(); // COLOCAR UML

            // para adicionar um objeto à lista
            void adicionarObjetos( /*Alguma coisa*/ );

            // desenha todos os objetos na tela
            void desenhar();

            // atualiza a janela (frames)
            void atualizar();

            void start();

            void shutdown();

            // verifica se a janela está aberta
            const bool estaAberta();

            // usar futuramente
            void operator+(int val);


            // Singleton - Impedir cópia
            Gerenciador_Grafico(const Gerenciador_Grafico&) = delete;
            Gerenciador_Grafico& operator=(const Gerenciador_Grafico&) = delete;

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/


            // ===/===/===/===/ Outros ===/===/===/===/

            
        public:

            // ===/===/===/===/ Obrigatórios ===/===/===/===/

            // Construtor (FALTA)
            Gerenciador_Grafico();

                // Destrutor (FALTA)
            ~Gerenciador_Grafico();

            static Gerenciador_Grafico* getInstancia();

            // ===/===/===/===/ Outros ===/===/===/===/


    };
}

// Inicializacao membro estatico
Gerenciador_Grafico* Gerenciador_Grafico::grafico = nullptr;

#endif
