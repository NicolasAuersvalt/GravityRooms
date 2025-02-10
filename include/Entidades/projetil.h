#ifndef PROJETIL_H
#define PROJETIL_H

#include <iostream>

#include "Entidades/Personagens/personagem.h"
#include "Entidades/entidade.h"

using namespace std;
using namespace sf;
using namespace Entidades;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  9

// Requisitos Conceituais 3.4
// Requisitos Conceituais 5.2
// =====/=====/=====/=====/=====/=====/

namespace Entidades {

class Projetil : public Entidade {
 private:
  static int danoProjetil;
  bool ativo;

  bool colidiu;
  Entidade *atirador;
  int dano;
  Vector2f velocidade;

 protected:
 public:
  Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  virtual ~Projetil();

  void executar();

  void setVelocidade(const Vector2f &vel);

  void mover();
  void atualizar();
  void setAtivo(bool i, Vector2f pos);
  bool getAtivo();
  void setAtirador(Entidade *a);
  bool getColidir(Entidade *e);
  int getDano();
  void atualizarPosicao() {};
  void colisao(Entidade *outraEntidade, Vector2f ds = Vector2f(0.0f, 0.0f));

  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["ativo"] = getAtivo();
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "projetil";
  }
  void carregar(json &arquivo) override {};
  string getTipo() const override { return "projetil"; }
};

}  // namespace Entidades

#endif