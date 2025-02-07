#include "Entidades/Personagens/tripulante.h"

#include <SFML/Graphics.hpp>

using namespace Entidades::Personagens;

namespace Entidades::Personagens {

REGISTRAR_CLASSE(Tripulante, "tripulante");
Tripulante::Tripulante(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID)
    : Personagem(pos, tam, ID), pontos(0), GF(pos) {
  projetil = new Projetil(Vector2f(-1000, -1000), Vector2f(50, 25),
                          IDs::IDs::projetil_tripulante);
  setSprite("assets/tripulante.png", pos.x, pos.y);
  setTamanho(Vector2f(getSprite().getTexture()->getSize().x,
                      getSprite().getTexture()->getSize().y));
  vivo = true;
  tempoSemColisao = 0.0f;
  noChao = false;
  sprite.setPosition(pos.x, pos.y);
  setMunicao(40);
<<<<<<< HEAD
  
=======
  projetil = new Projetil(pos, sf::Vector2f(50.0f, 54.0f),
                          IDs::IDs::projetil_tripulante);
  setProjetil(projetil);
>>>>>>> psave
}

Tripulante::~Tripulante() {}

void Tripulante::setGerenciadorEvento(Gerenciador_Eventos *GE) {
  if (GE) {
    this->GE = GE; // Atribui o ponteiro GE à variável membro this->GE
  }
}

void Tripulante::tirarMunicao() { municao--; }

int Tripulante::getMunicao() { return municao.getQtd(); }

void Tripulante::setMunicao(int qtd) { municao.setQtd(qtd); }

void Tripulante::mover() {
<<<<<<< HEAD
  // cair();
  // // Movimentação (sem física, apenas mover pela tela)
  // string tecla = GE->isTeclaPressionada(sf::Keyboard::Left);
  // if (tecla == "Left Arrow") {
  //   getSprite().move(-5.f, 0.f);  // Move para a esquerda
  // }
  // tecla = GE->isTeclaPressionada(sf::Keyboard::Q);
  // if (tecla == "Q" && noChao) {
  //   // Jump only if on ground
  //   atirar();  // o correto

  // }
  // tecla = GE->isTeclaPressionada(sf::Keyboard::Right);
  // if (tecla == "Right Arrow") {
  //   getSprite().move(5.f, 0.f);  // Move para a direita
  // }

  // tecla = GE->isTeclaPressionada(sf::Keyboard::Space);
  // if (tecla == "Space" && noChao) {
  //   // Jump only if on ground
  //   float jumpForce = -20.0f;  // controle do pulo
  //   velFinal.y = jumpForce;
  //   noChao = false;
  // }
  // if (!noChao) {
  //   // Apply gravity
  //   float dt = 0.016f;  // Assuming 60fps, adjust if using different time
  //   step velFinal.y += GF.aplicarGravidade() * dt;
  // }
  // getSprite().move(velFinal.x, velFinal.y);
  // // Apply movement

  /*----------------------------------------------------------------*/
  // Jogador 1 (WASD + Espaço)
=======
  // Jogador 1 (WASD + Q)
>>>>>>> psave
  cair();
  if (isPlayerOne) {
    string tecla = GE->isTeclaPressionada(sf::Keyboard::A);
    if (tecla == "A") {
      getSprite().move(-5.f, 0.f); // Move para a esquerda
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::D);
    if (tecla == "D") {
      getSprite().move(5.f, 0.f); // Move para a direita
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::W);
    if (tecla == "W" && noChao) {
<<<<<<< HEAD
      // Jump only if on ground
=======
>>>>>>> psave
      float jumpForce = -12.0f; // controle do pulo
      velFinal.y = jumpForce;
      noChao = false;
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Q);
    if (tecla == "Q" && noChao) {
<<<<<<< HEAD
      // Jump only if on ground
      atirar(); // o correto
=======
      atirar(); // Atirar
>>>>>>> psave
    }
  }
  // Jogador 2 (Setas + Z)
  else {
    string tecla = GE->isTeclaPressionada(sf::Keyboard::Left);
    if (tecla == "Left Arrow") {
      getSprite().move(-5.f, 0.f); // Move para a esquerda
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Right);
    if (tecla == "Right Arrow") {
      getSprite().move(5.f, 0.f); // Move para a direita
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Space);
    if (tecla == "Space" && noChao) {
<<<<<<< HEAD
      // Jump only if on ground
=======
>>>>>>> psave
      float jumpForce = -12.0f; // controle do pulo
      velFinal.y = jumpForce;
      noChao = false;
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Z);
    if (tecla == "Z" && noChao) {
<<<<<<< HEAD
      // Jump only if on ground
      atirar(); // o correto

=======
      atirar(); // Atirar
>>>>>>> psave
    }
  }

  // Aplicar gravidade
  if (!noChao) {
    velFinal.y += GF.aplicarGravidade() * 0.016f;
  }

  getSprite().move(velFinal.x, velFinal.y);
}

void Tripulante::salvarDataBuffer(nlohmann::ordered_json &json) {
  Vector2f pos = getPosicao(); // Desempacota a posição

  json = {

      {"posicao", {{"x", pos.x}, {"y", pos.y}}},

      {"vida", getVida()},

      {"pontos", getPontos()}

  };
}

void Tripulante::carregarDataBuffer(const nlohmann::ordered_json &json) {
  // Verifica se o JSON contém a chave "posicao"
  if (json.contains("posicao")) {
    // Obtém as coordenadas X e Y da posição do tripulante a partir do JSON
    int posicaoX = json["posicao"]["x"].get<int>();
    int posicaoY = json["posicao"]["y"].get<int>();

    // Define a posição do tripulante com os valores obtidos
    setPosicao(posicaoX, posicaoY);
  }

  // Verifica se o JSON contém a chave "vida"
  if (json.contains("vida")) {
    // Obtém o valor da vida do tripulante a partir do JSON e define no objeto
    setVida(json["vida"].get<int>());
  }

  // Verifica se o JSON contém a chave "pontos"
  if (json.contains("pontos")) {
    // Obtém o valor dos pontos do tripulante a partir do JSON e define no
    // objeto
    setPontos(json["pontos"].get<int>());
  }
}

int Tripulante::getPontos() { return pontos; }

void Tripulante::setChao(bool chao) { noChao = chao; }

bool Tripulante::getChao() { return noChao; }
void Tripulante::setPontos(int ponto) { pontos = ponto; }
void Tripulante::podePular() {}
void Tripulante::atualizar() {
  if (pontosVida <= 0) {
    morrer();
  }
  if (vivo) {
    mover();
  }
}

void Tripulante::atirar() {
  if (getMunicao() > 0) {
    if (!projetil->getAtivo()) {
      projetil->setAtivo(true, getSprite().getPosition());
      tirarMunicao();
    }
  }
}
void Tripulante::colisao(Entidade *outraEntidade, Vector2f ds) {
  bool onPlatform = false;

  switch (outraEntidade->getID()) {
  // Caso para colisão com inimigos
  case (IDs::IDs::ciborgue): //  inimigo fácil
  {
    Entidades::Personagens::Inimigo *inimigo =
        dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
    if (inimigo) {
      recebeDano(inimigo->getDano()); // Aplica o dano do inimigo
    }
  } break;
<<<<<<< HEAD
  case (IDs::IDs::clone): //  inimigo fácil
=======
  case (IDs::IDs::clone): //  inimigo difícil
>>>>>>> psave
  {
    Entidades::Personagens::Inimigo *inimigo =
        dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
    if (inimigo) {
      recebeDano(inimigo->getDano()); // Aplica o dano do inimigo
    }
  } break;
<<<<<<< HEAD
  case (IDs::IDs::androide): //  inimigo fácil
=======
  case (IDs::IDs::androide): //  inimigo médio
>>>>>>> psave
  {
    Entidades::Personagens::Inimigo *inimigo =
        dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
    if (inimigo) {
      recebeDano(inimigo->getDano()); // Aplica o dano do inimigo
    }
  } break;
<<<<<<< HEAD
  case IDs::IDs::plataforma: {
=======
  case IDs::IDs::plataforma: { // Colisão com plataforma
>>>>>>> psave
    tempoSemColisao = 0.0f;
    Vector2f myPos = getSprite().getPosition();
    Vector2f platPos = outraEntidade->getSprite().getPosition();
    Vector2f mySize = getTamanho();
    Vector2f platSize = outraEntidade->getTamanho();

    float myBottom = myPos.y + mySize.y;
    float platTop = platPos.y;

    float myRight = myPos.x + mySize.x;
    float platLeft = platPos.x;

    float myLeft = myPos.x;
    float platRight = platPos.x + platSize.x;
    if (myBottom >= platTop && ds.y <= 5.f) {
      velFinal.y = 0;
      myPos.y = platTop - mySize.y;
      getSprite().setPosition(myPos);
      setPosicao(myPos.x, myPos.y);
      onPlatform = true;
    }

  } break;
<<<<<<< HEAD
  case (IDs::IDs::espinho): {
=======
  case (IDs::IDs::espinho): { // Colisão com espinho
>>>>>>> psave
    Entidades::Obstaculos::Espinho *espinho =
        dynamic_cast<Entidades::Obstaculos::Espinho *>(outraEntidade);

    recebeDano(espinho->getDano());

  } break;
<<<<<<< HEAD
  case (IDs::IDs::centro_gravidade): {
=======
  case (IDs::IDs::centro_gravidade): { // Colisão com centro de gravidade
>>>>>>> psave
    Entidades::Obstaculos::Centro_Gravidade *centro_gravidade =
        dynamic_cast<Entidades::Obstaculos::Centro_Gravidade *>(outraEntidade);

    recebeDano((GF.gravidadePersonagemBuracoNegro() / 1e15));
  } break;
<<<<<<< HEAD
  case IDs::IDs::projetil_inimigo: {
=======
  case IDs::IDs::projetil_inimigo: { // Colisão com projetil inimigo
>>>>>>> psave
    Entidades::Projetil *projetil =
        dynamic_cast<Entidades::Projetil *>(outraEntidade);

    recebeDano(projetil->getDano());
    projetil->setAtivo(false, {-130.f, -130.f});

  } break;
<<<<<<< HEAD
=======
  case (IDs::IDs::espinhoRetratil): { // Colisão com espinho retratil
    Entidades::Obstaculos::EspinhoRetratil *espinhoRetratil =
        dynamic_cast<Entidades::Obstaculos::EspinhoRetratil *>(outraEntidade);

    if (espinhoRetratil->estaLigado()) {
      recebeDano(espinhoRetratil->getDano());
    }
  } break;
>>>>>>> psave
  default: {
    onPlatform = false;
  } break;
  }
  noChao = onPlatform;
}
} // namespace Entidades::Personagens
