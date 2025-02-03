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

    lock_guard<mutex> lock(
        mtx); // Garante acesso seguro aos dados compartilhados
    aplicarGravidade();
    atualizarPosicao();
  }
}

Vector2f Gerenciador_Fisica::getPosicao() const { return posicao; }

void Gerenciador_Fisica::setPosicao(const Vector2f &novaPosicao) {
  posicao = novaPosicao;
}

double Gerenciador_Fisica::gravidadePersonagemBuracoNegro(int casasDecimais) {

  double deltaR =
      (distanciaFinal - distanciaInicial) / passos; // Largura dos subintervalos
  double soma = 0.0;

  for (int i = 0; i < passos; i++) {

    double r = distanciaInicial + i * deltaR; // Ponto do intervalo
    if (r == 0)
      continue;                               // Evita divisão por zero
    soma += (G * m1 * m2 / (r * r)) * deltaR; // Soma de Riemann
  }

  // Retorna o valor arredondado para o número de casas decimais especificado
  double fator = pow(10, casasDecimais);

  return round(soma * fator) / fator;
}
} // namespace Gerenciadores
