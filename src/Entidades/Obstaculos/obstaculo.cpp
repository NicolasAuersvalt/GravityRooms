#include "Entidades/Obstaculos/obstaculo.h"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Obstaculos
{

	Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam) : Entidade(pos, tam)
	{
	}

	Obstaculo::~Obstaculo()
	{
	}
	void Obstaculo::salvar()
	{
	}
	bool Obstaculo::getColidindo(){
		return colidindo;
	}

	void Obstaculo::setColidindo(bool colide){
		colidindo = colide;

	}
}
