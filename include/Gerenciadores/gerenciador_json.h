#ifndef GERENCIADOR_JSON_H
#define GERENCIADOR_JSON_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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
        int x, y;
        string nome;
        int pontos;

    public:
        // Construtor e destruidor
        Gerenciador_Json();
        ~Gerenciador_Json();

        // Método para converter os dados para o formato JSON
        static json toJson(const int x, const int y, const string& nome);

        // Método para carregar os dados do arquivo JSON
        void carregarJson(const std::string& local, bool carregado);

        // Métodos de acesso
        string getNome() const;
        int getPontos() const;
        Vector2f getPos() const;

        // Método para gerar um objeto JSON
        json getJson(const std::string& local, const int x, const int y, const string& nome);
    };

}

#endif
