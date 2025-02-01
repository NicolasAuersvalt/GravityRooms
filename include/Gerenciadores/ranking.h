#ifndef RANKING_H
#define RANKING_H

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

class Ranking : public Gerenciador_Arquivos, public Gerenciador_Json{

    private:
        Entidades::Personagens::Tripulante* pJog1;
        Dados dados;

    public:
        Ranking();
        ~Ranking();

        void setJogador(Entidades::Personagens::Tripulante* jogador);
        Entidades::Personagens::Tripulante* getJogador();
        
        void salvar();
        void gravarDados();
        void carregar();

        void salvarArquivo(const Dados& dados, const json& j);
        void carregarJson(Dados& dados) override;
};


#endif