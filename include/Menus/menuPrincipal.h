
#pragma once

#include "Menus/menu.h"

namespace Menus {

class MenuPrincipal : public Menu {
 private:
 public:
  MenuPrincipal();
  MenuPrincipal(const IDs::IDs ID, std::string nome,
                const unsigned int tamFonte = 180);
  virtual ~MenuPrincipal();
  void criarBotoes();
  void executar();
};

}  // namespace Menus