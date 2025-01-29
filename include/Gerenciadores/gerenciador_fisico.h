#ifndef GERENCIADOR_FISICO_H
#define GERENCIADOR_FISICO_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
using namespace sf;

namespace Gerenciadores
{

	class Gerenciador_Fisica 
	{
		private:
			const double G = 6.674e-11;            // Constante gravitacional
			const double massaPersonagem = 70.0;   // Massa do personagem (kg)
			const double massaBuracoNegro = 1e12;  // Massa do buraco negro pequeno (kg)
			const double distanciaInicial = 1.0;   // Distância inicial (m)
			const double distanciaFinal = 10.0;    // Distância final (m)
			int m1 = 70;
			int m2 = 200;

			const int passos = 1000;  // Número de divisões

			Vector2f velocidade;  // Velocidade do personagem
			Vector2f posicao;     // Posição do personagem

			float gravidade = 10.0f;  // Gravidade (m/s^2) //ALTERADO PRA TESTES
			float tempo = 0.016f;     // Tempo de simulação (60 FPS por padrão)

			mutex mtx;  // Mutex para sincronização

		public:
			Gerenciador_Fisica(Vector2f posicaoInicial)
				: posicao(posicaoInicial), velocidade(0.f, 0.f) {}

			//   void aplicarGravidade() {
			//     // Aplica a gravidade ao objeto, alterando sua velocidade na direção Y
			//     velocidade.y +=
			//         gravidade * tempo;  // Acelerando na direção Y devido à gravidade
			//   }
			float aplicarGravidade();

			void atualizarPosicao();

			void processarFisica();

			// Getter para a posição (para renderizar no jogo)
			Vector2f getPosicao() const;

			// Setter para a posição (se necessário)
			void setPosicao(const Vector2f& novaPosicao);

			// Método para gravidade aproximada do personagem e do buraco negro
			double gravidadePersonagemBuracoNegro(int casasDecimais);

			/*

			// Verifica colisão com outro personagem ou objeto
			sf::FloatRect boundingBox = getSprite().getGlobalBounds();  // A caixa
			delimitadora do personagem

			// Exemplo de outro objeto ou personagem
			sf::FloatRect boundingBoxOutroPersonagem =
			outroPersonagem.getSprite().getGlobalBounds();

			if (verificarColisao(boundingBox, boundingBoxOutroPersonagem)) {
			// Se colidir com outro personagem, faça algo, por exemplo:
			std::cout << "Colisão detectada!" << std::endl;
			// Impedir o movimento ou aplicar outra lógica
			}

*/
	};
}

#endif
