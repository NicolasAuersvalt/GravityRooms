#ifndef CIBORGUE_H
#define CIBORGUE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

// =====/=====/=====/=====/=====/=====/
// Requisitos Conceituais 4.1

// Requisitos Conceituais 5.2
// =====/=====/=====/=====/=====/=====/

namespace Entidades::Personagens {

class Ciborgue : public Inimigo {
private:
  int tamanho;

protected:
public:
  Ciborgue(const Vector2f pos, Tripulante *tripulante, const IDs::IDs ID);
  Ciborgue(Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Ciborgue();

  using Ente::setSprite;
  void executar() override;
  void danificar(Tripulante *p) override;
  void mover() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  int getDano();
  Projetil *getProjetil() { return nullptr; };
  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["vida"] = getVida();
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "ciborgue";
  }
};

} // namespace Entidades::Personagens

#endif
