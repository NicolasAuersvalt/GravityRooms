#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Menus/Botoes/botao.h"
#include "Menus/Botoes/botaoTexto.h"
#include "Menus/Botoes/texto.h"
#include "ente.h"
#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

#include "Gerenciadores/gerenciador_grafico.h"

using namespace std;
using namespace sf;

class Gravity_Rooms;

// using Menus::Botao::BotaoTexto;

namespace Menus {
class Menu : public Ente {
 protected:
  std::list<Menus::Botoes::BotaoTexto*> listaBotaoTexto;
  std::list<Menus::Botoes::BotaoTexto*>::iterator it;
  const sf::Vector2f tamBotao;
  const sf::Vector2f tamJanela;
  sf::Vector2f posFundo;
  Menus::Botoes::Texto titulo;
  bool botaoSelecionado;

  void atualizarPosicaoFundo();
  virtual void criarFundo() {};
  virtual void criarBotoes() = 0;
  void inicializarIterator();

 public:
  Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const std::string nome,
       const unsigned int tamFonte);
  ~Menu();
  void addBotao(const std::string info, const sf::Vector2f pos,
                const IDs::IDs ID, const sf::Color corSelecionado);
  void mudarEstadoObservador();
  void selecionaCima();
  void selecionaBaixo();
  virtual void selecionaEsquerda() {}
  virtual void selecionaDireita() {}
  const IDs::IDs getIDBotaoSelecionado() const;
  void eventoTeclado(const sf::Keyboard::Key tecla);
  bool getSelecionado();
  virtual void executar() = 0;
  void desenhar(Gerenciador_Grafico* GG);
};

}  // namespace Menus

#endif
