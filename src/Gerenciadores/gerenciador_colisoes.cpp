#include "Gerenciadores/gerenciador_colisoes.h"

namespace Gerenciadores {

// Construtor
Gerenciador_Colisoes::Gerenciador_Colisoes(
    Listas::Lista_Entidades *listaPersonagem,
    Listas::Lista_Entidades *listaObstaculo)
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

const sf::Vector2f Gerenciador_Colisoes::calculaColisao(
    Entidades::Entidade *ent1, Entidades::Entidade *ent2) {
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

void Gerenciador_Colisoes::executar(Lista_Entidades *listaPer,
                                    Lista_Entidades *listaObs) {
  if (!listaPer || !listaObs) {
    cout << "Lista nula encontrada" << endl;
    return;
  }

  for (int i = listaPer->getTamanho() - 1; i >= 0; i--) {
    Entidades::Personagens::Personagem *personagem =
        dynamic_cast<Entidades::Personagens::Personagem *>(
            listaPer->operator[](i));
    if (personagem && !personagem->verificarVivo()) {
      Entidades::Personagens::Inimigo *inimigo =
          dynamic_cast<Entidades::Personagens::Inimigo *>(personagem);

      if (inimigo && pJog1) {
        pJog1->setPontos(pJog1->getPontos() + inimigo->getNivelMaldade());
      }

      listaPer->removerEntidade(personagem, true);
    }
  }

  for (int i = 0; i < listaPer->getTamanho() - 1; i++) {
    Entidades::Entidade *ent1 = listaPer->operator[](i);
    if (!ent1) continue;

    for (int j = i + 1; j < listaPer->getTamanho(); j++) {
      Entidades::Entidade *ent2 = listaPer->operator[](j);
      if (!ent2) continue;

      sf::Vector2f ds = calculaColisao(ent1, ent2);
      if (ds.x < 0.0f && ds.y < 0.0f) {
        ent1->colisao(ent2, ds);
        ent2->colisao(ent1, ds);
      }
    }
  }

  for (int i = 0; i < listaPer->getTamanho(); i++) {
    Entidades::Entidade *ent1 = listaPer->operator[](i);
    for (int j = 0; j < listaObs->getTamanho(); j++) {
      Entidades::Entidade *ent2 = listaObs->operator[](j);
      sf::Vector2f ds = calculaColisao(ent1, ent2);

      if (ds.x < 5.0f && ds.y < 5.0f) {
        ent1->colisao(ent2, ds);
      }
    }
  }
}
}  // namespace Gerenciadores
