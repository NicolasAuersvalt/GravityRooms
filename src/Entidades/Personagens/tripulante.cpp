#include "Entidades/Personagens/tripulante.h"

#include <SFML/Graphics.hpp>

#include "json.hpp"

using namespace Entidades::Personagens;

namespace Entidades::Personagens {

Tripulante::Tripulante(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID)
    : Personagem(pos, tam, ID), pontos(0) {
  setSprite("assets/tripulanteG.png", pos.x, pos.y);
  setTamanho(sf::Vector2f(150.0f, 150.0f));
  setPosicao(pos.x, pos.y);

  sprite.setPosition(pos.x, pos.y);
  std::cout << "TripulantePosition: " << pos.x << " " << pos.y << std::endl;
}

Tripulante::~Tripulante() {}

// Implementação da função executar()
/*
void Tripulante::executar() {
    // Implementação do comportamento da função
}
*/

void Tripulante::mover() {
  // Movimentação (sem física, apenas mover pela tela)
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    getSprite().move(-5.f, 0.f);  // Move para a esquerda
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    getSprite().move(5.f, 0.f);  // Move para a direita
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    getSprite().move(0.f, -5.f);  // Move para cima
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    getSprite().move(0.f, 5.f);  // Move para baixo
  }
}

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

void Tripulante::setPontos(int ponto) { pontos = ponto; }
void Tripulante::podePular() {
  //   if (noChao) {
  //     velocidade.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO_JOGADOR);
  //     noChao = false;
  //     caindo = false;
  //   }
}
void Tripulante::atualizar() {
  if (podeAndar) {
    atualizarPosicao();
  }
  relogio.restart();
}

void Tripulante::colisao(Entidade* outraEntidade, Vector2f ds) {
  switch (outraEntidade->getID()) {
    case (IDs::IDs::inimigo): {
    } break;
    case (IDs::IDs::plataforma): {
    } break;

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
}
}  // namespace Entidades::Personagens
