#include "Fases/laboratorio.h"

#include <iostream>

#include "Fases/fase.h"
// ===/===/===/===/ Obrigatório ===/===/===/===/
namespace Fases {

// Construtor
Laboratorio::Laboratorio() {}

// Destrutor
Laboratorio::~Laboratorio() {}

void Laboratorio::criarChefoes() {}

void Laboratorio::criarObstMedios() {}

void Laboratorio::criarProjeteis() {}

void Laboratorio::criarMapa() { criarPlataforma(Vector2f(100.0f, 80.0f)); }

void Laboratorio::criarFundo() { std::cout << "bloo\n"; }
}  // namespace Fases