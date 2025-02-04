#include "Fases/nave.h"

#include <fstream>
#include <iostream>
#include <string>

namespace Fases {

// Construtor
Nave::Nave(const IDs::IDs ID) : Fase(ID, IDs::IDs::fundo_nave) {}
// Destrutor
Nave::~Nave() {}

void Nave::criarInimMedios() {}

void Nave::criarObstMedios() {}
void Nave::criarFundo() {}
void Nave::criarMapa() {
  std::ifstream arquivo;
  string linha;
  arquivo.open("assets/mapa2.txt");
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
void Nave::desenhar() {}
}  // namespace Fases
