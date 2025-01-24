#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include "Entidades/Personagens/personagem.h"
#include "json.hpp"

#include <iostream>

using namespace sf;
using namespace std;


namespace Entidades::Personagens{

	class Tripulante : public Personagem{

		private:

			// ===/===/===/===/ Obrigatório ===/===/===/===/
			int pontos;


			// ===/===/===/===/ Outros  ===/===/===/===/

		protected:

			// ===/===/===/===/ Obrigatório ===/===/===/===/



			// ===/===/===/===/ Outros  ===/===/===/===/


		public:

			// ===/===/===/===/ Obrigatório ===/===/===/===/

			Tripulante(const Vector2f pos, const Vector2f tam);
			~Tripulante();

			void carregarDataBuffer(const nlohmann::ordered_json& json); 

			// virtual void executar() override;
			virtual void salvarDataBuffer(nlohmann::ordered_json& json) override; 
			virtual void mover() override; 

			int getPontos();	
			void setPontos(int ponto);

			// ===/===/===/===/ Outros  ===/===/===/===/


	};

}

#endif
