#include "Fases/fase.h"

#include <iostream>

#include "Entidades/Obstaculos/plataforma.h"

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

void Fase::criarPlataforma(const Vector2f pos) {
  Entidades::Obstaculos::Plataforma* plataforma =
      new Entidades::Obstaculos::Plataforma(pos, sf::Vector2f(300.0f, 50.0f));
  if (plataforma == nullptr) {
    std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(plataforma));
}

void Fase::executar() {}

// void Fase::gerenciar_colisoes() {}

// void Fase::cirarInimFaceis() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases