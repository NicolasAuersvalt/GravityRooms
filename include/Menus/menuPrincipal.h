
#pragma once

#include "Menus/menu.h"

using namespace std;
using namespace sf;

namespace Menus {

class MenuPrincipal : public Menu {
private:
public:
  MenuPrincipal(IDs::IDs id);
  MenuPrincipal(const IDs::IDs ID, string nome,
                const unsigned int tamFonte = 180);
  virtual ~MenuPrincipal();
  void criarBotoes();
  void executar();
  void criarFundo() override;
};

} // namespace Menus
