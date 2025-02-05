#ifndef FASE_H
#define FASE_H

#include <time.h>

#include <iostream>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Obstaculos/plataforma.h"
#include "Entidades/Personagens/androide.h"
#include "Entidades/Personagens/ciborgue.h"
#include "Entidades/Personagens/clone.h"
#include "Entidades/background.h"
#include "Gerenciadores/gerenciador_colisoes.h"
#include "Gerenciadores/gerenciador_grafico.h"
#include "Gerenciadores/gerenciador_json.h"
#include "IDs/IDs.h"
#include "Listas/lista_entidades.h"
#include "ente.h"

class Jogo;

using namespace std;
using namespace sf;

using Gerenciadores::Gerenciador_Colisoes;
using Gerenciadores::Gerenciador_Grafico;

using Entidades::Obstaculos::Centro_Gravidade;
using Entidades::Obstaculos::Espinho;
using Entidades::Obstaculos::Plataforma;

using Entidades::Personagens::Androide;
using Entidades::Personagens::Ciborgue;
using Entidades::Personagens::Clone;
using Entidades::Personagens::Tripulante;

using Entidades::Background;
using Entidades::Projetil;
using Listas::Lista_Entidades;

using namespace sf;
using namespace std;

namespace Fases {

class Fase : public Ente {
 private:
 protected:
  short inimAleatorio = 0;
  int contadorFaceis = 0;    // Contador de inimigos fáceis
  int contadorMedios = 0;    // Contador de inimigos medios
  int contadorDificeis = 0;  // Contador de inimigos difíceis
  int contadorEspinho = 0;
  short obsAleatorio = 0;
  int contadorCg = 0;

 public:
  bool complete;
  Lista_Entidades *listaObstaculos;
  Gerenciador_Grafico *GG;
  Tripulante *tripulantes[2];
  Vector2f pos1;
  Vector2f pos2;

  Gerenciador_Colisoes *pColisao;
  Lista_Entidades *listaPersonagens;
  Texture bgTexture;
  Sprite backgroundSprite;

  Background *bg;
  Lista_Entidades *listaBackground;

  Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
  ~Fase();

  void executar();
  std::string getTipo() const override { return "Fase"; }
  void carregar(std::ifstream &arquivo) {}
  void salvar(json &arquivo) override {}
  void criarBackground(const IDs::IDs ID_Fase) {
    bg = new Background(Vector2f(0.0f, 0.0f), Vector2f(0.0f, 0.0f), ID_Fase);

    if (bg == nullptr) {
      cout << "Fase::nao foi possivel criar jogador" << endl;
      exit(1);
    }

    listaBackground->incluir(static_cast<Entidade *>(bg));
  }

  void criarInimFaceis(const Vector2f pos, Tripulante *tripulante);

  void criarInimDificeis(const Vector2f pos, Tripulante *tripulante);
  void criarInimMedios(const Vector2f pos, Tripulante *tripulante);

  void criarJogador(const Vector2f pos, int index);
  void criarPlataforma(const Vector2f pos);
  void criarEspinho(const Vector2f pos);
  void criarCentroGravidade(const Vector2f pos);

  void setGerenciadorG(Gerenciador_Grafico *GG) {
    if (GG != nullptr) this->GG = GG;
  }
  Gerenciador_Grafico *getGerenciador() { return GG; }

  virtual void criarEntidades(char letra, const Vector2f pos);

  virtual void criarFundo() = 0;  // fundo
  virtual void criarMapa() = 0;
  virtual void desenhar() = 0;

  Entidades::Projetil *criarProjetil(const Vector2f pos, IDs::IDs ID);
};
}  // namespace Fases

#endif
