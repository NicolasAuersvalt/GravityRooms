#ifndef MENU_H
#define MENU_H

#include "ente.h"
// #include "Menus/Botoes/botao.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Gerenciadores/gerenciador_grafico.h"

using namespace std;
using namespace sf;

class Gravity_Rooms;

// using Menus::Botao::BotaoTexto;

namespace Menus {

class Menu : public Ente {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Gravity_Rooms* pJogo;

  vector<string> fases;
  vector<Text> textos;
  int selecionada;
  Font font;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  const Vector2f tamBotao;
  const Vector2f tamJanela;

  bool mouseSelecionado;

  // list<BotaoTexto*> listaBotaoTexto;
  // list<BotaoTexto*>::iterator it;  // n sei se vai funcionar

  // Texto titulo;

  // Vector2f posFundo;  // efeito parallax (ver)

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  /*
  Menu(const ID, const Vector2f tamBotao, const string nome,
       const unsigned int tamFonte);
  */

  Menu();

  ~Menu();

  // aaaaaaaaaaa void executar() override;

  // ===/===/===/===/ Outros  ===/===/===/===/

  int obterSelecao(Event& evento);

  void selecionaCima();

  void selecionaBaixo();

  void addBotao(const string info, const Vector2f pos, /* const
   ID,*/
                const Color corSelecionado);

  void desenhar(Gerenciador_Grafico& gerenciador);

  void atualizarPosicaoFundo();

  void moverSelecaoParaCima();

  void moverSelecaoParaBaixo();

  // virtual void executar() = 0;

  // aaaaaaaaaaa const IDs::IDs getIDBotaoSelecionado() const;
};

}  // namespace Menus

#endif
