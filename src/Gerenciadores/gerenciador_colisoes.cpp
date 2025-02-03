#include "Gerenciadores/gerenciador_colisoes.h"

namespace Gerenciadores {

// Construtor
Gerenciador_Colisoes::Gerenciador_Colisoes(
    Listas::Lista_Entidades* listaPersonagem,
    Listas::Lista_Entidades* listaObstaculo)
    : LIs(),
      LOs(),
      LPs(),
      pJog1(nullptr),
      pJog2(nullptr),
      listaPersonagem(listaPersonagem),
      listaObstaculo(listaObstaculo) {
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

// const bool Gerenciador_Colisoes::verificarColisao(Entidade *pe1,
//                                                   Entidade *pe2) {
//     if (pe1 && pe2) {  // Verifica se os ponteiros não são nulos

//     return pe1->getHitBox().intersects(pe2->getHitBox());
//   }
//   return false;
// }

// void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
//   pJog1->setPisando(false);
//   for (auto obstaculo : LOs) {
//     if (verificarColisao(pJog1, obstaculo)) {
//       // Lógica para quando o Tripulante colide com o obstáculo
//       pJog1->setPisando(true);
//       obstaculo->setColidindo(true);
//     }
//   }
// }
// void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {
//   for (auto inimigo : LIs) {
//     // Verifica se há colisão entre o Tripulante e o inimigo
//     if (verificarColisao(pJog1, inimigo)) {
//       pJog1->recebeDano(inimigo->getDano());
//     }
//   }
// }

// void Gerenciador_Colisoes::ColisoesJogsProjeteis() {
//   for (auto projetil : LPs) {
//     if (verificarColisao(pJog1, projetil)) {
//       pJog1->recebeDano(projetil->getDano());
//     }
//   }
// }

// void Gerenciador_Colisoes::incluirInimigo(Inimigo *pi) {
//   // Adiciona o inimigo à lista de inimigos
//   LIs.push_back(pi);
// }

// void Gerenciador_Colisoes::incluirObstaculo(Obstaculo *po) {
//   // Adiciona o obstáculo à lista de obstáculos
//   LOs.push_back(po);
// }

// void Gerenciador_Colisoes::incluirProjetil(Projetil *pj) {

//   // Adiciona o projetil ao conjunto de projetis
//   LPs.insert(pj);

// }

// void Gerenciador_Colisoes::executar() {

//   tratarColisoesJogsObstacs();

//   // // Verificar colisões entre o Tripulante e os Inimigos
//   tratarColisoesJogsInimgs();

//   // // Verificar colisões entre o Tripulante e os Projetis
//   ColisoesJogsProjeteis();

// }
/*---------------------------------------------------------------------------------------------------*/
const sf::Vector2f Gerenciador_Colisoes::calculaColisao(
    Entidades::Entidade* ent1, Entidades::Entidade* ent2) {
  sf::Vector2f pos1 = ent1->getSprite().getPosition();
  sf::Vector2f pos2 = ent2->getSprite().getPosition();

  sf::Vector2f tam1 = ent1->getTamanho();
  sf::Vector2f tam2 = ent2->getTamanho();

  sf::Vector2f distanciaEntreCentros(
      fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
      fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));
  sf::Vector2f somaMetadeRectangulo(tam1.x / 2.0f + tam2.x / 2.0f,
                                    tam1.y / 2.0f + tam2.y / 2.0f);
  return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x,
                      distanciaEntreCentros.y - somaMetadeRectangulo.y);
}

void Gerenciador_Colisoes::executar(Lista_Entidades* listaPer,
                                    Lista_Entidades* listaObs) {
  if (!listaPer || !listaObs) {
    cout << "Lista nula encontrada" << endl;
    return;
  }
  // Verificar colisões do Jogador 1

  // for (int i = 0; i < listaPer->getTamanho(); i++) {
  //   cout << "aio  " << listaPer->getTamanho() << endl;
  //   Entidades::Personagens::Personagem* personagem =
  //       dynamic_cast<Entidades::Personagens::Personagem*>(
  //           listaPer->operator[](i));
  //   if (personagem && !personagem->verificarVivo()) {
  //     listaPer->removerEntidade(static_cast<Entidades::Entidade*>(personagem),
  //                               true);

  //     cout << "aio  " << listaPer->getTamanho() << endl;
  //     i--;
  //     continue;
  //   }
  // }

  // In Gerenciador_Colisoes::executar()
  // Replace the existing dead entity removal loop with:
  for (int i = listaPer->getTamanho() - 1; i >= 0; i--) {  // Iterate backward
    Entidades::Personagens::Personagem* personagem =
        dynamic_cast<Entidades::Personagens::Personagem*>(
            listaPer->operator[](i));
    if (personagem && !personagem->verificarVivo()) {
      Entidades::Personagens::Inimigo* inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo*>(personagem);

      if (inimigo && pJog1) {
        pJog1->setPontos(pJog1->getPontos() + inimigo->getNivelMaldade());
        std::cout << "Player points: " << pJog1->getPontos() << std::endl;
      }

      listaPer->removerEntidade(personagem, true);  // Delete entity and node
      std::cout << "Removed dead entity. New size: " << listaPer->getTamanho()
                << std::endl;
    }
  }

  // In the Personagem vs Personagem loop:
  for (int i = 0; i < listaPer->getTamanho() - 1; i++) {
    Entidades::Entidade* ent1 = listaPer->operator[](i);
    if (!ent1) continue;  // Skip if null

    for (int j = i + 1; j < listaPer->getTamanho(); j++) {
      Entidades::Entidade* ent2 = listaPer->operator[](j);
      if (!ent2) continue;  // Skip if null

      sf::Vector2f ds = calculaColisao(ent1, ent2);
      if (ds.x < 0.0f && ds.y < 0.0f) {
        ent1->colisao(ent2, ds);
        ent2->colisao(ent1, ds);  // Ensure both entities process collisions
      }
    }
  }

  // verifica colisao entre Personagens e Obstáculos
  for (int i = 0; i < listaPer->getTamanho(); i++) {
    Entidades::Entidade* ent1 = listaPer->operator[](i);
    for (int j = 0; j < listaObs->getTamanho(); j++) {
      Entidades::Entidade* ent2 = listaObs->operator[](j);
      sf::Vector2f ds = calculaColisao(ent1, ent2);

      if (ds.x < 5.0f && ds.y < 5.0f) {
        // std::cout << "Character " << i << " collided with obstacle " << j
        //         << " with ds(" << ds.x << "," << ds.y << ")\n";
        ent1->colisao(ent2, ds);
      }
    }
  }
}
}  // namespace Gerenciadores
