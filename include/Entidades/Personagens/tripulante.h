#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include <cmath>
#include <iostream>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/personagem.h"
#include "Entidades/projetil.h"
#include "Gerenciadores/save.h"
#include "Gerenciadores/gerenciador_eventos.h"
#include "Gerenciadores/gerenciador_fisico.h"
#include "json.hpp"

using namespace sf;
using namespace std;

using Gerenciadores::Gerenciador_Eventos;
using Gerenciadores::Gerenciador_Fisica;


class Save;


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
    void atirou() {
      if (quantidade > 0) {
        quantidade--;
      } else {
        cerr << "Não tem mais munição" << endl;
      }
    }
  };

  Municao municao;
  // ===/===/===/===/ Obrigatório ===/===/===/===/
  int pontos;
  Gerenciador_Eventos* GE;
  Gerenciador_Fisica GF;
  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Save* GS;
  // ===/===/===/===/ Outros  ===/===/===/===/
  Projetil* projetil;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Tripulante(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Tripulante();

  void carregarDataBuffer(const nlohmann::ordered_json& json);

  // virtual void executar() override;
  virtual void salvarDataBuffer(nlohmann::ordered_json& json) override;
  virtual void mover() override;

  void salvar();
  void carregar();

  // Set
  void setPontos(int ponto);
  void setChao(bool chao);
  void setProjetil(Projetil* new_projetil) { projetil = new_projetil; };
  void setGerenciadorEvento(Gerenciador_Eventos* GE);
  void setMunicao(int qtd);

  // Get
  bool getChao();
  int getPontos();
  int getMunicao();

  Save* getGerenciadorSalvamento() {
    return GS;
  }
  void tirarMunicao();
  void atualizar();
  void podePular();
  void colisao(Entidade* outraEntidade,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));

  void atirar();
};

}  // namespace Entidades::Personagens

#endif
