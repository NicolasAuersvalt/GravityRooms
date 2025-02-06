#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include <cmath>
#include <iostream>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Obstaculos/espinhoRetratil.h"
#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/personagem.h"
#include "Entidades/projetil.h"
#include "Gerenciadores/gerenciador_eventos.h"
#include "Gerenciadores/gerenciador_fisico.h"
#include "Gerenciadores/gerenciador_json.h"
#include "Gerenciadores/registry.h"
#include "json.hpp"

using namespace sf;
using namespace std;

using Gerenciadores::Gerenciador_Eventos;
using Gerenciadores::Gerenciador_Fisica;

namespace Entidades::Personagens {

class Tripulante : public Personagem {
 private:
  class Municao {
   private:
    int quantidade;

   public:
    Municao() : quantidade(0) {}

    void setQtd(int qtd) { quantidade = qtd; }

    int getQtd() const { return quantidade; }

    Municao operator++(int) {
      Municao temp = *this;  // Cria uma cópia do objeto atual
      quantidade += 1;
      return temp;  // Retorna a cópia antes da alteração
    }
    Municao operator--(int) {
      Municao temp = *this;
      quantidade -= 1;
      return temp;
    }
  };

  Municao municao;
  int pontos;
  Gerenciador_Eventos *GE;
  Gerenciador_Fisica GF;
  bool isPlayerOne;

 protected:
  Projetil *projetil;

 public:
  Tripulante(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Tripulante();

  void carregarDataBuffer(const nlohmann::ordered_json &json);

  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  virtual void mover() override;

  void setPontos(int ponto);
  void setChao(bool chao);
  void setProjetil(Projetil *new_projetil) { projetil = new_projetil; };
  Projetil *getProjetil() { return projetil; };
  void setGerenciadorEvento(Gerenciador_Eventos *GE);
  void setMunicao(int qtd);
  void setPlayerOne(bool isone) { isPlayerOne = isone; }
  bool getChao();
  int getPontos();
  int getMunicao();
  void tirarMunicao();
  void atualizar();
  void podePular();
  void colisao(Entidade *outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
  void salvar(json &arquivo) override {
    arquivo["id"] = static_cast<int>(getID());
    arquivo["vida"] = getVida();
    arquivo["posicao"]["x"] = getPosicao().x;
    arquivo["posicao"]["y"] = getPosicao().y;
    arquivo["tipo"] = "tripulante";
  }
  void atirar();
};

}  // namespace Entidades::Personagens

#endif
