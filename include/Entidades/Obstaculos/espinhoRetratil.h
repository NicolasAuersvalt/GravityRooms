#ifndef ESPINHORETRATIL_H
#define ESPINHORETRATIL_H

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/entidade.h"

namespace Entidades::Obstaculos {
class EspinhoRetratil : public Obstaculo {
private:
  float largura;
  float tempoDesdeUltimaAlternancia;
  bool ligado;
  sf::Clock relogio;

protected:
public:
  EspinhoRetratil(const sf::Vector2f pos, const sf::Vector2f tam,
                  const IDs::IDs ID);
  ~EspinhoRetratil();
  void executar();
  void mover();

  void colisao(Entidade *outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  int getDano();

  bool estaLigado() const;

  void carregar(json &arquivo) {}
  std::string getTipo() const override { return "espinhoRetratil"; }
  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "espinhoRetratil";
  }
};

} // namespace Entidades::Obstaculos

#endif
