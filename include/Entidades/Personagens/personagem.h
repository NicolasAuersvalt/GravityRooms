#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <time.h>

#include <iostream>

#include "Entidades/entidade.h"
#include "json.hpp"

using namespace sf;
using namespace std;

namespace Entidades::Personagens {

class Personagem : public Entidade {
 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Vector2f vel;

  int pontosVida;
  bool noChao;
  RectangleShape corpo;
  // ===/===/===/===/ Outros  ===/===/===/===/

  bool vivo;
  bool podeAndar;
  bool paraEsquerda;
  Clock relogio;
  float dt;
  Vector2f velFinal;
  float tempoSemColisao;
  const float TEMPO_MAX_SEM_COLISAO = 0.1f;

  void verificarLimitesTela() {
    Vector2f pos = getSprite().getPosition();
    Vector2f tamanho = getTamanho();

    // Debug output
    cout << "Before boundary check:" << endl;
    cout << "Position: (" << pos.x << ", " << pos.y << ")" << endl;
    cout << "Size: (" << tamanho.x << ", " << tamanho.y << ")" << endl;

    // Horizontal boundaries (use actual window dimensions)
    const float LARGURA_TELA = 1280.0f;
    const float ALTURA_TELA = 920.0f;

    // Left boundary
    if (pos.x < 0.0f) {
      pos.x = 0.0f;
      velFinal.x = 0.0f;
    }
    // Right boundary
    if (pos.x + tamanho.x > LARGURA_TELA) {
      pos.x = LARGURA_TELA - tamanho.x;
      velFinal.x = 0.0f;
    }

    // Top boundary
    if (pos.y < 0.0f) {
      pos.y = 0.0f;
      velFinal.y = 0.0f;
    }
    // Bottom boundary
    if (pos.y + tamanho.y > ALTURA_TELA) {
      pos.y = ALTURA_TELA - tamanho.y;
      velFinal.y = 0.0f;
      noChao = true;
    }

    // Update both sprite and hitbox positions
    getSprite().setPosition(pos);
    setPosicao(pos.x, pos.y);

    // Debug output
    cout << "After boundary check:" << endl;
    cout << "Position: (" << pos.x << ", " << pos.y << ")" << endl;
  }

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // Personagem(pair<int, int> p, pair<int, int> d); //verificar
  Personagem(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Personagem();

  // virtual void executar() = 0;
  virtual void salvarDataBuffer(nlohmann::ordered_json& json) = 0;
  virtual void mover() = 0;

  // Método para obter o corpo (RectangleShape)
  const RectangleShape& getCorpo() const;

  // Métodos para manipulação de vida
  void setVida(int life);
  int getVida();
  void recebeDano(int dano);
  void setPisando(bool pisa);
  bool getPisando();
  void salvar();
  bool verificarVivo();
  void morrer();
  void atualizarPosicao();
  void parar();
  void andar(const bool paraEsquerda);
  virtual void colisao(Entidade* outraEntidade,
                       sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
  void setVelFinal(const sf::Vector2f velFinal);
  const sf::Vector2f getVelFinal() const;
  void cair();
};

}  // namespace Entidades::Personagens

#endif
