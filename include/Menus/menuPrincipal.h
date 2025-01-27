/*
#pragma once

#include "../Parallax/Fundo.hpp"
#include "menu.h"

#define CAMINHO_TEXTURA_MENU_PRINCIPAL "Jungle++/img/Menu/menuPrincipal.png"

namespace Jungle {

    namespace Menu {

        class MenuPrincipal: public Menu {
        protected:
            //Parallax::Fundo fundo;

        private:
            //void criarFundo();

        public:
            MenuPrincipal();
            MenuPrincipal(const IDs::IDs ID, std::string nome, const unsigned
int tamFonte = 180); virtual ~MenuPrincipal(); virtual void criarBotoes();
            virtual void executar();
        };

    }

}
*/
// #pragma once
// #include "Menus/menu.h"

// namespace Menus {

// class MenuPrincipal : public Menu {
//  public:
//   MenuPrincipal();
//   ~MenuPrincipal() = default;
// };

// }  // namespace Menus

// #pragma once

// #include "Menus/menu.h"
// #include "States/State.h"

// namespace States {
//     class Game;
// }

// namespace Menus {

//     class MainMenuState : public Menu, public States::State {
//     private:
//         States::Game* pGame;
//         GraphicalElements::Text title;

//     public:
//         MainMenuState(States::Game* pG = nullptr);

//         ~MainMenuState();

//         void update(const float dt);

//         void render();

//         void resetState();

//         void exec();
//     };

// }