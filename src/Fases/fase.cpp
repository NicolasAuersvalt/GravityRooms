#include "Fases/fase.h"

#include <iostream>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Obstaculos/plataforma.h"
#include "Entidades/Personagens/androide.h"
#include "Entidades/Personagens/ciborgue.h"
#include "Entidades/Personagens/clone.h"

using namespace std;
using namespace sf;
using namespace Fases;

// ===/===/===/===/ Obrigatório ===/===/===/===/
<<<<<<<<<Temporary merge branch 1 == == == == =
<<<<<<< HEAD
             >>>>>>>>> Temporary merge branch 2 namespace Fases {
  // Construtor
  Fase::Fase()
      : Ente(),
        // fundo(),
        tripulante(nullptr),
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
        new Entidades::Obstaculos::Centro_Gravidade(
            pos, sf::Vector2f(100.0f, 50.0f));
    if (centro_gravidade == nullptr) {
      std::cout << "Fase::nao foi possivel criar centro de gravidade"
                << std::endl;
      exit(1);
    }

    // plataforma->setTamanho(escala);
    listaObstaculos->incluir(static_cast<Entidade*>(centro_gravidade));
  }

  void Fase::criarEntidades(char letra, const Vector2f pos) {
    if (tripulante == nullptr) {
      criarJogador(Vector2f(100.0f, 800.0f));
    }
    switch (letra) {
      case ('i'): {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);

      } break;
      case ('f'): {
        criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);

        // } break;
        // case ('d'): {
        //   criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
        //   tripulante);

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
    tripulante =
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

  void Fase::criarInimFaceis(const Vector2f pos,
                             Entidades::Personagens::Tripulante* tripulante) {
    Entidades::Personagens::Ciborgue* ciborgue =
        new Entidades::Personagens::Ciborgue(pos, tripulante);
    if (ciborgue == nullptr) {
      cout << "Fase::nao foi possivel criar ciborgue" << endl;
      exit(1);
    }
    listaPersonagens->incluir(static_cast<Entidade*>(ciborgue));
  }

  void Fase::criarInimMedios(const Vector2f pos,
                             Entidades::Personagens::Tripulante* tripulante) {
    Entidades::Personagens::Androide* androide =
        new Entidades::Personagens::Androide(pos, tripulante);
    if (androide == nullptr) {
      std::cout << "Fase::nao foi possivel criar androide" << std::endl;
      exit(1);
    }
    listaPersonagens->incluir(static_cast<Entidade*>(androide));
  }

  // void Fase::criarInimDificeis(const Vector2f pos) {
  //   Entidades::Personagens::Inimigo::Clone* clone =
  //       new Entidades::Personagens::Inimigo::Clone(pos,
  //                                                  sf::Vector2f(50.0f, 50.0f));
  //   if (clone == nullptr) {
  //     std::cout << "Fase::nao foi possivel criar clone" << std::endl;
  //     exit(1);
  //   }
  //   listaPersonagens->incluir(static_cast<Entidade*>(clone));
  // }
  void Fase::executar() {
    // fundo.executar();
    desenhar();
    pColisao->executar();
  }

  // void Fase::gerenciar_colisoes() {}

  // void Fase::criarCenario() {}

  // ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases