#ifndef CLONE_H
#define CLONE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include "Gerenciadores/registry.h"
using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  4

// Requisitos Conceituais 4.1
// Requisitos Conceituais 5.2
// =====/=====/=====/=====/=====/=====/

namespace Entidades::Personagens {

class Clone : public Inimigo {
private:
  Clock timerTiro; // Temporizador para controlar a frequência de disparo

protected:
  Projetil *projetil;

public:
  Clone(const Vector2f pos, Tripulante *tripulante, const IDs::IDs ID);
  Clone(Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Clone();
  using Ente::setSprite;

  void danificar(Tripulante *p) override;

  virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;

  void mover() override;
  void setProjetil(Projetil *proj) { projetil = proj; };
  Projetil *getProjetil() {
     return projetil; 
    };
  void atirar();
  int getDano();

  void salvar(json &arquivo) override;

};

} // namespace Entidades::Personagens

#endif
