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
#include "Gerenciadores/gerenciador_fisico.h"
#include "Gerenciadores/gerenciador_input.h"
#include "Gerenciadores/registry.h"
#include "Listas/lista_entidades.h"
#include "json.hpp"

using namespace sf;
using namespace std;

using Gerenciadores::Gerenciador_Fisica;
using Gerenciadores::Gerenciador_Input;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  8
// Requisitos Funcionais  9

// Requisitos Conceituais 5.2
// =====/=====/=====/=====/=====/=====/

namespace Entidades::Personagens {

class Tripulante : public Personagem {
 private:
  class Municao {
   private:
    int quantidade;
    int maxMunicao;

   public:
    Municao(int maxM = 100) : quantidade(maxM), maxMunicao(maxM) {}

    void setQtd(int qtd) { quantidade = max(0, min(qtd, maxMunicao)); }

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
  Gerenciador_Input *GI;
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
  void podePular();

  Listas::Lista_Entidades *getProjeteis();

  bool podeAtirar();
  void setGerenciadorEvento(Gerenciador_Input *GI);
  void setMunicao(int qtd);
  void setPlayerOne(bool isone);

  bool getChao();
  int getPontos();
  int getMunicao();
  void atualizar();


  void colisao(Entidade *outraEntidade, Vector2f ds = Vector2f(0.0f, 0.0f));
  void salvar(json &arquivo) override;
  void atirar();
};

}  // namespace Entidades::Personagens

#endif
