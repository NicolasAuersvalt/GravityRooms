#ifndef GERENCIADOR_SALVAMENTO_H
#define GERENCIADOR_SALVAMENTO_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <mutex>
#include <filesystem>
#include "json.hpp"
#include "Entidades/Personagens/tripulante.h"// Incluindo o cabeçalho completo do Tripulante

using json = nlohmann::json;
using namespace std;
using namespace sf;

namespace Entidades::Personagens{
	class Tripulante;
}

namespace Gerenciadores {

    class Gerenciador_Salvamento {

    private:
        mutex mtx;
        Entidades::Personagens::Tripulante* pJog1;
        string nome = "Jogador1";

    public:
        Gerenciador_Salvamento();
        ~Gerenciador_Salvamento();

        void setJogador(Entidades::Personagens::Tripulante* jogador);
        Entidades::Personagens::Tripulante* getJogador();

        // Serializa o objeto Jogador para JSON
        json toJson() const;

        // Função para verificar se o arquivo existe
        bool arquivoExiste(const string& caminho);
    };

}

#endif
