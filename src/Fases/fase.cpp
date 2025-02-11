#include "Fases/fase.h"

namespace Fases {

// Construtor
Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo)
    : Ente(ID_Fase), listaPersonagens(new Lista_Entidades()),
      listaObstaculos(new Lista_Entidades()),
      listaBackground(new Lista_Entidades()), tripulantes{nullptr, nullptr},
      pos1(100.0f, 100.0f), pos2(200.0f, 100.0f),
      pColisao(new Gerenciador_Colisoes(listaPersonagens, listaObstaculos)),
      bg(), complete(false) {
  srand(time(nullptr));
}

// Destrutor
Fase::~Fase() {
  if (pColisao) {
    delete (pColisao);
    pColisao = nullptr;
  }

  // Clear queues
  while (!filaInimigosFaceis.empty()) {
    filaInimigosFaceis.pop();
  }
  while (!filaInimigosMedios.empty()) {
    filaInimigosMedios.pop();
  }
  while (!filaInimigosDificeis.empty()) {
    filaInimigosDificeis.pop();
  }
  listaObstaculos->limparLista();
  listaPersonagens->limparLista();
}

string Fase::getTipo() const {
   return "Fase"; 
}

void Fase::criarPlataforma(const Vector2f pos) {
  Plataforma *plataforma =
      new Plataforma(pos, Vector2f(266.0f, 80.0f), IDs::IDs::plataforma);
  if (plataforma == nullptr) {
    cout << "Fase::nao foi possivel criar plataforma" << endl;
    exit(1);
  }

  listaObstaculos->incluir(static_cast<Entidade *>(plataforma));
}

void Fase::criarEspinho(const Vector2f pos) {
  Vector2f adjustedPos = pos;
  adjustedPos.y -= 45.0f;
  Espinho *espinho =
      new Espinho(pos, Vector2f(90.0f, 90.0f), IDs::IDs::espinho);
  if (espinho == nullptr) {
    cout << "Fase::nao foi possivel criar espinho" << endl;
    exit(1);
  }

  listaObstaculos->incluir(static_cast<Entidade *>(espinho));
}

void Fase::criarCentroGravidade(const Vector2f pos) {
  Centro_Gravidade *centro_gravidade = new Centro_Gravidade(
      pos, Vector2f(90.0f, 90.0f), IDs::IDs::centro_gravidade);
  if (centro_gravidade == nullptr) {
    cout << "Fase::nao foi possivel criar centro de gravidade" << endl;
    exit(1);
  }

  listaObstaculos->incluir(static_cast<Entidade *>(centro_gravidade));
}
void Fase::criarEspinhoRetratil(const Vector2f pos) {
  EspinhoRetratil *espinhoRetratil = new EspinhoRetratil(
      pos, Vector2f(90.0f, 90.0f), IDs::IDs::espinhoRetratil);
  if (espinhoRetratil == nullptr) {
    cout << "Fase::nao foi possivel criar centro de gravidade" << endl;
    exit(1);
  }

  listaObstaculos->incluir(static_cast<Entidade *>(espinhoRetratil));
}

