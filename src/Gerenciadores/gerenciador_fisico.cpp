#include "Gerenciadores/gerenciador_fisico.h"

namespace Gerenciadores {
float Gerenciador_Fisica::aplicarGravidade() {
  // Aplica a gravidade ao objeto, alterando sua velocidade na direção Y
  return velocidade.y +=
         gravidade * tempo;  // Acelerando na direção Y devido à gravidade
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
double Gerenciador_Fisica::calcularSomaRiemann(double M, double G, double m, double a, double b, int n) {
  double somaLocal = 0.0;
  double dx = (b - a) / n;

  for (int i = 0; i < n; i++) {
      double x = a + i * dx;
      double termo = (G * M * m) / (x * x) * abs(dx);

      lock_guard<mutex> lock(mtx);
      somaLocal += termo;
  }

  lock_guard<mutex> lock(mtx);
  soma = somaLocal;
  return soma;
}

Vector2f Gerenciador_Fisica::getPosicao() const { return posicao; }

void Gerenciador_Fisica::setPosicao(const Vector2f &novaPosicao) {
  posicao = novaPosicao;
}

double Gerenciador_Fisica::gravidadePersonagemBuracoNegro() {
  lock_guard<mutex> lock(mtx);
  return sqrt((soma * 2 / 1e15));
}


double Gerenciador_Fisica::executarGravitacional() {
  double M = 1.989e30 * 10;     // Massa do buraco negro (10 massas solares)
  const double G = 6.67430e-11; // Constante gravitacional (m^3 kg^-1 s^-2)
  const double m = 70;          // Massa do personagem (kg)
  const double a = 1.0;         // Distância inicial (m)
  const double b = 0.1;         // Distância final (m)
  const int n = 100;            // Número de subdivisões para precisão de 5 casas

  double resultado = 0.0;

  // Usando a classe Thread para gerenciar a criação e o join das threads
  Gerenciador_Thread threadSoma(&Gerenciador_Fisica::calcularSomaRiemann, this, M, G, m, a, b, n);
  
  Gerenciador_Thread threadGravidade([this, &threadSoma, &resultado]() {
    threadSoma.join(); // Aguarda a soma de Riemann ser concluída
    resultado = gravidadePersonagemBuracoNegro(); // Exemplo de valor de velFinalX
  });

  threadGravidade.join(); // Aguarda o cálculo da gravidade

  return resultado;
}


}  // namespace Gerenciadores
