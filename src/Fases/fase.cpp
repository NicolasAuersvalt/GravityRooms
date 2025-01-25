#include "Fases/fase.h"

#include <iostream>

using namespace std;
using namespace Fases;

// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {
// Construtor
Fase::Fase()
    : Ente(),
      fundo(),
      listaPersonagens(new Lista::ListaEntidade()),
      listaObstaculos(new Lista::ListaEntidade()),
      pColisao(new Gerenciador::Gerenciador_Colisoes(&listaPersonagens,
                                                     &listaObstaculos)) {
  if (pColisao == nullptr) {
    std::cout
        << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao"
        << std::endl;
    exit(1);
  }
}

// Destrutor
Fase::~Fase() {}

void Fase::executar() {}

// void Fase::gerenciar_colisoes() {}

// void Fase::cirarInimFaceis() {}

// void Fase::criarPlataformas() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases