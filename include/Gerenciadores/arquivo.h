#ifndef GERENCIADOR_ARQUIVOS_H
#define GERENCIADOR_ARQUIVOS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Entidades/Personagens/tripulante.h"// Incluindo o cabeçalho completo do Tripulante

// Persistência de arquivos
#include <iostream>
#include <fstream>

#include <mutex>
#include <filesystem>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using namespace sf;

namespace Entidades::Personagens{
	class Tripulante;
}

namespace Gerenciadores {

    class Gerenciador_Arquivos  {

    private:
        //mutex mtx;
        //Entidades::Personagens::Tripulante* pJog1;
        //string nome = "Jogador1";
        //string local = "save.json";

    public:
    
        Gerenciador_Arquivos (){}

        ~Gerenciador_Arquivos(){}


        //virtual void salvar();
        //virtual void carregar();

        //void setJogador(Entidades::Personagens::Tripulante* jogador);
        //Entidades::Personagens::Tripulante* getJogador();

        // Serializa o objeto Jogador para JSON
        //json toJson() const;

        // Função para verificar se o arquivo existe
        //bool arquivoExiste();
    };

}

#endif
