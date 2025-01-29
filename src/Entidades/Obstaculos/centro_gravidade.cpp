#include "Entidades/Obstaculos/centro_gravidade.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace Entidades::Obstaculos;

namespace Entidades::Obstaculos {

	Centro_Gravidade::Centro_Gravidade(const sf::Vector2f pos,
			const sf::Vector2f tam, const IDs::IDs ID)
		: Obstaculo(pos, tam, ID) {
			this->dano = 10;
			setSprite("assets/gravidadeG.png", pos.x, pos.y);
			setTamanho(sf::Vector2f(45.0f, 150.0f));
			setPosicao(pos.x, pos.y);

			sprite.setPosition(pos.x, pos.y);
			std::cout << "centro_gravidade Position: " << pos.x << " " << pos.y
				<< std::endl;
		}

	Centro_Gravidade::~Centro_Gravidade() {}
	void Centro_Gravidade::executar() {
		mover();
		desenhar();
	}

	void Centro_Gravidade::mover() {}
	void Centro_Gravidade::salvar() {}
	void Centro_Gravidade::colisao(Entidade* outraEntidade, sf::Vector2f ds) {}

	int Centro_Gravidade::getDano() { return dano; }
}  // namespace Entidades::Obstaculos
