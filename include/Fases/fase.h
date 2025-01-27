#ifndef FASE_H
#define FASE_H

#include "Gerenciadores/gerenciador_colisoes.h"
#include "IDs/IDs.h"
#include "Listas/lista_entidades.h"
#include "ente.h"

class Jogo;
using namespace sf;

namespace Fases {

class Fase : public Ente {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Listas::Lista_Entidades* listaObstaculos;

  Entidades::Personagens::Tripulante* tripulante;
  // ===/===/===/===/ Outros  ===/===/===/===/
  Gerenciadores::Gerenciador_Colisoes* pColisao;
  Listas::Lista_Entidades* listaPersonagens;
  // Fase(const IDs IDs_Fase,const IDs IDs_Fundo);
  Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
  ~Fase();

  void executar();

  // void gerenciar_colisoes();
  void criarInimFaceis(const Vector2f pos,
                       Entidades::Personagens::Tripulante* tripulante);
  // void criarPlataformas();

  void criarInimDificeis(const Vector2f pos,
                         Entidades::Personagens::Tripulante* tripulante);
  void criarInimMedios(const Vector2f pos,
                       Entidades::Personagens::Tripulante* tripulante);

  void criarJogador(const Vector2f pos);
  void criarPlataforma(const Vector2f pos);
  void criarEspinho(const Vector2f pos);
  void criarCentroGravidade(const Vector2f pos);

  // virtual void criarCaixa(const Vector2f pos);
  virtual void criarEntidades(char letra, const Vector2f pos);

  virtual void criarFundo() = 0;  // fundo
  virtual void criarMapa() = 0;
  virtual void desenhar() = 0;

  // ===/===/===/===/ Outros  ===/===/===/===/
};
}  // namespace Fases

#endif