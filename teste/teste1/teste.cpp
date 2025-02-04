#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

// Gerenciador gráfico responsável pela renderização
class GerenciadorGrafico
{
  public:
    GerenciadorGrafico()
    {
        janela.create(sf::VideoMode(800, 600), "Jogo de Pular");
        janela.setFramerateLimit(60);
    }

    void desenhar(const sf::Drawable &drawable) { janela.draw(drawable); }

    void limparTela()
    {
        janela.clear(sf::Color::Cyan); // Cor de fundo
    }

    void mostrarTela() { janela.display(); }

    sf::RenderWindow &getJanela() { return janela; }

  private:
    sf::RenderWindow janela;
};

// Classe para o quadrado, responsável pelo movimento e física
class Quadrado
{
  public:
    Quadrado()
    {
        quadrado.setSize(sf::Vector2f(50, 50));
        quadrado.setFillColor(sf::Color::Green);
        velocidadeY = 0;
        noChao = false;
    }

    void atualizar()
    {
        if (!noChao)
        {
            velocidadeY += 0.5f; // gravidade
        }

        quadrado.move(0, velocidadeY);
    }

    void pular()
    {
        if (noChao)
        {
            velocidadeY = -10;
            noChao = false;
        }
    }

    void
    verificarColisaoComPlataforma(std::vector<sf::RectangleShape> &plataformas)
    {
        for (auto &plataforma : plataformas)
        {
            if (quadrado.getGlobalBounds().intersects(
                    plataforma.getGlobalBounds()))
            {
                if (velocidadeY > 0 &&
                    quadrado.getPosition().y + quadrado.getSize().y <=
                        plataforma.getPosition().y)
                {
                    noChao = true;
                    velocidadeY = 0;
                    quadrado.setPosition(quadrado.getPosition().x,
                                         plataforma.getPosition().y -
                                             quadrado.getSize().y);
                }
            }
        }
    }

    sf::RectangleShape &getQuadrado() { return quadrado; }

    bool isNoChao() { return noChao; }

    void setNoChao(bool status) { noChao = status; }

    void setPosicao(float x, float y) { quadrado.setPosition(x, y); }

  private:
    sf::RectangleShape quadrado;
    float velocidadeY;
    bool noChao;
};

// Classe base para as fases, será herdada pelas fases específicas
class Fase
{
  public:
    virtual void desenhar(GerenciadorGrafico &gerenciador) = 0;
    virtual void atualizar(Quadrado &quadrado) = 0;
    virtual void adicionarPlataformas() = 0;
    virtual std::vector<sf::RectangleShape> &getPlataformas() = 0;
};

// Fase 1
class Fase1 : public Fase
{
  public:
    Fase1() { adicionarPlataformas(); }

    void desenhar(GerenciadorGrafico &gerenciador) override
    {
        for (auto &plataforma : plataformas)
        {
            gerenciador.desenhar(plataforma);
        }
    }

    void atualizar(Quadrado &quadrado) override
    {
        quadrado.atualizar();
        quadrado.verificarColisaoComPlataforma(plataformas);
    }

    void adicionarPlataformas() override
    {
        sf::RectangleShape plataforma1(sf::Vector2f(200, 20));
        plataforma1.setFillColor(sf::Color::Blue);
        plataforma1.setPosition(150, 400);
        plataformas.push_back(plataforma1);

        sf::RectangleShape plataforma2(sf::Vector2f(200, 20));
        plataforma2.setFillColor(sf::Color::Blue);
        plataforma2.setPosition(450, 300);
        plataformas.push_back(plataforma2);
    }

    std::vector<sf::RectangleShape> &getPlataformas() override
    {
        return plataformas;
    }

  private:
    std::vector<sf::RectangleShape> plataformas;
};

// Fase 2
class Fase2 : public Fase
{
  public:
    Fase2() { adicionarPlataformas(); }

    void desenhar(GerenciadorGrafico &gerenciador) override
    {
        for (auto &plataforma : plataformas)
        {
            gerenciador.desenhar(plataforma);
        }
    }

    void atualizar(Quadrado &quadrado) override
    {
        quadrado.atualizar();
        quadrado.verificarColisaoComPlataforma(plataformas);
    }

    void adicionarPlataformas() override
    {
        sf::RectangleShape plataforma1(sf::Vector2f(200, 20));
        plataforma1.setFillColor(sf::Color::Green);
        plataforma1.setPosition(100, 500);
        plataformas.push_back(plataforma1);

        sf::RectangleShape plataforma2(sf::Vector2f(200, 20));
        plataforma2.setFillColor(sf::Color::Green);
        plataforma2.setPosition(400, 400);
        plataformas.push_back(plataforma2);
    }

