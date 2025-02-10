// #ifndef DADOS_H
// #define DADOS_H

// #include <iostream>
// #include <string>
// #include <utility>

// using namespace std;

// class Dados {
//  private:
//   string level;
//   Vector2f player2Pos;
//   int player2Health;
//   string nome, local;
//   int pontos;
//   float x, y;  // Mantenha o tipo float se você deseja usar valores decimais

//  public:
//   // Construtor padrão
//   Dados() : nome(""), pontos(0), x(0), y(0) {}

//   // Destruidor
//   ~Dados() {}

//   // Setters e getters
//   void setNome(const string& nome) {
//     this->nome = nome;  // Adicionando o ponto e vírgula
//   }

//   const string getNome() const {  // Melhor adicionar const para indicar que
//   o
//                                   // método não altera o objeto
//     return nome;                  // Adicionando o ponto e vírgula
//   }

//   // Setters e getters
//   void setLocal(const string& local) {
//     this->local = local;  // Adicionando o ponto e vírgula
//   }

//   const string getLocal() const {  // Melhor adicionar const para indicar que
//   o
//                                    // método não altera o objeto
//     return local;                  // Adicionando o ponto e vírgula
//   }

//   void setPos(pair<int, int> pos) {
//     x = static_cast<float>(pos.first);   // Cast para garantir que x seja
//     float y = static_cast<float>(pos.second);  // Cast para garantir que y
//     seja float
//   }

//   pair<int, int> getPos() const {  // Adicionando const para indicar que o
//                                    // método não altera o objeto
//     return make_pair(static_cast<int>(x),
//                      static_cast<int>(y));  // Convertendo de float para int
//   }

//   void setPontos(int pontos) { this->pontos = pontos; }

//   int getPontos() const { return pontos; }

//   void setLevel(const string& lvl) { level = lvl; }
//   void setPlayer2Pos(Vector2f pos) { player2Pos = pos; }
//   void setPlayer2Health(int health) { player2Health = health; }
// };

// #endif