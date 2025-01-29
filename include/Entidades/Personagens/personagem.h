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
  

  // ===/===/===/===/ Outros  ===/===/===/===/
  
  bool vivo;
  bool podeAndar;
  bool paraEsquerda;
  Clock relogio;
  float dt;
  Vector2f velFinal;

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
};

}  // namespace Entidades::Personagens

#endif
