#ifndef PROJETIL_H
#define PROJETIL_H

#include "Entidades/Personagens/personagem.h"
#include "Entidades/entidade.h"
#include <iostream>

using namespace std;
using namespace Entidades;

namespace Entidades{
	class Personagem;

	class Projetil : public Entidade{

		private:

			// ===/===/===/===/ Obrigatório ===/===/===/===/

			static int danoProjetil;
			bool ativo;

			// ===/===/===/===/ Outros  ===/===/===/===/
			bool colidiu;
			Entidade* atirador;
			int dano;

		protected:

			// ===/===/===/===/ Obrigatório ===/===/===/===/



			// ===/===/===/===/ Outros  ===/===/===/===/


		public:

			// ===/===/===/===/ Obrigatório ===/===/===/===/

			Projetil();
			virtual ~Projetil();

			// Métodos Virtuais
			// void executar() override;

			// ===/===/===/===/ Outros  ===/===/===/===/

			//virtual void executar() override;
			//virtual void mover() override; 

			void atualizar();
			void setAtirador(Entidade* a); 
			void colisao(Entidade* e);
			bool getColidir(Entidade* e);
			void danificar(Personagem* p);
			int getDano();
	};

}

#endif
