#include "Entidades/Personagens/tripulante.h"

#include <SFML/Graphics.hpp>

#include "Entidades/Obstaculos/espinho.h"
#include "json.hpp"

using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Tripulante::Tripulante(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID)
    : Personagem(pos, tam, ID), pontos(0), noChao(false), GF(pos) {
  setSprite("assets/tripulanteG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(150.0f, 150.0f));
  setPosicao(pos.x, pos.y);
  vivo = true;
  sprite.setPosition(pos.x, pos.y);
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

void Tripulante::setGerenciadorEvento(Gerenciador_Eventos* GE) {
  if (GE) {
    this->GE = GE;  // Atribui o ponteiro GE à variável membro this->GE
  }
}

void Tripulante::mover() {
  // Movimentação (sem física, apenas mover pela tela)
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
    float jumpForce = -30.0f;  // Adjust this value to control jump height
    velFinal.y = jumpForce;
    noChao = false;
  }

  if (!noChao) {
    // Apply gravity
    float dt = 0.016f;  // Assuming 60fps, adjust if using different time step
    velFinal.y += GF.aplicarGravidade() * dt;
  }
  getSprite().move(velFinal.x, velFinal.y);

  // Apply movement
}
}  // namespace Entidades::Personagens

void Tripulante::salvarDataBuffer(nlohmann::ordered_json& json) {
  Vector2f pos = getPosicao();  // Desempacota a posição

  json = {

      {"posicao", {{"x", pos.x}, {"y", pos.y}}},

      {"vida", getVida()},

      {"pontos", getPontos()}

  };
}

void Tripulante::carregarDataBuffer(const nlohmann::ordered_json& json) {
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
  if (podeAndar) {
    atualizarPosicao();
  }
  relogio.restart();
  if (pontosVida <= 0) {
    cout << vivo << endl;
    morrer();
    cout << vivo << endl;
  }
}

void Tripulante::colisao(Entidade* outraEntidade, Vector2f ds) {
  switch (outraEntidade->getID()) {
    // case (IDs::IDs::inimigo): {
    // } break;
    case IDs::IDs::plataforma: {
      Vector2f myPos = getSprite().getPosition();
      Vector2f platPos = outraEntidade->getPosicao();
      Vector2f mySize = getTamanho();
      Vector2f platSize = outraEntidade->getTamanho();

      // Platform collision from above
      if (ds.x < 0 && ds.y < 0) {
        float myBottom = myPos.y + mySize.y;
        float platTop = platPos.y;

        if (myBottom > platTop) {
          noChao = true;
          velFinal.y = 0;
          myPos.y = platTop - mySize.y;
          getSprite().setPosition(myPos);
          setPosicao(myPos.x, myPos.y);
        }
      }
    } break;
    case (IDs::IDs::espinho): {
      // std::cout << "\n=== Tripulante Collision Debug ===" << std::endl;

      Entidades::Obstaculos::Espinho* espinho =
          dynamic_cast<Entidades::Obstaculos::Espinho*>(outraEntidade);

      recebeDano(espinho->getDano());
      // std::cout << "\n=== ANTES DO IF ===" << std::endl;
      // std::cout << vivo << std::endl;

      // if (vivo) {
      //   // Apply initial bounce velocity with reduced height
      //   float bounceForce = 0.7f;  // Reduce bounce height to 70%
      //   float gravity = GF.aplicarGravidade();
      //   velFinal.y = -sqrt(2.0f * gravity * TAMANHO_PULO * bounceForce);

      //   // Ensure the player doesn't get stuck in continuous collision

      //   noChao = false;  // Player is no longer on ground after bounce
      //   std::cout << "\n=== DENTRO DO IF ===" << std::endl;
      //   std::cout << "\nvel em y" << velFinal.y << std::endl;
      //   std::cout << "\nvel em x" << velFinal.x << std::endl;
      // }
    } break;

    default: {
      noChao = false;
    }

      /*--------------------------------------------*/
      // switch (outraEntidade->getID()) {
      //   case (IDs::IDs::plataforma): {
      //   } break;
      //   case (IDs::IDs::inimigo): {
      //     // empura inimigo
      //     sf::Vector2f posInimigo = outraEntidade->getPos();
      //     Inimigo::Inimigo* inimigo =
      //         dynamic_cast<Inimigo::Inimigo*>(outraEntidade);
      //     if (pos.x < posInimigo.x) {
      //       ds.x *= -1;
      //     }
      //     // bate no jogador
      //     inimigo->parar();
      //     inimigo->atacar(true);
      //   } break;
      //   case (IDs::IDs::vida): {
      //     Item::Vida* vida = dynamic_cast<Item::Vida*>(outraEntidade);
      //     setVida(vida->getVida());
      //     vida->remover();
      //   } break;
      //   case (IDs::IDs::projetil_inimigo): {
      //     Item::Projetil* projetil =
      //     dynamic_cast<Item::Projetil*>(outraEntidade);
      //     tomarDano(projetil->getDano());
      //     projetil->setColidiu(true);
      //   } break;
      //   case (IDs::IDs::espinho): {
      //     Obstaculo::Espinho* espinho =
      //         dynamic_cast<Obstaculo::Espinho*>(outraEntidade);
      //     tomarDano(espinho->getDano());
      //     if (!morrendo) {
      //       velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
      //     }
      //   } break;
      //   case (IDs::IDs::centro_gravidade): {
      //     Obstaculo::Centro_gravidade* centro_gravidade =
      //         dynamic_cast<Obstaculo::Centro_gravidade*>(outraEntidade);
      //     tomarDano(centro_gravidade->getDano());
      //     if (!morrendo) {
      //       velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
      //     }
      //   } break;
  }

}  // namespace Entidades::Personagens
