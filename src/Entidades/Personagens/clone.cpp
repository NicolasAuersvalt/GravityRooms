#include "Entidades/Personagens/clone.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;


namespace Entidades::Personagens{


	Clone::Clone(const sf::Vector2f pos, Tripulante* tripulante):
		Inimigo(pos, Vector2f(0.0f, 0.0f), tripulante)
	{

	}

	Clone::~Clone(){


	}
	void Clone::executar(){

	}

	void Clone::danificar(Tripulante* p){

	}
}  
