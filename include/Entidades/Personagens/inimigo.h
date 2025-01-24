#ifndef INIMIGO_H
#define INIMIGO_H

#include <cmath>
#include <time.h>
#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f
#define VELOCIDADE_INIMIGO_X 0.025f
#define VELOCIDADE_INIMIGO_Y 0.025f

#include "Entidades/Personagens/personagem.h"
#include "Entidades/Personagens/tripulante.h"

//using Entidades::Personagens; 
using namespace sf;
using namespace std;

namespace Entidades::Personagens {

	class Inimigo : public Personagem {
		private:

			// ===/===/===/===/ Obrigatório ===/===/===/===/

			int dano = 10;

			// ===/===/===/===/ Outros  ===/===/===/===/


		protected:
			// ===/===/===/===/ Obrigatório ===/===/===/===/
			int nivel_maldade;

			// ===/===/===/===/ Outros  ===/===/===/===/
			Tripulante* tripulante;
			Clock relogio;
			short moverAleatorio;
			void inicializar();

		public:
			// ===/===/===/===/ Obrigatório ===/===/===/===/

			Inimigo(const Vector2f pos, const Vector2f tam, Tripulante* tripulante);
			~Inimigo();

			virtual void salvarDataBuffer(nlohmann::ordered_json& json) override;
			virtual void danificar(Tripulante* p) = 0;
			virtual void executar() = 0;
			virtual void colidir(Entidade* outro, string direction = "") = 0;
			virtual void mover();  // n virtual puro por enquanto

			virtual int getDano() {

				// Por exemplo, retornar o dano base multiplicado pelo nivel de maldade
				return dano;
			}

			void perseguirTripulante(sf::Vector2f posTripulante, const sf::Vector2f posInimigo);
			void movimentarAleatorio();
	};

}  // namespace Entidades::Personagens

#endif
