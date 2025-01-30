#include "Fases/fase.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {

// Construtor
Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo)
    : Ente(ID_Fase),
      listaPersonagens(new Lista_Entidades()),
      listaObstaculos(new Lista_Entidades()),
      listaBackground(new Lista_Entidades()),
      tripulante(nullptr),
      pColisao(new Gerenciador_Colisoes(listaPersonagens, listaObstaculos)),
      bg(),
      GS() {
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
      new Plataforma(pos, Vector2f(300.0f, 50.0f), IDs::IDs::plataforma);
  if (plataforma == nullptr) {
    cout << "Fase::nao foi possivel criar plataforma" << endl;
    exit(1);
  }

  // plataforma->setTamanho(escala);
  listaObstaculos->incluir(static_cast<Entidade*>(plataforma));
}

void Fase::criarEspinho(const Vector2f pos) {
  Espinho* espinho =
      new Espinho(pos, Vector2f(50.0f, 50.0f), IDs::IDs::espinho);
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
  switch (letra) {
    case ('i'): {
      if (contadorFaceis < 3) {
        criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
        contadorFaceis++;
      } else if (contadorMedios < 3) {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
        contadorMedios++;
      } else {
        // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
        inimAleatorio = rand() % 2;
        if (inimAleatorio == 0 && contadorFaceis < 7) {
          criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
          contadorFaceis++;
        } else if (inimAleatorio == 1 && contadorMedios < 7) {
          criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
          contadorMedios++;
        }
      }
      break;
    }

    case ('d'): {
      if (contadorMedios < 3) {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
        contadorMedios++;
      } else if (contadorDificeis < 3) {
        criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
        contadorDificeis++;
      } else {
        // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
        inimAleatorio = rand() % 2;
        if (inimAleatorio == 0 && contadorMedios < 7) {
          criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
          contadorMedios++;
        } else if (inimAleatorio == 1 && contadorDificeis < 7) {
          criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulante);
          contadorDificeis++;
        }
      }
      break;

    } break;
    case ('k'): {  // PARA TESTES, REMOVER DEPOIS
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
      if (tripulante == nullptr) {
        criarJogador(Vector2f(100.0f, 100.0f));
        criarProjetil(Vector2f(100.0f, 100.0f));
      }
      listaPersonagens->incluir(static_cast<Entidade*>(tripulante));
    } break;
    case ('b'): {
      criarBackground();
    }
  }
}

void Fase::criarJogador(const Vector2f pos) {
  tripulante =
      new Tripulante(pos, Vector2f(50.0f, 50.0f), IDs::IDs::tripulante);

  if (tripulante == nullptr) {
    cout << "Fase::nao foi possivel criar jogador" << endl;
    exit(1);
  }
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
  Projetil* projetil =
      new Projetil(pos, Vector2f(50.0f, 50.0f), IDs::IDs::projetil_tripulante);

  if (projetil == nullptr) {
    cout << "Fase::nao foi possivel criar projetil" << endl;
    exit(1);
  }

  listaPersonagens->incluir(static_cast<Entidade*>(projetil));
  tripulante->setProjetil(projetil);

  for (int i = 0; i < listaPersonagens->getTamanho(); i++) {
    Entidade* entidade = listaPersonagens->getElemento(i);
    if (entidade && entidade->getID() == IDs::IDs::clone) {
      Clone* clone = dynamic_cast<Clone*>(entidade);
      if (clone) {
        clone->setProjetil(projetil);
      }
    }
  }

  cout << "criacao do projetil2 " << endl;
}
// void Fase::setLimiteCamera(IntRect limiteCamera) {
//   this->limiteCamera = limiteCamera;
// }

// const IntRect Fase::getLimiteCamera() const { return limiteCamera; }

// void Fase::gerenciar_colisoes() {}

// void Fase::criarCenario() {}

// ===/===/===/===/ Outros  ===/===/===/===/

}  // namespace Fases
