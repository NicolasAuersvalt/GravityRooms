#include "Fases/fase.h"

#include <iostream>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Obstaculos/plataforma.h"
#include "Entidades/Personagens/androide.h"
#include "Entidades/Personagens/ciborgue.h"
#include "Entidades/Personagens/clone.h"
#include "Gerenciadores/gerenciador_colisoes.h"


// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {

// Construtor
Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo)
    : Ente(ID_Fase),
      listaPersonagens(new Listas::Lista_Entidades()),
      listaObstaculos(new Listas::Lista_Entidades()),
      tripulante(nullptr),
      pColisao(new Gerenciadores::Gerenciador_Colisoes(listaPersonagens,
                                                       listaObstaculos)) 
                                                       {
  // ...existing code...
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
      new Entidades::Obstaculos::Plataforma(pos, sf::Vector2f(300.0f, 50.0f),
                                            IDs::IDs::plataforma);
  if (plataforma == nullptr) {
    std::cout << "Fase::nao foi possivel criar plataforma" << std::endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(plataforma));
}

void Fase::criarEspinho(const Vector2f pos) {
  Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(
      pos, sf::Vector2f(50.0f, 50.0f), IDs::IDs::espinho);
  if (espinho == nullptr) {
    std::cout << "Fase::nao foi possivel criar espinho" << std::endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(espinho));
}

void Fase::criarCentroGravidade(const Vector2f pos) {
  Entidades::Obstaculos::Centro_Gravidade* centro_gravidade =
      new Entidades::Obstaculos::Centro_Gravidade(
          pos, sf::Vector2f(90.0f, 90.0f), IDs::IDs::centro_gravidade);
  if (centro_gravidade == nullptr) {
    std::cout << "Fase::nao foi possivel criar centro de gravidade"
              << std::endl;
    exit(1);
  }

  listaObstaculos->incluir(static_cast<Entidade*>(centro_gravidade));
}

void Fase::criarEntidades(char letra, const Vector2f pos) {
  if (tripulante == nullptr) {
    criarJogador(Vector2f(100.0f, 100.0f));
    criarProjetil(Vector2f(100.0f, 100.0f));
  }
  switch (letra) {
    case ('i'): {
      criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);

    } break;
    case ('f'): {
      criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);

    } break;
    case ('d'): {
      criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);

    } break;
    case ('c'): {
      criarEspinho(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    } break;
    case ('#'): {
      criarPlataforma(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    } break;
    case ('g'): {
      criarCentroGravidade(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    } break;
    case ('j'): {
      listaPersonagens->incluir(static_cast<Entidade*>(tripulante));
    }
  }
}

void Fase::criarJogador(const Vector2f pos) {
  tripulante = new Entidades::Personagens::Tripulante(
      pos, sf::Vector2f(50.0f, 50.0f), IDs::IDs::tripulante);
  if (tripulante == nullptr) {
    std::cout << "Fase::nao foi possivel criar jogador" << std::endl;
    exit(1);
  }
}
void Fase::desenhar() {
  listaObstaculos->desenharTodos();
  listaPersonagens->desenharTodos();
}

void Fase::criarInimFaceis(const Vector2f pos,
                           Entidades::Personagens::Tripulante* tripulante) {
  Entidades::Personagens::Ciborgue* ciborgue =
      new Entidades::Personagens::Ciborgue(pos, tripulante, IDs::IDs::ciborgue);
  if (ciborgue == nullptr) {
    cout << "Fase::nao foi possivel criar ciborgue" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(ciborgue));
}

void Fase::criarInimMedios(const Vector2f pos,
                           Entidades::Personagens::Tripulante* tripulante) {
  Entidades::Personagens::Androide* androide =
      new Entidades::Personagens::Androide(pos, tripulante, IDs::IDs::androide);
  if (androide == nullptr) {
    std::cout << "Fase::nao foi possivel criar androide" << std::endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(androide));
}

void Fase::criarInimDificeis(const Vector2f pos,
                             Entidades::Personagens::Tripulante* tripulante) {
  Entidades::Personagens::Clone* clone =
      new Entidades::Personagens::Clone(pos, tripulante, IDs::IDs::clone);
  if (clone == nullptr) {
    cout << "Fase::nao foi possivel criar clone" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(clone));
}
void Fase::executar() {
  // fundo.executar();
  // pJogador = getTripulante();
  // if (pJogador) {

  //   pGrafico->atualizarCamera(pJogador->getPos(), pJogador->getTam());
  //}
  desenhar();
}

void Fase::criarProjetil(const Vector2f pos) {
  cout << "criacao do projetil " << endl;
  Entidades::Projetil* projetil = new Entidades::Projetil(
      pos, sf::Vector2f(50.0f, 50.0f), IDs::IDs::projetil_tripulante);
  if (projetil == nullptr) {
    std::cout << "Fase::nao foi possivel criar projetil" << std::endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(projetil));
  tripulante->setProjetil(projetil);
  cout << "criacao do projetil2 " << endl;
}
// void Fase::setLimiteCamera(sf::IntRect limiteCamera) {
//   this->limiteCamera = limiteCamera;
// }

// const sf::IntRect Fase::getLimiteCamera() const { return limiteCamera; }

// void Fase::gerenciar_colisoes() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases
