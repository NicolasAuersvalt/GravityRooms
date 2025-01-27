<<<<<<< HEAD
/*
#ifndef MENUPAUSE_H
#define MENUPAUSE_H

#include "ente.h"

using namespace std;
using namespace sf;

class Jogo;

class MenuPause : public Menu {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Jogo* pJog;
  RectangleShape fundoPainel;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  Fase::Fase* fase;
     RectangleShape fundoEscuro;
     float posBotaoY;

  void atualizarBotoes();

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  MenuPausa(Fase::Fase* fase = nullptr);
  MenuPausa(const IDs::IDs ID, const string nome, Fase::Fase* fase = nullptr); // dois construtores
  ~Menu();

  // void executar() override;

  // ===/===/===/===/ Outros  ===/===/===/===/
  virtual void criarBotoes();
     void setFase(Fase::Fase* fase);
     Fase::Fase* getFase();
     virtual void executar();
};

#endif
=======
/*
#ifndef MENUPAUSE_H
#define MENUPAUSE_H

#include "ente.h"

using namespace std;
using namespace sf;

class Jogo;

class MenuPause : public Menu {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Jogo* pJog;
  RectangleShape fundoPainel;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  Fase::Fase* fase;
     RectangleShape fundoEscuro;
     float posBotaoY;

  void atualizarBotoes();

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  MenuPausa(Fase::Fase* fase = nullptr);
  MenuPausa(const IDs::IDs ID, const string nome, Fase::Fase* fase = nullptr);
// dois construtores ~Menu();

  // void executar() override;

  // ===/===/===/===/ Outros  ===/===/===/===/
  virtual void criarBotoes();
     void setFase(Fase::Fase* fase);
     Fase::Fase* getFase();
     virtual void executar();
};

#endif
>>>>>>> ff66d92e029ef284b21b6d9fe650ce0c6efc77bb
*/