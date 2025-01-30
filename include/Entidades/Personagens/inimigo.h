#ifndef INIMIGO_H
#define INIMIGO_H

#include <time.h>

#include <cmath>
#define RAIO_PERSEGUIR_X 500.0f
#define RAIO_PERSEGUIR_Y 500.0f
// #define VELOCIDADE_INIMIGO_X 0.025f
// #define VELOCIDADE_INIMIGO_Y 0.025f

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"
#include "Gerenciadores/gerenciador_fisico.h"

// using Entidades::Personagens;
using namespace sf;
using namespace std;
using Gerenciadores::Gerenciador_Fisica;
namespace Entidades::Personagens {
class Tripulante;
class Inimigo : public Personagem {
  private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  int nivel_maldade;

  int dano;
  // ===/===/===/===/ Outros  ===/===/===/===/
  Tripulante* tripulante;
  Clock relogio;
  short moverAleatorio;
  void inicializar();
  Gerenciador_Fisica GF;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Inimigo(const Vector2f pos, const Vector2f tam, Tripulante* tripulante,
          const IDs::IDs ID);
  ~Inimigo();

  virtual void salvarDataBuffer(nlohmann::ordered_json& json) override;
  virtual void danificar(Tripulante* p) = 0;
  virtual void executar() = 0;
  // virtual void colidir(Entidade* outro, string direction = "") = 0;
  void colisao(Entidade* outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  virtual void mover();  // n virtual puro por enquanto

  virtual int getDano() {
    // Por exemplo, retornar o dano base multiplicado pelo nivel de maldade
    return dano;
  }

  void perseguirTripulante(sf::Vector2f posTripulante,
                           const sf::Vector2f posInimigo);
  void movimentarAleatorio();
};

}  // namespace Entidades::Personagens

#endif
