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

  // Gerenciador_Colisoes GC;

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/
  Gerenciadores::Gerenciador_Colisoes GC;
  Listas::Lista_Entidades* listaPersonagens;
  Listas::Lista_Entidades* listaObstaculos;
  Gerenciadores::Gerenciador_Colisoes* pColisao;
  == == == =
               // Gerenciador_Colisoes GC;
                    
>>>>>>> parent of 05a9e64 (fase de inicio)

      // ===/===/===/===/ Outros  ===/===/===/===/

      protected :
      // ===/===/===/===/ Obrigatório ===/===/===/===/
      Entidades::Personagens::Tripulante *
      tripulante;
  // ===/===/===/===/ Outros  ===/===/===/===/
  Gerenciadores::Gerenciador_Colisoes GC;
  Gerenciadores::Gerenciador_Colisoes* pColisao;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  Listas::Lista_Entidades* listaObstaculos;

  Listas::Lista_Entidades* listaPersonagens;
  // Fase(const IDs IDs_Fase,const IDs IDs_Fundo);
  Fase();
  ~Fase();

  void executar();
  void desenhar();
  // void gerenciar_colisoes();
  void criarInimFaceis(const Vector2f pos,
                       Entidades::Personagens::Tripulante* tripulante);
  // void criarPlataformas();

  void criarInimDificeis(const Vector2f pos);
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

  // ===/===/===/===/ Outros  ===/===/===/===/
};
}  // namespace Fases

#endif