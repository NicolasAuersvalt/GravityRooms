// #ifndef SAVE_H
// #define SAVE_H

// #include <filesystem>
// #include <fstream>
// #include <iostream>
// #include <mutex>

// #include "Entidades/Personagens/tripulante.h"
// #include "Gerenciadores/gerenciador_json.h"
// #include "json.hpp"

// using json = nlohmann::json;
// using namespace std;
// using namespace sf;

// using Gerenciadores::Gerenciador_Json;

// namespace Entidades::Personagens {
// class Tripulante;
// }

// class Save : public Gerenciador_Json {
//  private:
//   Entidades::Personagens::Tripulante* pJog1;
//   Dados dados;

//  public:
//   Save();
//   ~Save();

//   void setJogador(Entidades::Personagens::Tripulante* jogador);
//   Entidades::Personagens::Tripulante* getJogador();

//   void salvar();
//   void gravarDados();
//   void carregar();

//   const Dados& getDados() const { return dados; }
// };

// #endif