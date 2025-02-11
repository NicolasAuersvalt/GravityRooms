
#ifndef MENUGAMEOVER_H
#define MENUGAMEOVER_H
#include <fstream>
#include <vector>

#include "../json.hpp"
#include "Menus/Botoes/texto.h"
#include "Menus/menu.h"

using namespace std;
using namespace sf;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  10
// =====/=====/=====/=====/=====/=====/

namespace Menus {

class MenuGameOver : public Menu {
private:
  void carregarMenuGameOver();
  void exibirMenuGameOver();
  vector<Botoes::Texto> rankingTexts;
  string nome;
  Botoes::Texto texto;
  int pontuacao;

public:
  MenuGameOver(const IDs::IDs id);
  MenuGameOver(const IDs::IDs ID, string nome,
               const unsigned int tamFonte = 180);
  virtual ~MenuGameOver();
  void addCaracter(char caracter);
  void criarBotoes() override;
  void executar();
  void salvarColocacao(int pontos);
  void setPlayerData(const string &playerName, int score);
  
};

} // namespace Menus
#endif