
#ifndef MENUGAMEOVER_H
#define MENUGAMEOVER_H
#include <fstream>
#include <vector>

#include "../json.hpp"
#include "Menus/Botoes/texto.h"
#include "Menus/menu.h"

namespace Menus {

class MenuGameOver : public Menu {
 private:
  void carregarMenuGameOver();
  void exibirMenuGameOver();
  std::vector<Botoes::Texto> rankingTexts;
  std::string nome;
  Botoes::Texto texto;
  int pontuacao;

 public:
  MenuGameOver(const IDs::IDs id);
  MenuGameOver(const IDs::IDs ID, std::string nome,
               const unsigned int tamFonte = 180);
  virtual ~MenuGameOver();
  void addCaracter(char caracter);
  void criarBotoes() override;
  void executar();
  void salvarColocacao(int pontos);
  void setPlayerData(const std::string& playerName, int score) {
    nome = playerName;
    pontuacao = score;
  }
};

}  // namespace Menus
#endif