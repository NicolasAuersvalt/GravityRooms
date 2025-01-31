#include "Listas/lista_entidades.h"

#include <setjmp.h>

#include <csignal>
#include <iostream>
namespace {
jmp_buf jumpBuffer;

void segfaultHandler(int signal) {
  std::cerr << "Caught segmentation fault!" << std::endl;
  longjmp(jumpBuffer, 1);
}
}  // namespace
namespace Listas {

Lista_Entidades::Lista_Entidades() {
  // cout << "Construtor de Lista_Entidades" << endl;
  LEs = new Lista<Entidade>();
}

// Destrutor
Lista_Entidades::~Lista_Entidades() {
  limparLista();
  delete LEs;
  LEs = nullptr;
}
// Incluir uma Entidade na lista
void Lista_Entidades::incluir(Entidade* pE) { LEs->incluir(pE); }

// Percorrer todos os elementos da lista e desenhar cada um
void Lista_Entidades::desenharTodos() {
  // cout << "Desenhando todos os elementos..." << endl;

  LEs->percorrerLista([](Entidade* entidade) {
    entidade->desenhar();  // Chama o método desenhar() de cada Entidadep
  });
}

void Lista_Entidades::atualizarTodas() {
  if (!LEs) {
    std::cout << "LE NULO" << std::endl;
    return;
  }

  // Install signal handler
  signal(SIGSEGV, segfaultHandler);

  auto updateFunction = [](Entidade* entidade) {
    if (!entidade) {
      std::cout << "Entidade nula encontrada!" << std::endl;
      return;
    }
    std::cout << "Entidade  encontrada!" << std::endl;

    if (setjmp(jumpBuffer) == 0) {
      try {
        std::cout << "Processing entity ID: "
                  << static_cast<int>(entidade->getID()) << std::endl;
        entidade->mover();
        entidade->atualizarPosicao();
      } catch (const std::exception& e) {
        std::cerr << "Error updating entity: " << e.what() << std::endl;
      }
    } else {
      std::cerr << "Recovered from segfault while processing entity"
                << std::endl;
    }
  };

  LEs->percorrerLista(updateFunction);

  // Restore default signal handler
  signal(SIGSEGV, SIG_DFL);
}
void Lista_Entidades::limparLista() {
  if (LEs) {
    LEs->limpar();
  }
}

const int Lista_Entidades::getTamanho() { return LEs->getTam(); }

Entidades::Entidade* Listas::Lista_Entidades::operator[](int pos) {
  return LEs->operator[](pos);
}

void Lista_Entidades::removerEntidade(Entidade* entidade, const bool deletar) {
  if (entidade && LEs) {
    LEs->removerElemento(entidade, deletar);
  }
}
Entidade* Listas::Lista_Entidades::getElemento(int pos) {
  // return objListaEntidade.operator[](pos);
  return LEs->operator[](pos);
}
}  // namespace Listas
