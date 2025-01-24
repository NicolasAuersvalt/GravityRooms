#include "Entidades/Personagens/personagem.h"
// #include "gerenciador_grafico.h"

#include <iostream>

using namespace std;
using namespace Entidades::Personagens;

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Entidades::Personagens {

	Personagem::Personagem(const Vector2f pos, const Vector2f tam)
		: Entidade(pos, tam), noChao(false) {


		}

	Personagem::~Personagem() 
	{

	}
	void Personagem::salvar() 
	{

	}

}

const RectangleShape& Personagem::getCorpo() const
{
	return RectangleShape();
}

/*
const RectangleShape& Personagem::getCorpo() {
	return corpo;
}
*/


int Personagem::getVida() {
	return pontosVida;
}

void Personagem::setVida(int life) {
	pontosVida = life;
}

void Personagem::recebeDano(int dano) {

	pontosVida -= dano;

	if (!verificarVivo()) {
		morrer();
	}
}

bool Personagem::verificarVivo() { 
	return (pontosVida > 0); 
}

void Personagem::morrer() {
	cout << "Fulano Morreu" << endl;
	// Aqui você pode adicionar lógica para remover da lista de entidades, se necessário.
}

void Personagem::setPisando(bool pisa) {
	noChao = pisa;
}

bool Personagem::getPisando() {
	return noChao;
}
