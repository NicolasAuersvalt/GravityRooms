#ifndef CLONE_H
#define CLONE_H

#include <SFML/Graphics.hpp>

#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include "Gerenciadores/registry.h"
using namespace std;
using namespace sf;
using namespace Entidades::Personagens;

namespace Entidades::Personagens {

class Clone : public Inimigo {
private:
  Clock timerTiro; // Temporizador para controlar a frequência de disparo

protected:
  Projetil *projetil;

public:
  Clone(const sf::Vector2f pos, Tripulante *tripulante, const IDs::IDs ID);
  ~Clone();
  using Ente::setSprite;

  void danificar(Tripulante *p) override;

  virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  void mover() override;
  void setProjetil(Projetil *proj) { projetil = proj; };
  Projetil *getProjetil() { return projetil; };
  void atirar();
  int getDano();
  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["vida"] = getVida();
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "clone";
    if (projetil) {
      arquivo["projetil"]["id"] = static_cast<int>(projetil->getID());

      arquivo["projetil"]["ativo"] = projetil->getAtivo();
      arquivo["projetil"]["posicao"]["x"] = projetil->getPosicao().x;
      arquivo["projetil"]["posicao"]["y"] = projetil->getPosicao().y;
      arquivo["projetil"]["tipo"] = "projetil";
    }
  }
};

} // namespace Entidades::Personagens

#endif
