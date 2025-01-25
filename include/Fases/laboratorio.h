#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "Fases/fase.h"

using namespace std;

using namespace Fases;
namespace Fases {

class Laboratorio : public Fase {
 private:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 protected:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // ===/===/===/===/ Outros  ===/===/===/===/

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  const int maxChefoes = 1;

  Laboratorio();
  ~Laboratorio();

  void criarChefoes();
  void criarObstMedios();
  void criarProjeteis();

  void criarFundo() override;
  void criarMapa() override;

  // ===/===/===/===/ Outros  ===/===/===/===/
};
}  // namespace Fases

#endif