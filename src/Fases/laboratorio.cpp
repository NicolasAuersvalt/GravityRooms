#include "Fases/laboratorio.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Fases/fase.h"
#include "Gerenciadores/gerenciador_grafico.h"

namespace Fases {

REGISTRAR_CLASSE(Laboratorio, "laboratorio");
// Construtor
Laboratorio::Laboratorio(const IDs::IDs ID)
    : Fase(ID, IDs::IDs::fundo_laboratorio) {
  criarFundo();
}
Laboratorio::Laboratorio(const Vector2f pos, const Vector2f tam,
                         const IDs::IDs ID)
    : Fase(ID, IDs::IDs::fundo_laboratorio) {
  criarFundo();
}
// Destrutor
Laboratorio::~Laboratorio() {}

void Laboratorio::criarProjeteis() {}

void Laboratorio::criarMapa() {
  ifstream arquivo;
  string linha;
  arquivo.open("assets/mapa.txt");

  if (!arquivo.is_open()) {
    cout << "Erro ao abrir o arquivo" << endl;
    exit(1);
  }
  int j = 0;

  while (getline(arquivo, linha)) {
    for (int i = 0; i < linha.size(); i++) {
      if (linha[i] != ' ') {
        criarEntidades(linha[i],
                       Vector2(static_cast<float>(i), static_cast<float>(j)));
      }
    }
    j++;
  }
  arquivo.close();
}

void Laboratorio::salvar(json &arquivo) override {
  arquivo["id"] = static_cast<int>(getID());
  arquivo["posicao"]["x"] = 0.0f;
  arquivo["posicao"]["y"] = 0.0f;
  arquivo["tipo"] = "laboratorio";
}


void Laboratorio::criarFundo() {
  if (!bgTexture.loadFromFile("assets/lab.png")) {
    cerr << "Failed to load background texture!" << endl;
    return;
  }

  backgroundSprite.setTexture(bgTexture);
  backgroundSprite.setPosition(0.0f, 0.0f);
}
void Laboratorio::desenhar() {
  pGG->desenhar(backgroundSprite);
  Fase::desenhar();
}
}  // namespace Fases
