#ifndef INIMIGO_H
#define INIMIGO_H

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f
#define VELOCIDADE_INIMIGO_X 0.025f
#define VELOCIDADE_INIMIGO_Y 0.025f

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"

namespace Entidades::Personagens {

class Inimigo : public Personagem {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  int nivel_maldade;
  int dano = 10;

  // ===/===/===/===/ Outros  ===/===/===/===/
  Jogador::Jogador* jogador;
  sf::Clock relogio;
  short moverAleatorio;
  void inicializa();

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Inimigo(cosnt sf::Vector2f pos, const sf::Vector2f tam,
          Jogador::Jogador* pJog);
  ~Inimigo();
  void perseguirJogador(sf::Vector2f posJogador, const sf::Vector2f posInimigo);
  void movimentarAleatorio();
  virtual void mover();  // n virtual puro por enquanto
  void salvarDataBuffer();
  virtual void danificar(Tripulante* p) = 0;

  virtual void executar() = 0;

  // ===/===/===/===/ Outros  ===/===/===/===/

  virtual void colidir(Entidade* outro, string direction = "") = 0;

  // Pode reescrever se quiser (com algum multiplicador, por exemplo)
  virtual int getDano() {
    // Por exemplo, retornar o dano base multiplicado pelo nível de maldade
    return dano;
  }
};

}  // namespace Entidades::Personagens

#endif