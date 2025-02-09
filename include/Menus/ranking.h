
#ifndef RANKING_H
#define RANKING_H
#include <fstream>
#include <vector>

#include "../json.hpp"
#include "Menus/menu.h"
namespace Menus {

class Ranking : public Menu {
private:
  void carregarRanking();
  void exibirRanking();
  vector<Botoes::Texto> rankingTexts;

public:
  Ranking(const IDs::IDs id);
  Ranking(const IDs::IDs ID, string nome,
          const unsigned int tamFonte = 180);
  virtual ~Ranking();
  void criarBotoes();
  void executar();
};

} // namespace Menus
#endif