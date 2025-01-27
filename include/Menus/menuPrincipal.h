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