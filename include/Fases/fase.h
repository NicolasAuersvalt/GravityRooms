#ifndef FASE_H
#define FASE_H

#include <time.h>

#include <iostream>
#include <queue>

#include "Entidades/Obstaculos/centro_gravidade.h"
#include "Entidades/Obstaculos/espinho.h"
#include "Entidades/Obstaculos/espinhoRetratil.h"
#include "Entidades/Obstaculos/plataforma.h"
#include "Entidades/Personagens/androide.h"
#include "Entidades/Personagens/ciborgue.h"
#include "Entidades/Personagens/clone.h"
#include "Entidades/background.h"
#include "Gerenciadores/gerenciador_colisoes.h"
#include "Gerenciadores/gerenciador_grafico.h"
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

using Entidades::Obstaculos::EspinhoRetratil;

using Entidades::Personagens::Androide;
using Entidades::Personagens::Ciborgue;
using Entidades::Personagens::Clone;
using Entidades::Personagens::Tripulante;

// using Entidades::Background;
using Entidades::Projetil;
using Listas::Lista_Entidades;

using namespace sf;
using namespace std;

namespace Entidades {
class Background;
}

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  3
// Requisitos Funcionais  5
// Requisitos Funcionais  7
// Requisitos Funcionais  8

// Requisitos Conceituais 2.1
// Requisitos Conceituais 3.1
// Requisitos Conceituais 3.3
// Requisitos Conceituais 5.2
// Requisitos Conceituais 7.2

// =====/=====/=====/=====/=====/=====/

namespace Fases {

class Fase : public Ente {
 private:

 protected:
  short inimAleatorio = 0;
  queue<Vector2f> filaInimigosFaceis;     // Queue for easy enemies
  queue<Vector2f> filaInimigosMedios;     // Queue for medium enemies
  queue<Vector2f> filaInimigosDificeis;   // Queue for difficult enemies
  queue<Vector2f> filaEspinhos;           // Queue for spikes
  queue<Vector2f> filaEspinhosRetrateis;  // Queue for retractable spikes
  queue<Vector2f> filaCentrosGravidade;   // Queue for gravity centers
  int contadorEspinho = 0;
  int contadorEspinhoRetratil = 0;
  short obsAleatorio = 0;
  int contadorCg = 0;
  const int MAX_INIMIGOS_INICIAIS = 3;
  const int MAX_INIMIGOS_TOTAL = 7;

 public:

  bool complete;
  Lista_Entidades *listaObstaculos;
  Gerenciador_Grafico *GG;

  // =====/=====/=====/=====/=====/=====/
  // Requisitos Funcionais 2 (Um ou mais Jogadores)

  Tripulante *tripulantes[2];
  // =====/=====/=====/=====/=====/=====/

  Vector2f pos1;
  Vector2f pos2;

  Gerenciador_Colisoes *pColisao;
  Lista_Entidades *listaPersonagens;

  Entidades::Background *bg;
  Lista_Entidades *listaBackground;

  Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
  ~Fase();

  void executar();
  string getTipo() const override;
  void carregar(json &arquivo) {}
  void salvar(json &arquivo) override {}
  void criarBackground(const IDs::IDs ID_Fase);
  void criarInimFaceis(const Vector2f pos, Tripulante *tripulante);
  void criarInimDificeis(const Vector2f pos, Tripulante *tripulante);
  void criarInimMedios(const Vector2f pos, Tripulante *tripulante);
  void criarJogador(const Vector2f pos, int index);
  void criarPlataforma(const Vector2f pos);
  void criarEspinho(const Vector2f pos);
  void criarCentroGravidade(const Vector2f pos);
  void criarEspinhoRetratil(const Vector2f pos);
  void setGerenciadorG(Gerenciador_Grafico *GG);
  Gerenciador_Grafico* getGerenciador();
  virtual void criarEntidades(char letra, const Vector2f pos);
  virtual void criarFundo() = 0;  // fundo
  virtual void criarMapa() = 0;
  virtual void desenhar() = 0;
  Entidades::Projetil *criarProjetil(const Vector2f pos, IDs::IDs ID);

  bool isNave();
  bool isLab();
};
}  // namespace Fases

#endif
