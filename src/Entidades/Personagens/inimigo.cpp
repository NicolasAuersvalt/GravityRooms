#include "Entidades/Personagens/inimigo.h"

#include <iostream>

using namespace std;
using namespace sf;

using Entidades::Personagens::Inimigo;

namespace Entidades::Personagens {

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, Tripulante* tripulante,
                 const IDs::IDs ID)
    : Personagem(pos, tam, ID),
      tripulante(tripulante),
      relogio(),
      GF(pos),
      dano(-1) {
  inicializar();
  tempoSemColisao = 0.0f;
  // Inicializa a semente do gerador de numeros aleatorios
  srand(time(NULL));
  // Gera uma direcao aleatoria inicial (0-3) para o movimento
  moverAleatorio = rand() % 2;

  velFinal = Vector2f(0.f, 0.f);
  noChao = false;
}
Inimigo::~Inimigo() {}

void Inimigo::inicializar() {
  vel = {2.f, 2.f};
  setVida(10);
}

void Inimigo::executar() {}
void Inimigo::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
  bool onPlatform = false;
  switch (outraEntidade->getID()) {
    // case (IDs::IDs::inimigo): {
    // } break;
    case (IDs::IDs::plataforma): {
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
    // case (IDs::IDs::tripulante): {
    //   Entidades::Personagens::Tripulante* tripulante =
    //       dynamic_cast<Entidades::Personagens::Tripulante*>(outraEntidade);
    //   cout << "colisao" << endl;
    //   tripulante->recebeDano(dano);
    //   cout << "recebeu dano na colisao" << dano << endl;

    // } break;
    default: {
      tempoSemColisao = 0.0f;
      onPlatform = false;
    } break;
  }
}
void Inimigo::mover() {
  // Obtem as posicoes do Tripulante e do inimigo
  // Debug print current positions
  Vector2f posJogador = tripulante->getSprite().getPosition();
  Vector2f posInimigo = getSprite().getPosition();

  cair();
  if (verificarVivo()) {
    if (!noChao) {
      float dt = 0.016f;
      velFinal.y += GF.aplicarGravidade() * dt;
    }
    if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X &&
        fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
      // Se estiver dentro do raio, persegue o Tripulante
      perseguirTripulante(posJogador, posInimigo);
    } else {
      // Se estiver fora do raio, move-se aleatoriamente
      movimentarAleatorio();
    }
  } else {
    cout << "esta morto" << endl;
    morrer();
  }
  getSprite().move(velFinal.x, velFinal.y);
  // std::cout << "=== Enemy Movement Debug ===" << std::endl;
  // std::cout << "Player pos: " << posJogador.x << "," << posJogador.y
  //           << std::endl;
  // std::cout << "Enemy pos: " << posInimigo.x << "," << posInimigo.y
  //           << std::endl;
  // std::cout << "Enemy velocity: " << vel.x << "," << vel.y << std::endl;

  // Verifica se o Tripulante esta dentro do raio de perseguicao
}
void Inimigo::salvarDataBuffer(nlohmann::ordered_json& json) {}
// Pode sobrescrever se quiser (com algum multiplicador)

void Inimigo::perseguirTripulante(Vector2f posJogador,
                                  const Vector2f posInimigo) {
  // Se o Tripulante estiver a direita do inimigo, move para direita
  if (posJogador.x - posInimigo.x > 0.0f) {
    getSprite().move(vel.x, 0.0f);
  }
  // Se o Tripulante estiver a esquerda do inimigo, move para esquerda
  else if (posJogador.x - posInimigo.x < 0.0f) {
    getSprite().move(-vel.x, 0.0f);
  }
  // // Se o Tripulante estiver abaixo do inimigo, move para baixo
  // else if (posJogador.y - posInimigo.y > 0.0f) {
  //   getSprite().move(0.0f, vel.y);
  // }
  // // Se o Tripulante estiver acima do inimigo, move para cima
  // else {
  //   getSprite().move(0.0f, -vel.y);
  // }
}

void Inimigo::movimentarAleatorio() {
  // // Move para cima quando moverAleatorio = 0
  // if (moverAleatorio == 0) {
  //   getSprite().move(0.0f, -vel.y);
  // }
  // // Move para baixo quando moverAleatorio = 1
  // else if (moverAleatorio == 1) {
  //   getSprite().move(0.0f, vel.y);
  // }
  // Move para esquerda quando moverAleatorio = 0
  if (moverAleatorio == 0) {
    getSprite().move(-vel.x, 0.0f);
  }
  // Move para direita quando moverAleatorio = 1
  else {
    getSprite().move(vel.x, 0.0f);
  }

  // Obtem o tempo decorrido desde o ultimo reinicio do relogio
  float dt = relogio.getElapsedTime().asSeconds();
  // A cada 1 segundo, gera uma nova direcao aleatoria
  if (dt >= 1.0f) {
    moverAleatorio = rand() % 4;
    relogio.restart();
  }
}

}  // namespace Entidades::Personagens
