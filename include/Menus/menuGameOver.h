
#ifndef MENUGAMEOVER_H
#define MENUGAMEOVER_H

#include "Menus/menu.h"

namespace Menus {

class MenuGameOver : public Menu {
 private:
 public:
  MenuGameOver(const IDs::IDs id);
  MenuGameOver(const IDs::IDs ID, std::string nome,
               const unsigned int tamFonte = 180);
  virtual ~MenuGameOver();
  void criarBotoes();
  void executar();
};

}  // namespace Menus
#endif