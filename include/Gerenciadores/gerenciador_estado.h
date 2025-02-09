#ifndef GERENCIADOR_ESTADO_H
#define GERENCIADOR_ESTADO_H
// Gerenciadores
#include "Gerenciadores/gerenciador_grafico.h"

// Pilha
#include <stack>

using namespace std;
using namespace sf;

namespace Gerenciadores {

class GerenciadorEstado {
private:
  stack<int *> pilhaEstados;
  static GerenciadorEstado *pGerenciadorEstado;
  GerenciadorEstado();
  void desativarObservadores();
  void ativarObservadores();

public:
  ~GerenciadorEstado();
  static GerenciadorEstado *getGerenciadorEstado();
  void executar();
  int *getEstado(const int qtdRemove);
  void addEstado(const int ID);
  void removerEstado(const int qtd);
  void removerEstado();
  int getEstadoAtual();
};

} // namespace Gerenciadores

#endif