    std::vector<sf::RectangleShape> &getPlataformas() override
    {
        return plataformas;
    }

  private:
    std::vector<sf::RectangleShape> plataformas;
};

// Classe Menu
class Menu
{
  public:
    Menu()
    {

        font.loadFromFile(
            "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"); // Fonte
                                                                     // padrão
                                                                     // no Linux

        // Inicializando as opções do menu
        fases.push_back("Fase 1");
        fases.push_back("Fase 2");

        // Criando os textos para as fases
        for (size_t i = 0; i < fases.size(); ++i)
        {
            sf::Text texto;
            texto.setFont(font);
            texto.setString(fases[i]);
            texto.setCharacterSize(30);
            texto.setFillColor(
                sf::Color::White); // Inicialmente todas as fases são brancas
            texto.setPosition(200, 200 + (i * 40));
            textos.push_back(texto);
        }

        // Cor da fase selecionada (verde)
        textos[0].setFillColor(sf::Color::Green);
        selecionada = 0;
    }

    void desenhar(GerenciadorGrafico &gerenciador)
    {
        for (auto &texto : textos)
        {
            gerenciador.desenhar(texto);
        }
    }

    bool estaAtivo(sf::RenderWindow &janela) { return janela.hasFocus(); }

    void moverSelecaoParaCima()
    {
        if (selecionada > 0)
        {
            textos[selecionada].setFillColor(
                sf::Color::White); // Desmarca a opção
            selecionada--;
            textos[selecionada].setFillColor(
                sf::Color::Green); // Marca a nova opção
        }
    }

    void moverSelecaoParaBaixo()
    {
        if (selecionada < fases.size() - 1)
        {
            textos[selecionada].setFillColor(
                sf::Color::White); // Desmarca a opção
            selecionada++;
            textos[selecionada].setFillColor(
                sf::Color::Green); // Marca a nova opção
        }
    }

    int obterSelecao(sf::Event &evento)
    {
        if (evento.type == sf::Event::KeyPressed)
        {
            if (evento.key.code == sf::Keyboard::Up)
            {
                moverSelecaoParaCima();
            }
            else if (evento.key.code == sf::Keyboard::Down)
            {
                moverSelecaoParaBaixo();
            }
            else if (evento.key.code == sf::Keyboard::Enter)
            {
                return selecionada + 1; // Retorna o número da fase selecionada
            }
        }
        return 0;
    }

  private:
    std::vector<std::string> fases;
    std::vector<sf::Text> textos;
    int selecionada;
    sf::Font font;
};

int main()
{

    GerenciadorGrafico gerenciadorGrafico;
    Quadrado quadrado;
    // ESTOU AQUI
    Menu menu;

    Fase *faseAtual = nullptr;

    bool jogoAtivo = false;
    sf::Clock clock;

    while (gerenciadorGrafico.getJanela().isOpen())
    {

        sf::Event evento;

        while (gerenciadorGrafico.getJanela().pollEvent(evento))
        {

            if (evento.type == sf::Event::Closed)
            {

                gerenciadorGrafico.getJanela().close();
            }

            if (faseAtual == nullptr)
            {
                int selecao = menu.obterSelecao(evento);
                if (selecao == 1)
                {
                    faseAtual = new Fase1();
                    quadrado.setPosicao(400,
                                        100); // Inicia o quadrado mais alto
                    jogoAtivo = true;
                }
                else if (selecao == 2)
                {
                    faseAtual = new Fase2();
                    quadrado.setPosicao(400,
                                        100); // Inicia o quadrado mais alto
                    jogoAtivo = true;
                }
            }
            else
            {
                if (evento.type == sf::Event::KeyPressed &&
                    evento.key.code == sf::Keyboard::Space)
                {
                    quadrado.pular();
                }
            }
        }

        gerenciadorGrafico.limparTela();

        if (faseAtual == nullptr)
        {
            menu.desenhar(gerenciadorGrafico);
        }
        else
        {
            faseAtual->atualizar(quadrado);
            faseAtual->desenhar(gerenciadorGrafico);
        }

        gerenciadorGrafico.desenhar(quadrado.getQuadrado());
        gerenciadorGrafico.mostrarTela();
    }

    delete faseAtual;
    return 0;
}
