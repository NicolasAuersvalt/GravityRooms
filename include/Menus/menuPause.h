
#ifndef MENUPAUSE_H
#define MENUPAUSE_H

#include "Menus/menu.h"

namespace Menus {

class MenuPause : public Menu {
private:
public:
  MenuPause(const IDs::IDs id);
  MenuPause(const IDs::IDs ID, std::string nome,
            const unsigned int tamFonte = 180);
  virtual ~MenuPause();
  void criarBotoes();
  void executar();
};

} // namespace Menus
#endif