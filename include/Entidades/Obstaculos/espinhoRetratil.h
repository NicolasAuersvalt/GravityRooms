#ifndef ESPINHORETRATIL_H
#define ESPINHORETRATIL_H

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/entidade.h"

using namespace std;
using namespace sf;

namespace Entidades::Obstaculos {
class EspinhoRetratil : public Obstaculo {
 private:
  float largura;
  float tempoDesdeUltimaAlternancia;
  bool ligado;
  Clock relogio;

 protected:
 public:
  EspinhoRetratil(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~EspinhoRetratil();
  void executar();
  void mover();

  void colisao(Entidade *outraEntidade, Vector2f ds = Vector2f(0.0f, 0.0f));
  int getDano();

  bool estaLigado() const;

  void carregar(json &arquivo) {}
  string getTipo() const override { return "espinhoRetratil"; }

  void salvar(json &arquivo) override;

};

}  // namespace Entidades::Obstaculos

#endif
