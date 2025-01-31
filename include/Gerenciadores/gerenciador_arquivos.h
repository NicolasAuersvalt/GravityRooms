#ifndef GERENCIADOR_ARQUIVOS_H
#define GERENCIADOR_ARQUIVOS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Entidades/Personagens/tripulante.h" // Incluindo o cabeçalho completo do Tripulante

// Persistência de arquivos
#include <iostream>
#include <fstream>
#include <string>

#include <mutex>
#include <filesystem>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using namespace sf;

namespace Entidades::Personagens {
    class Tripulante;
}

namespace Gerenciadores {

    class Gerenciador_Arquivos  {

    private:
        mutex mtx;
        int x, y; // As variáveis x e y, que irão armazenar a posição

    public:
        Gerenciador_Arquivos () : x(0), y(0) {}

        ~Gerenciador_Arquivos() {}

        virtual void salvarArquivo(const std::string& local, const json& j) {
            std::ofstream arquivo(local);
            if (arquivo.is_open()) {
                // Escrever o conteúdo do JSON no arquivo
                arquivo << j.dump(4);  // O '4' especifica a indentação (4 espaços)
                std::cout << "Salvamento concluído com sucesso em " << local << std::endl;

            } else {
                std::cerr << "Erro ao abrir o arquivo " << local << " para escrita." << std::endl;

            }
        }

        // Método para carregar os dados do arquivo
        virtual void carregar(const string& local){
            // Verifica se o arquivo existe
            std::cout << "Caminho do arquivo: " << local << std::endl;

            if (!arquivoExiste(local)) {
                std::cerr << "Erro: O arquivo não existe." << std::endl;
                return;
            }

            std::ifstream arquivoLeitura(local);

            // Verifica se o arquivo foi aberto com sucesso
            if (arquivoLeitura.is_open()) {
                json dadosCarregados;
                try {
                    // Tenta carregar os dados JSON do arquivo
                    arquivoLeitura >> dadosCarregados;

                    // Imprime o conteúdo lido para verificação
                    std::cout << "Conteúdo lido do arquivo: " << dadosCarregados.dump(4) << std::endl;

                    // Carrega as posições
                    x = dadosCarregados["x"];
                    y = dadosCarregados["y"];

                } catch (const json::parse_error& e) {
                    // Captura qualquer erro de parsing do JSON
                    std::cerr << "Erro ao parsear o arquivo JSON: " << e.what() << std::endl;
                }
            } else {
                std::cerr << "Erro ao abrir o arquivo " << local << " para leitura." << std::endl;
            }
        }
        

        // Função para verificar se o arquivo existe
        bool arquivoExiste(const string& local) const {
            return filesystem::exists(local);
        }
    };

}

#endif
