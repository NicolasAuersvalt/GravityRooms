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
        Gerenciador_Arquivos () : x(0), y(0) 
        {

        }

        ~Gerenciador_Arquivos() 
        {

        }

        virtual void salvarArquivo(const string& local, const json& j) // OK
        { 

            ofstream arquivo(local);

            if (arquivo.is_open()) 
            {
                // Escrever o conteúdo do JSON no arquivo
                arquivo << j.dump(4);  // O '4' especifica a indentação (4 espaços)
                cout << "Salvamento concluído com sucesso em " << local << endl;

            }
            else 
            {
                cerr << "Erro ao abrir o arquivo " << local << " para escrita." << endl;

            }
        }

        // Método para carregar os dados do arquivo
        virtual void carregar(const string& local) // OK
        {
            // Verifica se o arquivo existe
            cout << "Caminho do arquivo: " << local << endl;

            if (!arquivoExiste(local)) 
            {
                cerr << "Erro: O arquivo não existe." << endl;
                return;
            }

            ifstream arquivoLeitura(local);

            // Verifica se o arquivo foi aberto com sucesso
            if (arquivoLeitura.is_open()) 
            {
                json dadosCarregados;
                try 
                {
                    // Tenta carregar os dados JSON do arquivo
                    arquivoLeitura >> dadosCarregados;

                    // Imprime o conteúdo lido para verificação
                    cout << "Conteúdo lido do arquivo: " << dadosCarregados.dump(4) << endl;

                    // Carrega as posições
                    x = dadosCarregados["x"];
                    y = dadosCarregados["y"];

                } 
                catch (const json::parse_error& e) 
                {
                    // Captura qualquer erro de parsing do JSON
                    cerr << "Erro ao parsear o arquivo JSON: " << e.what() << endl;
                }
            } 
            else 
            {
                cerr << "Erro ao abrir o arquivo " << local << " para leitura." << endl;
            }
        }
        

        // Função para verificar se o arquivo existe
        bool arquivoExiste(const string& local) const 
        {
            return filesystem::exists(local);
        }
    };

}

#endif
