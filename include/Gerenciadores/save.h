#ifndef SAVE_H
#define SAVE_H

#include "Entidades/Personagens/tripulante.h"
#include "Gerenciadores/gerenciador_arquivos.h"
#include "Gerenciadores/gerenciador_json.h"

#include <iostream>
#include <fstream>

#include <mutex>
#include <filesystem>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using namespace sf;

using Gerenciadores::Gerenciador_Arquivos;
using Gerenciadores::Gerenciador_Json;

namespace Entidades::Personagens{
	class Tripulante;
}

class Save : public Gerenciador_Arquivos, public Gerenciador_Json
{

    private:

        Entidades::Personagens::Tripulante* pJog1;
        Dados dados;

    public:
    
        Save();
        ~Save();

        void setJogador(Entidades::Personagens::Tripulante* jogador);
        Entidades::Personagens::Tripulante* getJogador();
        
        void salvar();
        void gravarDados();
        void carregar();

};


#endif