#include "Fases/laboratorio.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Fases/fase.h"
#include "Gerenciadores/gerenciador_grafico.h"
using namespace sf;
using namespace std;

namespace Fases {

	// Construtor
	Laboratorio::Laboratorio(const IDs::IDs IDs)
		: Fase(ID, IDs::IDs::fundo_laboratorio) {
			criarFundo();
		}

	// Destrutor
	Laboratorio::~Laboratorio() {}

	void Laboratorio::criarProjeteis() {}

	void Laboratorio::criarMapa() {
		//   criarJogador(Vector2f(100.0f, 400.0f));
		//   for (int i = 0; i < 10; i++) {
		//     criarPlataforma(Vector2f(i * 300.0f, 550.0f));
		//   }
		//   for (int i = 0; i < 2; i++) {
		//     criarPlataforma(Vector2f(500.0f * (i + 1), 0.0f));
		//   }
		//   criarPlataforma(Vector2f(500.0f, 400.0f));

		//   criarPlataforma(Vector2f(900.0f, 400.0f));

		//   criarPlataforma(Vector2f(1200.0f, 400.0f));

		//   criarPlataforma(Vector2f(1100.0f, 250.0f));

		//   criarEspinho(Vector2f(400.0f, 500.0f));

		//   criarCentroGravidade(Vector2f(100.0f, 80.0f));

		std::ifstream arquivo;
		string linha;
		arquivo.open("assets/mapa.txt");
		if (!arquivo.is_open()) {
			cout << "Erro ao abrir o arquivo" << endl;
			exit(1);
		}
		int j = 0;
		while (getline(arquivo, linha)) {
			for (int i = 0; i < linha.size(); i++) {
				if (linha[i] != ' ') {
					criarEntidades(linha[i],
							Vector2(static_cast<float>(i), static_cast<float>(j)));
				}
			}
			j++;
		}
		arquivo.close();
	}

	void Laboratorio::criarFundo() {
		std::cout << "Loading background texture..." << std::endl;

		if (!bgTexture.loadFromFile("assets/lab.png")) {
			std::cerr << "Failed to load background texture!" << std::endl;
			return;
		}

		std::cout << "Texture loaded successfully" << std::endl;
		backgroundSprite.setTexture(bgTexture);
		backgroundSprite.setPosition(0.0f, 0.0f);
	}
	void Laboratorio::desenhar() {
		pGG->desenhar(backgroundSprite);
		Fase::desenhar();  // Call parent's draw method
	}
}  // namespace Fases
