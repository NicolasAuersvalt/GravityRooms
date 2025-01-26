#include "Fases/laboratorio.h"

#include <iostream>

#include "Fases/fase.h"
using namespace sf;
// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {

// Construtor
Laboratorio::Laboratorio() {}

// Destrutor
Laboratorio::~Laboratorio() {}

void Laboratorio::criarChefoes() {}

void Laboratorio::criarObstMedios() {}

void Laboratorio::criarProjeteis() {}

void Laboratorio::criarMapa() {
  criarJogador(Vector2f(100.0f, 400.0f));
  for (int i = 0; i < 10; i++) {
    criarPlataforma(Vector2f(i * 300.0f, 550.0f));
  }
  for (int i = 0; i < 2; i++) {
    criarPlataforma(Vector2f(500.0f * (i + 1), 0.0f));
  }
  cout << "criacao de itens1" << endl;
  criarPlataforma(Vector2f(500.0f, 400.0f));

  cout << "criacao de itens2" << endl;
  criarPlataforma(Vector2f(900.0f, 400.0f));

  cout << "criacao de itens3" << endl;
  criarPlataforma(Vector2f(1200.0f, 400.0f));

  cout << "criacao de itens4" << endl;
  criarPlataforma(Vector2f(1100.0f, 250.0f));

  cout << "criacao de iten5s" << endl;
  criarEspinho(Vector2f(400.0f, 500.0f));

  cout << "criacao de iten54s" << endl;
  criarCentroGravidade(Vector2f(100.0f, 80.0f));

  cout << "criacao de iten5s5" << endl;
}

void Laboratorio::criarFundo() { std::cout << "bloo\n"; }
}  // namespace Fases