#ifndef FASE_H
#define FASE_H

#include "Gerenciadores/gerenciador_colisoes.h"
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

  // ===/===/===/===/ Outros  ===/===/===/===/
  Gerenciadores::Gerenciador_Colisoes GC;
  Listas::Lista_Entidades* listaPersonagens;
  Listas::Lista_Entidades* listaObstaculos;
  Gerenciadores::Gerenciador_Colisoes* pColisao;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // Fase(const IDs IDs_Fase,const IDs IDs_Fundo);
  Fase();
  ~Fase();

  void executar();
  void desenhar();
  // void gerenciar_colisoes();
  void criarInimFaceis();
  // void criarPlataformas();

  // virtual void criarInimigos(const Vector2f pos);
  void criarJogador(const Vector2f pos);
  void criarPlataforma(const Vector2f pos);
  void criarEspinho(const Vector2f pos);
  void criarCentroGravidade(const Vector2f pos);

  // virtual void criarCaixa(const Vector2f pos);
  // virtual void criarEntidades(char letra, const Vector2f pos);

  virtual void criarFundo() = 0;  // fundo
  virtual void criarMapa() = 0;

  // ===/===/===/===/ Outros  ===/===/===/===/
};
}  // namespace Fases

#endif