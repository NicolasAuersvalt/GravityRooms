#include "Entidades/Personagens/tripulante.h"

#include <SFML/Graphics.hpp>

using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Tripulante::Tripulante(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID, bool isFirstPlayer)
    : Personagem(pos, tam, ID), pontos(0), GF(pos) {
  projetil = new Projetil(Vector2f(-1000, -1000), Vector2f(50, 25),
                          IDs::IDs::projetil_tripulante);
  // GS = new Save();
  // GS->setJogador(this);

  setSprite("assets/tripulante.png", pos.x, pos.y);
  // setSprite("assets/tripulanteP.png", pos.x, pos.y);
  setTamanho(Vector2f(getSprite().getTexture()->getSize().x,
                      getSprite().getTexture()->getSize().y));
  // setPosicao(pos.x, pos.y);
  vivo = true;
  isPlayerOne = isFirstPlayer;
  tempoSemColisao = 0.0f;
  noChao = false;
  sprite.setPosition(pos.x, pos.y);
  setMunicao(40);
  std::cout << "TripulantePosition: " << pos.x << " " << pos.y << "vivo "
            << vivo << std::endl;
}

Tripulante::~Tripulante() {}

// Implementação da função executar()
/*
   void Tripulante::executar() {
// Implementação do comportamento da função
}
*/

void Tripulante::setGerenciadorEvento(Gerenciador_Eventos *GE) {
  if (GE) {
    this->GE = GE;  // Atribui o ponteiro GE à variável membro this->GE
  }
}

void Tripulante::tirarMunicao() { 

  municao--;

}

int Tripulante::getMunicao() { 
  return municao.getQtd(); 
  }

void Tripulante::setMunicao(int qtd) { 
  municao.setQtd(qtd); 
  }

void Tripulante::mover() {
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

  //   cout << "Shooting projectile" << endl;
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
  cair();
  if (isPlayerOne) {
    string tecla = GE->isTeclaPressionada(sf::Keyboard::A);
    if (tecla == "A") {
      getSprite().move(-5.f, 0.f);  // Move para a esquerda
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::D);
    if (tecla == "D") {
      getSprite().move(5.f, 0.f);  // Move para a direita
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::W);
    if (tecla == "W" && noChao) {
      // Jump only if on ground
      float jumpForce = -12.0f;  // controle do pulo
      velFinal.y = jumpForce;
      noChao = false;
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Q);
    if (tecla == "Q" && noChao) {
      // Jump only if on ground
      atirar(); // o correto
      
    }
  }
  // Jogador 2 (Setas + Q)
  else {
    string tecla = GE->isTeclaPressionada(sf::Keyboard::Left);
    if (tecla == "Left Arrow") {
      getSprite().move(-5.f, 0.f);  // Move para a esquerda
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Right);
    if (tecla == "Right Arrow") {
      getSprite().move(5.f, 0.f);  // Move para a direita
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Space);
    if (tecla == "Space" && noChao) {
      // Jump only if on ground
      float jumpForce = -12.0f;  // controle do pulo
      velFinal.y = jumpForce;
      noChao = false;
    }
    tecla = GE->isTeclaPressionada(sf::Keyboard::Z);
    if (tecla == "Z" && noChao) {
      // Jump only if on ground
      atirar();  // o correto

      cout << "player 1 is Shooting projectile" << endl;
    }
  }

  // Aplicar gravidade
  if (!noChao) {
    velFinal.y += GF.aplicarGravidade() * 0.016f;
  }
  
  getSprite().move(velFinal.x, velFinal.y);
}

void Tripulante::salvarDataBuffer(nlohmann::ordered_json &json) {
  Vector2f pos = getPosicao();  // Desempacota a posição

  json = {

      {"posicao", {{"x", pos.x}, {"y", pos.y}}},

      {"vida", getVida()},

      {"pontos", getPontos()}

  };
}

void Tripulante::carregarDataBuffer(const nlohmann::ordered_json &json) {
  if (json.contains("posicao")) {
    int posicaoX = json["posicao"]["x"].get<int>();
    int posicaoY = json["posicao"]["y"].get<int>();

    setPosicao(posicaoX, posicaoY);
  }

  if (json.contains("vida")) {
    setVida(json["vida"].get<int>());
  }
  if (json.contains("pontos")) {
    setPontos(json["pontos"].get<int>());
  }
}

int Tripulante::getPontos() { return pontos; }

void Tripulante::setChao(bool chao) { noChao = chao; }

bool Tripulante::getChao() { return noChao; }
void Tripulante::setPontos(int ponto) { pontos = ponto; }
void Tripulante::podePular() {
  // if (noChao) {
  //   velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
  //   noChao = false;
  //   atacando = false;
  // }
}
void Tripulante::atualizar() {
  if (pontosVida <= 0) {
    morrer();
  }
  if (vivo) {
    mover();
  }
}

void Tripulante::atirar() {
  if(getMunicao() > 0){
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
    case (IDs::IDs::ciborgue):  //  inimigo fácil
    {
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
      if (inimigo) {
        recebeDano(inimigo->getDano());  // Aplica o dano do inimigo
      }
    } break;
    case (IDs::IDs::clone):  //  inimigo fácil
    {
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
      if (inimigo) {
        recebeDano(inimigo->getDano());  // Aplica o dano do inimigo
      }
    } break;
    case (IDs::IDs::androide):  //  inimigo fácil
    {
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(outraEntidade);
      if (inimigo) {
        recebeDano(inimigo->getDano());  // Aplica o dano do inimigo
      }
    } break;
    case IDs::IDs::plataforma: {
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
      // Platform collision from above
      if (myBottom >= platTop && ds.y <= 5.f) {
        velFinal.y = 0;
        myPos.y = platTop - mySize.y;
        getSprite().setPosition(myPos);
        setPosicao(myPos.x, myPos.y);
        onPlatform = true;
      }

      // Check if the Tripulante is landing on top of the platform

    } break;
    case (IDs::IDs::espinho): {
            Entidades::Obstaculos::Espinho *espinho =
          dynamic_cast<Entidades::Obstaculos::Espinho *>(outraEntidade);

      recebeDano(espinho->getDano());

    } break;
    case (IDs::IDs::centro_gravidade): {
      Entidades::Obstaculos::Centro_Gravidade *centro_gravidade =
          dynamic_cast<Entidades::Obstaculos::Centro_Gravidade *>(
              outraEntidade);

      recebeDano((GF.gravidadePersonagemBuracoNegro() / 1e15));
    } break;
    case IDs::IDs::projetil_inimigo: {
      Entidades::Projetil *projetil =
          dynamic_cast<Entidades::Projetil *>(outraEntidade);

      recebeDano(projetil->getDano());
      projetil->setAtivo(false, {-130.f, -130.f});

    } break;
    default: {
      onPlatform = false;
    } break;
  }
  noChao = onPlatform;
}
}  // namespace Entidades::Personagens
