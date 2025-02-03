#include "Fases/fase.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {

// Construtor
Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo)
    : Ente(ID_Fase),
      listaPersonagens(new Lista_Entidades()),
      listaObstaculos(new Lista_Entidades()),
      listaBackground(new Lista_Entidades()),
      tripulantes{nullptr, nullptr},
      pos1(100.0f, 100.0f),
      pos2(200.0f, 100.0f),
      pColisao(new Gerenciador_Colisoes(listaPersonagens, listaObstaculos)),
      bg(),
      complete(false) {
  srand(time(nullptr));
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
  Plataforma* plataforma =
      new Plataforma(pos, Vector2f(266.0f, 80.0f), IDs::IDs::plataforma);
  if (plataforma == nullptr) {
    cout << "Fase::nao foi possivel criar plataforma" << endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(plataforma));
}

void Fase::criarEspinho(const Vector2f pos) {
  Vector2f adjustedPos = pos;
  adjustedPos.y -= 45.0f;
  Espinho* espinho =
      new Espinho(pos, Vector2f(90.0f, 90.0f), IDs::IDs::espinho);
  if (espinho == nullptr) {
    cout << "Fase::nao foi possivel criar espinho" << endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(espinho));
}

void Fase::criarCentroGravidade(const Vector2f pos) {
  Centro_Gravidade* centro_gravidade = new Centro_Gravidade(
      pos, Vector2f(90.0f, 90.0f), IDs::IDs::centro_gravidade);
  if (centro_gravidade == nullptr) {
    cout << "Fase::nao foi possivel criar centro de gravidade" << endl;
    exit(1);
  }

  listaObstaculos->incluir(static_cast<Entidade*>(centro_gravidade));
}

void Fase::criarEntidades(char letra, const Vector2f pos) {
  if (tripulantes[0] == nullptr) {
    criarJogador({100.f, 100.f}, 0);  // Create player 1
    tripulantes[0]->setProjetil(
        criarProjetil(pos, IDs::IDs::projetil_tripulante));
  }
  // if (tripulantes[1] == nullptr) {
  //   criarJogador({150.f, 100.f}, 1);  // Create player 2
  //   tripulantes[1]->setProjetil(
  //       criarProjetil(pos, IDs::IDs::projetil_tripulante));
  // }
  switch (letra) {
    case ('i'): {
      if (contadorFaceis < 3) {
        criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
        contadorFaceis++;
      } else if (contadorMedios < 3) {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
        contadorMedios++;
      } else {
        // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
        inimAleatorio = rand() % 2;
        if (inimAleatorio == 0 && contadorFaceis < 7) {
          criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
                          tripulantes[0]);
          contadorFaceis++;
        } else if (inimAleatorio == 1 && contadorMedios < 7) {
          criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
                          tripulantes[0]);
          contadorMedios++;
        }
      }
      break;
    }

    case ('d'): {
      if (contadorMedios < 3) {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
        contadorMedios++;
      } else if (contadorDificeis < 3) {
        criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
                          tripulantes[0]);
        contadorDificeis++;
      } else {
        // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
        inimAleatorio = rand() % 2;
        if (inimAleatorio == 0 && contadorMedios < 7) {
          criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
                          tripulantes[0]);
          contadorMedios++;
        } else if (inimAleatorio == 1 && contadorDificeis < 7) {
          criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
                            tripulantes[0]);
          contadorDificeis++;
        }
      }
      break;

    } break;
    case ('k'): {  // PARA TESTES, REMOVER DEPOIS
      criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);

    } break;
    case ('l'): {  // PARA TESTES, REMOVER DEPOIS
      criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);

    } break;
    case ('c'): {
      criarEspinho(Vector2f(pos.x * 50.0f, pos.y * 54.0f));

    } break;
    case ('#'): {
      criarPlataforma(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

    } break;
    case ('g'): {
      criarCentroGravidade(Vector2f(pos.x * 50.0f, pos.y * 51.0f));

    } break;
    case ('j'): {
      // listaPersonagens->incluir(static_cast<Entidade*>(tripulantes[0]));
    } break;
    case ('b'): {
      criarBackground();
    }
  }
}

void Fase::criarJogador(const Vector2f pos, int index) {
  cout << "imprimindo jogador" << endl;
  tripulantes[index] =
      new Tripulante(pos, Vector2f(50.0f, 50.0f), IDs::IDs::tripulante, index);
  if (tripulantes[index] == nullptr) {
    std::cerr << "Fase::nao foi possivel criar jogador" << std::endl;
    exit(1);
  }

  listaPersonagens->incluir(static_cast<Entidade*>(tripulantes[index]));
}
void Fase::desenhar() {
  listaBackground->desenharTodos();
  listaObstaculos->desenharTodos();
  listaPersonagens->desenharTodos();
}

void Fase::criarInimFaceis(const Vector2f pos, Tripulante* tripulante) {
  Ciborgue* ciborgue = new Ciborgue(pos, tripulante, IDs::IDs::ciborgue);
  if (ciborgue == nullptr) {
    cout << "Fase::nao foi possivel criar ciborgue" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(ciborgue));
}

void Fase::criarInimMedios(const Vector2f pos, Tripulante* tripulante) {
  Androide* androide = new Androide(pos, tripulante, IDs::IDs::androide);
  if (androide == nullptr) {
    cout << "Fase::nao foi possivel criar androide" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(androide));
}

void Fase::criarInimDificeis(const Vector2f pos, Tripulante* tripulante) {
  Clone* clone = new Clone(pos, tripulante, IDs::IDs::clone);
  if (clone == nullptr) {
    cout << "Fase::nao foi possivel criar clone" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade*>(clone));

  clone->setProjetil(
      criarProjetil(Vector2f(100.0f, 100.0f), IDs::IDs::projetil_inimigo));
  std::cout << "Fase:: foi possivel criar inim dificil" << std::endl;
}
void Fase::executar() {
  // fundo.executar();
  // pJogador = getTripulante();
  // if (pJogador) {

  //   pGrafico->atualizarCamera(pJogador->getPos(), pJogador->getTam());
  //}
  desenhar();
}

Entidades::Projetil* Fase::criarProjetil(const Vector2f pos, IDs::IDs ID) {
  Entidades::Projetil* projetil =
      new Entidades::Projetil(pos, sf::Vector2f(50.0f, 54.0f), ID);
  if (projetil == nullptr) {
    std::cout << "Fase::nao foi possivel criar projetil" << std::endl;
    exit(1);
  }

  listaPersonagens->incluir(static_cast<Entidade*>(projetil));
  return projetil;
}
// void Fase::setLimiteCamera(IntRect limiteCamera) {
//   this->limiteCamera = limiteCamera;
// }

// const IntRect Fase::getLimiteCamera() const { return limiteCamera; }

// void Fase::gerenciar_colisoes() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases
