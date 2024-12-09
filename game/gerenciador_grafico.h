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

            // ===/===/===/===/ Outros  ===/===/===/===/

            // Nome do título da janela
            string nomeJanela =  "GravityRooms";

            sf::RenderWindow window;  // Adicionando m_window

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

            // verifica se a janela está aberta
            const bool estaAberta();

            // usar futuramente
            void operator+(int val);

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/


            // ===/===/===/===/ Outros ===/===/===/===/

            
        public:

            // ===/===/===/===/ Obrigatórios ===/===/===/===/

            // Construtor (FALTA)
            Gerenciador_Grafico();

                // Destrutor (FALTA)
            ~Gerenciador_Grafico();

            // ===/===/===/===/ Outros ===/===/===/===/


    };
}

#endif
