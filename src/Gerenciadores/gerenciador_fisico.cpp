#include "Gerenciadores/gerenciador_fisico.h"

namespace Gerenciadores {
float Gerenciador_Fisica::aplicarGravidade() {
  // Aplica a gravidade ao objeto, alterando sua velocidade na direção Y
  return velocidade.y +=
         gravidade * tempo; // Acelerando na direção Y devido à gravidade
}

void Gerenciador_Fisica::atualizarPosicao() {
  // Atualiza a posição do objeto com base na velocidade
  posicao.y += velocidade.y * tempo;

  // Se a posição chegar ao chão (y > 500, por exemplo), a velocidade é zerada
  // para simular colisão com o chão
  if (posicao.y >= 500.f) {
    posicao.y = 500.f;
    velocidade.y = 0.f;
  }
}
void Gerenciador_Fisica::processarFisica() {
  while (true) {
    this_thread::sleep_for(
        chrono::milliseconds(16)); // Simula o tempo de cada frame

    lock_guard<mutex> lock(mtx); // Garante acesso seguro aos dados compartilhados
    aplicarGravidade();
    atualizarPosicao();
  }
}

Vector2f Gerenciador_Fisica::getPosicao() const { return posicao; }

void Gerenciador_Fisica::setPosicao(const Vector2f &novaPosicao) {
  posicao = novaPosicao;
}

double Gerenciador_Fisica::gravidadePersonagemBuracoNegro(float velFinalX) {

  double M = 1.989e30 * 10;     // Massa do buraco negro (10 massas solares)
  const double G = 6.67430e-11; // Constante gravitacional (m^3 kg^-1 s^-2)
  const double m = 70;          // Massa do personagem (kg)
  const double a = 1.0;         // Distância inicial (m)
  const double b = 0.1;         // Distância final (m)
  const int n = 100; // Número de subdivisões para precisão de 5 casas
  double soma = 0.0;
  double dx = (b - a) / n;

  for (int i = 0; i < n; i++) {
    double x = a + i * dx; // Ponto na subdivisão
    soma += (G * M * m) / (x * x) * abs(dx);
  }

  return (soma/1e15);
}
} // namespace Gerenciadores
