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
#include "Gerenciadores/registry.h"
#include "Listas/lista_entidades.h"
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
    int maxMunicao;

   public:
    Municao(int maxM = 100) : quantidade(maxM), maxMunicao(maxM) 
    {}

    void setQtd(int qtd) {
      quantidade = std::max(0, std::min(qtd, maxMunicao));
    }

    int getQtd() const { return quantidade; }

    void recarregar(int qtd) { setQtd(quantidade + qtd); }

    bool consumir() {
      if (quantidade > 0) {
        quantidade--;
        return true;
      }
      return false;
    }
    // Sobrecarga do operador +=
    Municao &operator+=(int qtd) {
      setQtd(quantidade + qtd);  // Adiciona a quantidade, respeitando o limite
      return *this;
    }

    // Sobrecarga do operador -=
    Municao &operator-=(int qtd) {
      setQtd(quantidade - qtd);  // Remove a quantidade, mas sem ir abaixo de 0
      return *this;
    }
    Municao &operator--() {
      if (quantidade > 0) {
        quantidade--;  // Decrementa se houver munição
      }
      return *this;
    }
  };

  Municao municao;
  int pontos;
  Gerenciador_Eventos *GE;
  Gerenciador_Fisica GF;
  bool isPlayerOne;
  float tempoUltimoTiro;  // Tempo desde o último disparo
  float tempoCooldown;

 protected:
  Listas::Lista_Entidades *projeteis;

 public:
  Tripulante(const Vector2f pos, const Vector2f tam, const IDs::IDs ID);
  ~Tripulante();

  void carregarDataBuffer(const nlohmann::ordered_json &json);

  virtual void salvarDataBuffer(nlohmann::ordered_json &json) override;
  virtual void mover() override;

  void setPontos(int ponto);
  void setChao(bool chao);
  void atualizarProjeteis();
  void removerProjetilInativo();
  Listas::Lista_Entidades *getProjeteis() { return projeteis; };
  bool podeAtirar() { return municao.getQtd() > 0; }
  void setGerenciadorEvento(Gerenciador_Eventos *GE);
  void setMunicao(int qtd);
  void setPlayerOne(bool isone) { isPlayerOne = isone; }
  bool getChao();
  int getPontos();
  int getMunicao();
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
