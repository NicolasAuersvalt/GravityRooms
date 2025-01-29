#include "Entidades/entidade.h"

namespace Entidades {

	Entidade::Entidade(const Vector2f pos, const Vector2f tam, const IDs::IDs ID)
		: Ente(ID), pos(pos), tam(tam) {
			corpo.setPosition(pos);
		}

	Entidade::~Entidade() {}

	void Entidade::setTamanho(const Vector2f tam) {
		corpo.setSize(tam);
		this->tam = tam;
	}

	const Vector2f Entidade::getPosicao() const { return pos; }

	const Vector2f Entidade::getTamanho() const { return tam; }

	void Entidade::setPosicao(int x, int y) {
		pos.x = x;

		pos.y = y;
	}
}  // namespace Entidades
