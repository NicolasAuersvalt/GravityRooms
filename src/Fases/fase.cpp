#include "Fases/fase.h"

#include <iostream>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Obstaculos/plataforma.h"

using namespace std;
using namespace sf;
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

void Fase::criarEspinho(const Vector2f pos) {
  Entidades::Obstaculos::Espinho* espinho =
      new Entidades::Obstaculos::Espinho(pos, sf::Vector2f(50.0f, 50.0f));
  if (espinho == nullptr) {
    std::cout << "Fase::nao foi possivel criar espinho" << std::endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(espinho));
}

void Fase::criarCentroGravidade(const Vector2f pos) {
  Entidades::Obstaculos::Centro_Gravidade* centro_gravidade =
      new Entidades::Obstaculos::Centro_Gravidade(pos,
                                                  sf::Vector2f(100.0f, 50.0f));
  if (centro_gravidade == nullptr) {
    std::cout << "Fase::nao foi possivel criar centro de gravidade"
              << std::endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(centro_gravidade));
}

void Fase::criarEntidades(char letra, const Vector2f pos) {
  switch (letra) {
    // case ('i'): {
    //   criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    // } break;
    case ('c'): {
      criarEspinho(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    } break;
    case ('#'): {
      criarPlataforma(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    } break;
    case ('j'): {
      criarJogador(Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
  }
}

void Fase::criarJogador(const Vector2f pos) {
  Entidades::Personagens::Tripulante* tripulante =
      new Entidades::Personagens::Tripulante(pos, sf::Vector2f(50.0f, 50.0f));
  if (tripulante == nullptr) {
    std::cout << "Fase::nao foi possivel criar jogador" << std::endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(tripulante));
}
void Fase::desenhar() {
  listaObstaculos->desenharTodos();
  listaPersonagens->desenharTodos();
}
void Fase::executar() {
  // fundo.executar();
  desenhar();
  pColisao->executar();
}

// void Fase::gerenciar_colisoes() {}

void Fase::criarInimFaceis() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases