#ifndef FASE_H
#define FASE_H

#include "Gerenciadores/gerenciador_colisoes.h"
#include "Lista/lista_entidades.h"
#include "ente.h"

class Jogo;
class Gerenciador_Colisoes;
using namespace sf;

namespace Fases {

class Fase : protected Ente {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/
  Gerenciadores::Gerenciador_colisoes GC;
  Lista::Lista_entidades listaPersonagens;
  Lista::Lista_entidades listaObstaculos;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // Fase(const IDs IDs_Fase,const IDs IDs_Fundo);
  Fase();
  ~Fase();

  void executar();
  void desenhar();
  // void gerenciar_colisoes();
  // void cirarInimFaceis();
  // void criarPlataformas();

  // virtual void criarInimigos(const Vector2f pos);
  // virtual void criarJogador(const Vector2f pos);
  // virtual void criarObstaculo(const Vector2f pos); //plataforma
  // virtual void criarCaixa(const Vector2f pos);
  // virtual void criarEntidades(char letra, const Vector2f pos);

  // virtual void criarCenario() =0; //fundo
  // virtual void criarMapa() =0;

  // ===/===/===/===/ Outros  ===/===/===/===/
};
}  // namespace Fases

#endif