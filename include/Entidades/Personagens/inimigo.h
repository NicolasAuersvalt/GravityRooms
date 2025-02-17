#ifndef INIMIGO_H
#define INIMIGO_H

#include <time.h>

#include <cmath>
#define RAIO_PERSEGUIR_X 500.0f
#define RAIO_PERSEGUIR_Y 500.0f

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"
#include "Entidades/projetil.h"
#include "Gerenciadores/gerenciador_fisico.h"

using namespace sf;
using namespace std;

using Gerenciadores::Gerenciador_Fisica;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  9
// =====/=====/=====/=====/=====/=====/

namespace Entidades::Personagens {
class Tripulante;
class Inimigo : public Personagem {
private:
protected:
  int nivel_maldade;

  int dano;
  Tripulante *tripulante;
  Clock relogio;
  short moverAleatorio;
  void inicializar();
  Gerenciador_Fisica GF;

public:
  Inimigo(const Vector2f pos, const Vector2f tam, Tripulante *tripulante,
          const IDs::IDs ID);
  ~Inimigo();

  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  virtual void danificar(Tripulante *p) = 0;
  virtual void executar() = 0;
  void colisao(Entidade *outraEntidade, Vector2f ds = Vector2f(0.0f, 0.0f));
  virtual void mover();

  virtual Projetil *getProjetil() = 0;
  virtual int getDano() = 0;

  void perseguirTripulante(Vector2f posTripulante, const Vector2f posInimigo);
  void movimentarAleatorio();
  int getNivelMaldade() const;
  void setTripulante(Tripulante *tripulante) { this->tripulante = tripulante; };
};

} // namespace Entidades::Personagens

#endif
