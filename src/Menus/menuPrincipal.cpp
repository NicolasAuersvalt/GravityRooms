/*
#include "Menu/MenuPrincipal.h"



    namespace Menus {

        MenuPrincipal::MenuPrincipal():
            Menu(IDs::IDs::menu_principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "JUNGLE++", 180),
            fundo(IDs::IDs::fundo_florestaNegra)
        {
            titulo.setPos(sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
            titulo.setCorTexto(sf::Color{0,200,0});
            criarFundo();
        }

        MenuPrincipal::MenuPrincipal(const IDs::IDs ID, std::string nome, const unsigned int tamFonte):
            Menu(ID, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte), 
            fundo(IDs::IDs::fundo_florestaNegra)
        {
            titulo.setPos(sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
            titulo.setCorTexto(sf::Color{0,200,0});

            criarFundo();
        }

        MenuPrincipal::~MenuPrincipal(){
            
        }
        void Fundo::setCorSolida(const sf::Color& cor) {
    fundoSolido.setSize(sf::Vector2f(1920.0f, 1080.0f));
    fundoSolido.setFillColor(cor);
    fundoSolido.setPosition(0.0f, 0.0f);
}

        void MenuPrincipal::criarFundo(){
            fundo.setCorSolida(sf::Color(0, 100, 0));

            //colocar o fundo de cor solida
        }

        void MenuPrincipal::criarBotoes(){
            const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            addBotao("Novo Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f), IDs::IDs::botao_novoJogo, sf::Color{0, 255, 0});
            addBotao("Carregar Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 1.2f), IDs::IDs::botao_carregar_jogo, sf::Color{0, 255, 0});
            addBotao("Colocacao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 2.4f), IDs::IDs::botao_colocacao, sf::Color{0, 255, 0});
            addBotao("Opcao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.6f), IDs::IDs::botao_opcao, sf::Color{0, 255, 0});
            addBotao("Sair", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), IDs::IDs::botao_sair, sf::Color{0, 255, 0});
            inicializarIterator();
        }

        void MenuPrincipal::executar(){
            //conteúdo do efeito Parallax
            posFundo = sf::Vector2f(posFundo.x + pGrafico->getTempo() * 80.0f, posFundo.y);
            pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            fundo.executar();
            pGrafico->resetarJanela();

            //desenha todo o conteúdo do menu principal na tela
            desenhar();
            pGrafico->desenhaElemento(titulo.getTexto());
        }

    }


*/