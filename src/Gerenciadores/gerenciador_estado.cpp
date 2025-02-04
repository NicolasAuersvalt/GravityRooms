#include "Gerenciadores/gerenciador_estado.h"

namespace Gerenciadores {

GerenciadorEstado *GerenciadorEstado::pGerenciadorEstado = nullptr;

GerenciadorEstado::GerenciadorEstado() : pilhaEstados() {}

GerenciadorEstado *GerenciadorEstado::getGerenciadorEstado() {
  if (pGerenciadorEstado == nullptr) {
    pGerenciadorEstado = new GerenciadorEstado();
  }
  return pGerenciadorEstado;
}

GerenciadorEstado::~GerenciadorEstado() {
  // deleta todos os estados da minha pilha
  while (!pilhaEstados.empty()) {
    pilhaEstados.pop();
  }

  if (pGerenciadorEstado) {
    delete pGerenciadorEstado;
    pGerenciadorEstado = nullptr;
  }
}

void GerenciadorEstado::ativarObservadores() {
  // Ativa os observaores que estavam no estado atenrior
  int estadoAtual = getEstadoAtual();
}

void GerenciadorEstado::desativarObservadores() {
  // desativa os observaores que estavam no estado anterior
  int estadoAtual = getEstadoAtual();
}
void GerenciadorEstado::addEstado(const int ID) {
  if (!pilhaEstados.empty()) {
    desativarObservadores();
  }
  int *estado = new int(ID);
  pilhaEstados.push(estado);
}
void GerenciadorEstado::removerEstado() {
  if (!pilhaEstados.empty()) {
    int *estado = pilhaEstados.top();
    delete estado;
    pilhaEstados.pop();
  }
}

void GerenciadorEstado::removerEstado(const int qtd) {
  int i = 0;
  while (!pilhaEstados.empty() && i < qtd) {
    pilhaEstados.pop();
    i++;
  }
}
int GerenciadorEstado::getEstadoAtual() {
  if (!pilhaEstados.empty()) {
    return *(pilhaEstados.top());
  }
  return -1;
}

int *GerenciadorEstado::getEstado(const int qtdRemove) {
  std::stack<int *> pilhaEstadoAux = pilhaEstados;
  int i = 0;
  while (i < qtdRemove && !pilhaEstadoAux.empty()) {
    pilhaEstadoAux.pop();
    i++;
  }
  if (!pilhaEstadoAux.empty()) {
    return pilhaEstadoAux.top();
  }
  return nullptr;
}

void GerenciadorEstado::executar() {
  // executa o estado que está no topo da minha pilha
  if (!pilhaEstados.empty()) {
    int estado = *(pilhaEstados.top());
    switch (estado) {
    case 1:
      // Execute ações do menu principal
      break;
    case 2:
      // Execute ações do menu de pausa
      break;
      // Adicione outros casos conforme necessário
    default:
      std::cout << "Estado desconhecido: " << estado << std::endl;
      break;
    }
  }
}

} // namespace Gerenciadores
