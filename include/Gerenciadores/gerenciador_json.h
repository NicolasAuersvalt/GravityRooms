#ifndef GERENCIADOR_JSON_H
#define GERENCIADOR_JSON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "dados.h"

// Persistência de arquivos
#include <iostream>
#include <fstream>
#include <string>

#include <mutex>
#include <filesystem>

#include "dados.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using namespace sf;

namespace Gerenciadores {

    class Gerenciador_Json {

    private:
        string nomeJ;
        int pontos;

    public:
        // Construtor e destruidor
        Gerenciador_Json();
        ~Gerenciador_Json();

        // Método para converter os dados para o formato JSON
        static json toJson(Dados &dados);

        // Método para carregar os dados do arquivo JSON
        void carregarJson(Dados& dados);

        // Método para gerar um objeto JSON
        json getJson(Dados &dados);
    };

}

#endif
