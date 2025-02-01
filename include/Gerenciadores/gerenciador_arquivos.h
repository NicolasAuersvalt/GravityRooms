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
#include "dados.h"

using json = nlohmann::json;
using namespace std;
using namespace sf;

namespace Entidades::Personagens {
    class Tripulante;
}

namespace Gerenciadores 
{

    class Gerenciador_Arquivos  
    {

    private:

        mutex mtx;

    public:
        Gerenciador_Arquivos () 
        {
        }

        ~Gerenciador_Arquivos() 
        {

        }

        virtual void salvarArquivo(Dados &dados, const json& j) { 
            lock_guard<mutex> lock(mtx);  // Garante acesso seguro ao arquivo

            ofstream arquivoEscrita(dados.getLocal());
            if (arquivoEscrita.is_open()) {
                arquivoEscrita << j.dump(4);
                cout << "Salvamento concluído com sucesso em " << dados.getLocal() << endl;
            } else {
                cerr << "Erro ao abrir o arquivo " << dados.getLocal() << " para escrita." << endl;
            }
        }
        

        // Função para verificar se o arquivo existe
        bool arquivoExiste(Dados dados) const 
        {
            return filesystem::exists(dados.getLocal());
        }
    };

}

#endif
