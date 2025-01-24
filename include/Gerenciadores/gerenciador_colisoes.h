#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

#include"Gerenciadores/gerenciador_grafico.h"
#include"Entidades/Personagens/inimigo.h"
#include"Entidades/Personagens/tripulante.h"
#include"Entidades/projetil.h"
#include"Entidades/Obstaculos/obstaculo.h"
#include"Gerenciadores/gerenciador_grafico.h"

// Precisa conhecer entidade
#include"Entidades/entidade.h"

#include <iostream>
#include <list>
#include <set>
#include <vector>

using Entidades::Obstaculos::Obstaculo;
using Entidades::Personagens::Inimigo;
using Entidades::Personagens::Tripulante;
using Entidades::Projetil;
using Gerenciadores::Gerenciador_Grafico;

using namespace Entidades;

class Obstaculo;

namespace Gerenciadores{

	class Gerenciador_Colisoes{

		private:

			// ===/===/===/===/ Obrigatório ===/===/===/===/

			vector<Inimigo*> LIs;  
			list<Obstaculo*> LOs;   
			set<Projetil*> LPs;     
			Tripulante *pJog1;

			// ===/===/===/===/ Outros ===/===/===/===/

		public:

			// ===/===/===/===/ Obrigatórios ===/===/===/===/

			// Construtor (FALTA)
			Gerenciador_Colisoes();

			// Destrutor (FALTA)
			~Gerenciador_Colisoes();


			const bool verificarColisao(Entidade *pe1, Entidade *pe2);
			void tratarColisoesJogsObstacs();
			void tratarColisoesJogsInimgs();
			void ColisoewsJogsProjeteis();
			void incluirInimigo(Inimigo *pi);
			void incluirObstaculo(Obstaculo *po);
			void incluirProjetil(Projetil *pj);
			void executar();


			// ===/===/===/===/ Outros  ===/===/===/===/

			void incluirTripulante(Tripulante &Tripulante){
				pJog1 = &Tripulante;
			}


		protected:

			// ===/===/===/===/ Obrigatório ===/===/===/===/


			// ===/===/===/===/ Outros ===/===/===/===/




	};

} using namespace Gerenciadores;

#endif
