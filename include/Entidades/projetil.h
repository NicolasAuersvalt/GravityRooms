#ifndef PROJETIL_H
#define PROJETIL_H

#include <iostream>

#include "Entidades/Personagens/personagem.h"
#include "Entidades/entidade.h"

using namespace std;
using namespace Entidades;

namespace Entidades {
class Personagem;

class Projetil : public Entidade {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  static int danoProjetil;
  bool ativo;

  // ===/===/===/===/ Outros  ===/===/===/===/
  bool colidiu;
  Entidade* atirador;
  int dano;

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Projetil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  virtual ~Projetil();

  // Métodos Virtuais
  // void executar() override;

  // ===/===/===/===/ Outros  ===/===/===/===/

  // virtual void executar() override;
  // virtual void mover() override;

  void salvar();
  void mover();
  void atualizar();
  void setAtivo(bool i, sf::Vector2f pos);
  bool getAtivo();
  void setAtirador(Entidade* a);
  bool getColidir(Entidade* e);
  void danificar(Personagem* p);
  int getDano();
  void colisao(Entidade* outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
};

}  // namespace Entidades

#endif