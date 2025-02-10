#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <time.h>

#include <iostream>

#include "Entidades/entidade.h"
#include "json.hpp"

using namespace sf;
using namespace std;

// =====/=====/=====/=====/=====/=====/

// Requisitos Funcionais 2
// Requisitos Funcionais 4
// Requisitos Funcionais 9

// Requisitos Conceituais 1.2
// Requisitos Conceituais 2.3
// Requisitos Conceituais 5.1
// Requisitos Conceituais 8.3

// =====/=====/=====/=====/=====/=====/

namespace Entidades::Personagens {

class Personagem : public Entidade {
 protected:
  Vector2f vel;

  int pontosVida;
  bool noChao;
  RectangleShape corpo;

  bool vivo;
  bool podeAndar;
  bool paraEsquerda;
  Clock relogio;
  float dt;
  Vector2f velFinal;
  float tempoSemColisao;
  const float TEMPO_MAX_SEM_COLISAO = 0.1f;

  void verificarLimitesTela();

 public:
  Personagem(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Personagem();

  virtual void salvarDataBuffer(nlohmann::ordered_json &json) = 0;
  virtual void mover() = 0;

  // Método para obter o corpo (RectangleShape)
  const RectangleShape &getCorpo() const;

  // Métodos para manipulação de vida
  void setVida(int life);
  int getVida();
  void recebeDano(int dano);
  void setPisando(bool pisa);
  bool getPisando();
  bool verificarVivo();
  void morrer();
  void atualizarPosicao();
  void parar();
  void andar(const bool paraEsquerda);
  virtual void colisao(Entidade *outraEntidade,
                       Vector2f ds = Vector2f(0.0f, 0.0f)) = 0;
  void setVelFinal(const Vector2f velFinal);
  const Vector2f getVelFinal() const;
  void cair();
  void carregar(json &arquivo) override {};
  string getTipo() const override { return "Personagem"; }
};

}  // namespace Entidades::Personagens

#endif