void Fase::criarEntidades(char letra, const Vector2f pos) {
  if (tripulantes[0] == nullptr) {
    criarJogador({100.f, 100.f}, 0);
  }

  switch (letra) {
  case ('i'): {
    if (filaInimigosFaceis.size() < MAX_INIMIGOS_INICIAIS) {
      criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
      filaInimigosFaceis.push(pos);
    } else if (filaInimigosMedios.size() < MAX_INIMIGOS_INICIAIS) {
      criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
      filaInimigosMedios.push(pos);
    } else {
      // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
      inimAleatorio = rand() % 2;
      if (inimAleatorio == 0 &&
          filaInimigosFaceis.size() < MAX_INIMIGOS_TOTAL) {
        criarInimFaceis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
        filaInimigosFaceis.push(pos);
      } else if (inimAleatorio == 1 &&
                 filaInimigosMedios.size() < MAX_INIMIGOS_TOTAL) {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
        filaInimigosMedios.push(pos);
      }
    }
    break;
  }

  case ('d'): {
    if (filaInimigosMedios.size() < MAX_INIMIGOS_INICIAIS) {
      criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
      filaInimigosMedios.push(pos);
    } else if (filaInimigosDificeis.size() < MAX_INIMIGOS_INICIAIS) {
      criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
      filaInimigosDificeis.push(pos);
    } else {
      // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
      inimAleatorio = rand() % 2;
      if (inimAleatorio == 0 & filaInimigosMedios.size() < MAX_INIMIGOS_TOTAL) {
        criarInimMedios(Vector2f(pos.x * 50.0f, pos.y * 50.0f), tripulantes[0]);
        filaInimigosMedios.push(pos);
      } else if (inimAleatorio == 1 &
                 filaInimigosDificeis.size() < MAX_INIMIGOS_TOTAL) {
        criarInimDificeis(Vector2f(pos.x * 50.0f, pos.y * 50.0f),
                          tripulantes[0]);
        filaInimigosDificeis.push(pos);
      }
    }
    break;

  } break;
  case ('c'): {
    if (contadorEspinho < 3) {
      criarEspinho(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
      contadorEspinho++;
    } else if (contadorEspinhoRetratil < 3) {
      criarEspinhoRetratil(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
      contadorEspinhoRetratil++;
    } else {
      // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
      obsAleatorio = rand() % 2;
      if (obsAleatorio == 0 && contadorEspinho < 7) {
        criarEspinho(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
        contadorEspinho++;
      } else if (obsAleatorio == 1 && contadorEspinhoRetratil < 7) {
        criarEspinhoRetratil(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
        contadorEspinhoRetratil++;
      }
    }
    break;

  } break;
  case ('#'): {
    criarPlataforma(Vector2f(pos.x * 50.0f, pos.y * 50.0f));

  } break;
  case ('r'): {
    criarEspinhoRetratil(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
  } break;
  case ('g'): {
    criarCentroGravidade(Vector2f(pos.x * 50.0f, pos.y * 51.0f));

  } break;
  case ('k'): {
    if (contadorEspinhoRetratil < 3) {
      criarEspinhoRetratil(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
      contadorEspinhoRetratil++;
    } else if (contadorCg < 2) {
      criarCentroGravidade(Vector2f(pos.x * 50.0f, pos.y * 51.0f));
      contadorCg++;
    } else {
      // Após garantir 3 instâncias de cada tipo, criar aleatoriamente
      obsAleatorio = rand() % 2;
      if (obsAleatorio == 0 && contadorEspinho < 7) {
        criarEspinhoRetratil(Vector2f(pos.x * 50.0f, pos.y * 54.0f));
        contadorEspinhoRetratil++;
      } else if (obsAleatorio == 1 && contadorCg < 7) {
        criarCentroGravidade(Vector2f(pos.x * 50.0f, pos.y * 51.0f));
        contadorCg++;
      }
    }
    break;
  } break;
  case ('b'): {
    criarBackground(getID());
  }
  }
}

void Fase::criarJogador(const Vector2f pos, int index) {
  tripulantes[index] =
      new Tripulante(pos, Vector2f(50.0f, 50.0f), IDs::IDs::tripulante);
  if (tripulantes[index] == nullptr) {
    cerr << "Fase::nao foi possivel criar jogador" << endl;
    exit(1);
  }
  tripulantes[index]->setPlayerOne(index);
  listaPersonagens->incluir(static_cast<Entidade *>(tripulantes[index]));
}
void Fase::desenhar() {
  listaBackground->desenharTodos();
  listaObstaculos->desenharTodos();
  listaPersonagens->desenharTodos();
}

void Fase::criarInimFaceis(const Vector2f pos, Tripulante *tripulante) {
  Ciborgue *ciborgue = new Ciborgue(pos, tripulante, IDs::IDs::ciborgue);
  if (ciborgue == nullptr) {
    cout << "Fase::nao foi possivel criar ciborgue" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade *>(ciborgue));
}

void Fase::criarInimMedios(const Vector2f pos, Tripulante *tripulante) {
  Androide *androide = new Androide(pos, tripulante, IDs::IDs::androide);
  if (androide == nullptr) {
    cout << "Fase::nao foi possivel criar androide" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade *>(androide));
}

void Fase::criarInimDificeis(const Vector2f pos, Tripulante *tripulante) {
  Clone *clone = new Clone(pos, tripulante, IDs::IDs::clone);
  if (clone == nullptr) {
    cout << "Fase::nao foi possivel criar clone" << endl;
    exit(1);
  }
  listaPersonagens->incluir(static_cast<Entidade *>(clone));

  clone->setProjetil(
      criarProjetil(Vector2f(100.0f, 100.0f), IDs::IDs::projetil_inimigo));
}
void Fase::executar() {
   desenhar(); 
  }

Gerenciador_Grafico* Fase::getGerenciador() {
  return GG;
}


Entidades::Projetil *Fase::criarProjetil(const Vector2f pos, IDs::IDs ID) {
  Entidades::Projetil *projetil =
      new Entidades::Projetil(pos, Vector2f(50.0f, 54.0f), ID);
  if (projetil == nullptr) {
    cout << "Fase::nao foi possivel criar projetil" << endl;
    exit(1);
  }

  listaPersonagens->incluir(static_cast<Entidade *>(projetil));
  return projetil;
}
void Fase::criarBackground(const IDs::IDs ID_Fase) {

  // cout << "Criar Background" << endl;

  bg = new Background(Vector2f(0.0f, 0.0f), Vector2f(0.0f, 0.0f), ID_Fase);

  if (bg == nullptr) {
    cout << "Fase::nao foi possivel criar jogador" << endl;
    exit(1);
  }

  bg->setFase(this);

  listaBackground->incluir(static_cast<Entidade *>(bg));
}

bool Fase::isNave() {
  if (getID() == IDs::IDs::fase_nave) {
    return true;
  }
  return false;
}

bool Fase::isLab() {
  if (getID() == IDs::IDs::fase_laboratorio) {
    return true;
  }
  return false;
}

void Fase::setGerenciadorG(Gerenciador_Grafico *GG) {
  if (GG != nullptr)
    this->GG = GG;
}
} // namespace Fases
