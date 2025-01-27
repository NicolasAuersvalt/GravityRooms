#ifndef FASE_H
#define FASE_H

#include "ente.h"
#include "Gerenciadores/gerenciador_colisoes.h"
#include "Listas/lista_entidades.h"
#include "ente.h"

class Jogo;
class Gerenciador_Colisoes;
using namespace sf;

namespace Fases {

class Fase : protected Ente {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

            // Gerenciador_Colisoes GC;
                    

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