#include "Fases/fase.h"

#include <iostream>

using namespace std;
using namespace Fases;

// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {
// Construtor
Fase::Fase()
    : Ente(),
      // fundo(),
      listaPersonagens(new Listas::Lista_Entidades()),
      listaObstaculos(new Listas::Lista_Entidades()),
      pColisao(new Gerenciadores::Gerenciador_Colisoes()) {
  if (pColisao == nullptr) {
    std::cout
        << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao"
        << std::endl;
    exit(1);
  }
}

// Destrutor
Fase::~Fase() {
  if (pColisao) {
    delete (pColisao);
    pColisao = nullptr;
  }
  listaObstaculos->limparLista();
  listaPersonagens->limparLista();
}

void Fase::executar() {}

// void Fase::gerenciar_colisoes() {}

// void Fase::cirarInimFaceis() {}

// void Fase::criarPlataformas() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases