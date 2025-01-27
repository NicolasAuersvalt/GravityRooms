#include "Gerenciadores/gerenciador_colisoes.h"

namespace Gerenciadores {
// Construtor
Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), LPs() {
  // Inicializações necessárias
  LIs.clear();
  LOs.clear();
  LPs.clear();
}

// Destrutor
Gerenciador_Colisoes::~Gerenciador_Colisoes() {
  // Limpar listas e recursos, se necessário
  LIs.clear();
  LOs.clear();
  LPs.clear();
  pJog1 = nullptr;
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade *pe1,
                                                  Entidade *pe2) {
  if (pe1 && pe2) {  // Verifica se os ponteiros não são nulos

    return pe1->getHitBox().intersects(pe2->getHitBox());
  }
  return false;
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
  pJog1->setPisando(false);
  for (auto obstaculo : LOs) {
    if (verificarColisao(pJog1, obstaculo)) {
      // Lógica para quando o Tripulante colide com o obstáculo
      pJog1->setPisando(true);
      obstaculo->setColidindo(true);
    }
  }
}
void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {
  for (auto inimigo : LIs) {
    // Verifica se há colisão entre o Tripulante e o inimigo
    if (verificarColisao(pJog1, inimigo)) {
      pJog1->recebeDano(inimigo->getDano());
    }
  }
}

void Gerenciador_Colisoes::ColisoesJogsProjeteis() {
  for (auto projetil : LPs) {
    if (verificarColisao(pJog1, projetil)) {
      pJog1->recebeDano(projetil->getDano());
    }
  }
}
void Gerenciador_Colisoes::incluirInimigo(Inimigo *pi) {
  // Adiciona o inimigo à lista de inimigos
  LIs.push_back(pi);
}

void Gerenciador_Colisoes::incluirObstaculo(Obstaculo *po) {
  // Adiciona o obstáculo à lista de obstáculos
  LOs.push_back(po);
}

void Gerenciador_Colisoes::incluirProjetil(Projetil *pj) {
  // Adiciona o projetil ao conjunto de projetis
  LPs.insert(pj);
}

void Gerenciador_Colisoes::executar() {
  tratarColisoesJogsObstacs();

  // // Verificar colisões entre o Tripulante e os Inimigos
  tratarColisoesJogsInimgs();

  // // Verificar colisões entre o Tripulante e os Projetis
  ColisoesJogsProjeteis();
}
}  // namespace Gerenciadores