#ifndef TRIPULANTE_H
#define TRIPULANTE_H
#define TAMANHO_PULO 120.0f
#include <iostream>

#include "Entidades/Personagens/personagem.h"
#include "Gerenciadores/gerenciador_eventos.h"
#include "json.hpp"

using namespace sf;
using namespace std;

using Gerenciadores::Gerenciador_Eventos;

namespace Entidades::Personagens {

class Tripulante : public Personagem {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  int pontos;
  bool noChao;
  Gerenciador_Eventos *GE;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Tripulante(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Tripulante();

  void carregarDataBuffer(const nlohmann::ordered_json& json);

  // virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json& json) override;
  virtual void mover() override;

  int getPontos();
  void setPontos(int ponto);

  // ===/===/===/===/ Outros  ===/===/===/===/

  void setChao(bool chao);
  void setGerenciadorEvento(Gerenciador_Eventos *GE);

  bool getChao();
  void atualizar();
  void podePular();
  void colisao(Entidade* outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
};

}  // namespace Entidades::Personagens

#endif
