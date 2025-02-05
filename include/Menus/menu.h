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

namespace Menus {

class Menu : public Ente {
 protected:
  list<Menus::Botoes::BotaoTexto *> listaBotaoTexto;
  list<Menus::Botoes::BotaoTexto *>::iterator it;

  const Vector2f tamBotao;
  const Vector2f tamJanela;

  Menus::Botoes::Texto titulo;
  bool botaoSelecionado;

  sf::Texture texturaBackground;
  sf::Sprite spriteBackground;
  sf::Vector2f posFundo;

  void atualizarPosicaoFundo();
  virtual void criarFundo() {};

 public:
  void inicializarIterator();

  Menu(const IDs::IDs ID, const Vector2f tamBotao, const string nome,
       const unsigned int tamFonte);
  ~Menu();
  void addBotao(const string info, const Vector2f pos, const IDs::IDs ID,
                const Color corSelecionado);
  virtual void criarBotoes() = 0;
  void mudarEstadoObservador();
  void selecionaCima();
  void selecionaBaixo();
  virtual void selecionaEsquerda() {}
  virtual void selecionaDireita() {}
  const IDs::IDs getIDBotaoSelecionado() const;
  void eventoTeclado(const Keyboard::Key tecla);
  bool getSelecionado();
  virtual void executar() = 0;
  void desenhar(Gerenciador_Grafico *GG);
  void setSelecionado(bool status);
  std::string getTipo() const override { return "Menu"; }
  void carregar(json &arquivo) {}
  void salvar(json &arquivo) override {}
};

}  // namespace Menus

#endif
