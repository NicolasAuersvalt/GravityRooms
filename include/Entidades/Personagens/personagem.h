#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>

#include "Entidades/entidade.h"

namespace Entidades::Personagens {

class Personagem : public Entidade {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  sf::RectangleShape corpo;
  sf::Vector2f vel;
  int pontosVida;
  bool noChao;
  int num_vidas;

  // ===/===/===/===/ Outros  ===/===/===/===/

  int vel;
  bool vivo;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // Personagem(pair<int, int> p, pair<int, int> d); //verificar
  Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
  ~Personagem();
  void salvar();

  // Métodos Virtuais
  virtual void executar() = 0;
  virtual void salvarDataBuffer() {}
  void setPisando(bool pisa) { noChao = pisa; }
  bool getPisando() { return noChao; }
  void recebeDano(int dano) {
    pontosVida -= dano;
    if (!verificarVivo()) {
      morrer();
    }
  }

  bool verificarVivo() { return (pontosVida > 0); }
  void morrer() {
    std::cout << "FUlano Morreu" << std::endl;
    // REMOVER DA LISTA DE ENTIDADES SEI LÁ
  }

  // ===/===/===/===/ Outros  ===/===/===/===/
  const sf::RectangleShape getCorpo();
  virtual void move() = 0;
};

}  // namespace Entidades::Personagens

#endif