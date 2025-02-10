#include "Gerenciadores/save.h"

#include "Entidades/Obstaculos/obstaculo.h"
#include "Entidades/Personagens/inimigo.h"
#include "Entidades/Personagens/tripulante.h"
#include "Entidades/background.h"
#include "Fases/fase.h"
#include "Gerenciadores/registry.h"

Save::Save() {}

Save::~Save() {}

void Save::setJogador(Entidades::Personagens::Tripulante *jogador) {}

void Save::gravarDados() {}

void Save::salvar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                  Lista_Entidades &listaObstaculo,
                  Lista_Entidades &listaBackgrounds, Fase *&fase,
                  const string &nomeArquivo) {
  json j;

  json fase_save_content;

  fase->salvar(fase_save_content);
  j["fase"].push_back(fase_save_content);

  j["entities"] = json::array();
  auto atual = listaPersonagem.LEs->getPrimeiro();
  while (atual != nullptr) {
    if (atual->pInfo) {
      json obj;
      atual->pInfo->salvar(obj);
      j["entities"].push_back(obj);
    }
    atual = atual->getProximo();
  }
  auto atual1 = listaBackgrounds.LEs->getPrimeiro();
  while (atual1 != nullptr) {
    if (atual1->pInfo) {
      json obj;
      atual1->pInfo->salvar(obj);
      j["entities"].push_back(obj);
    }
    atual1 = atual1->getProximo();
  }
  auto atual2 = listaObstaculo.LEs->getPrimeiro();
  while (atual2 != nullptr) {
    if (atual2->pInfo) {
      json obj;
      atual2->pInfo->salvar(obj);
      j["entities"].push_back(obj);
    }
    atual2 = atual2->getProximo();
  }

  ofstream arquivo(nomeArquivo);
  if (arquivo.is_open()) {
    arquivo << j.dump(4);  // Formatação bonita com 4 espaços
  }
}

bool Save::carregar(Gerenciador_Colisoes &GC, Lista_Entidades &listaPersonagem,
                    Lista_Entidades &listaObstaculo,
                    Lista_Entidades &listaBackgrounds, Fase *&fase,
                    const string &nomeArquivo) {
  ifstream arquivo(nomeArquivo);
  if (!arquivo.is_open()) {
    cerr << "Erro ao abrir arquivo de salvamento!\n";
    return false;
  }

  json dados;
  arquivo >> dados;

  // Carrega a fase
  if (dados.contains("fase") && dados["fase"].is_array() &&
      !dados["fase"].empty()) {
    auto &registry = Registry::getInstance();
    auto ente = registry.criar(dados["fase"][0]);
    fase = dynamic_cast<Fase *>(ente.release());

    if (!fase) {
      std::cerr << "Error: Failed to load Fase from JSON." << std::endl;
    }
  }

  // Carrega todas as entidades
  for (auto &entidadeData : dados["entities"]) {
    if (entidadeData.is_null() || !entidadeData.contains("tipo")) {
      continue;
    }

    string tipo = entidadeData["tipo"];
    auto &registry = Registry::getInstance();
    auto ente = registry.criar(entidadeData);
    if (ente) {
      // Adiciona nas listas apropriadas
      if (dynamic_cast<Personagem *>(ente.get())) {
        if (auto jogador = dynamic_cast<Tripulante *>(ente.get())) {
          if (!GC.pJog1) {
            GC.pJog1 = jogador;
            GC.pJog1->setPlayerOne(false);
            GC.pJog1->carregarDataBuffer(entidadeData);
          } else if (!GC.pJog2) {
            GC.pJog2 = jogador;
            GC.pJog2->setPlayerOne(true);
            GC.pJog2->carregarDataBuffer(entidadeData);
          }
        } else {
          if (GC.pJog1) {
            auto inimigo = dynamic_cast<Inimigo *>(ente.get());
            inimigo->setTripulante(GC.pJog1);
            if (entidadeData.contains("projetil")) {
              auto proj = registry.criar(entidadeData["projetil"]);
              if (proj) {
                listaPersonagem.incluir(
                    dynamic_cast<Entidade *>(inimigo->getProjetil()));
              }
            }
          }
        }

        listaPersonagem.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (dynamic_cast<Obstaculo *>(ente.get())) {
        listaObstaculo.incluir(dynamic_cast<Entidade *>(ente.release()));
      } else if (dynamic_cast<Background *>(ente.get())) {
        (dynamic_cast<Background *>(ente.get()))->setFase(fase);
        listaBackgrounds.incluir(dynamic_cast<Entidade *>(ente.release()));
      }
    }
  }
  auto atualPersonagens = listaPersonagem.LEs->getPrimeiro();
  while (atualPersonagens != nullptr) {
    if (dynamic_cast<Inimigo *>(atualPersonagens->pInfo))
      dynamic_cast<Inimigo *>(atualPersonagens->pInfo)->setTripulante(GC.pJog1);

    atualPersonagens = atualPersonagens->getProximo();
  }
  return true;
}