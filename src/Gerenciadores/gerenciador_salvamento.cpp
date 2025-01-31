#include "Gerenciadores/gerenciador_salvamento.h"

namespace Gerenciadores {

    // Construtor
    Gerenciador_Salvamento::Gerenciador_Salvamento() : pJog1(nullptr) {}

    // Destrutor
    Gerenciador_Salvamento::~Gerenciador_Salvamento() {}

    void Gerenciador_Salvamento::salvar(){
        if (pJog1) {
            json dados = toJson();
            ofstream arquivo("save.json");
            if (arquivo.is_open()) {
                arquivo << dados.dump(4);
                arquivo.close();
                cout << "Salvamento concluído com sucesso em saves/save.json" << endl;
            } else {
                cerr << "Erro ao abrir o arquivo saves/save.json para escrita." << endl;
            }
        } else {
            cerr << "Erro: pJog1 é nullptr. Nenhum dado foi salvo." << endl;
        }
    }

    void Gerenciador_Salvamento::carregar() {
        
        ifstream arquivo("save.json");
        if (arquivo.is_open()) {
            json dados;
            arquivo >> dados;
            arquivo.close();
            
            if (pJog1) {
                pJog1->setPosicao(static_cast<int>(dados["x"]), static_cast<int>(dados["y"]));
                cout << "Carregamento concluído com sucesso. Posição restaurada para: (" 
                          << dados["x"] << ", " << dados["y"] << ")" << endl;
            } 
            else
             {
                cerr << "Erro: pJog1 é nullptr. Não foi possível carregar os dados." << endl;
            }
        } 
        else 
        {
            cerr << "Erro ao abrir o arquivo saves/save.json para leitura." << endl;
        }
        

    }

    // Método para definir o jogador
    void Gerenciador_Salvamento::setJogador(Entidades::Personagens::Tripulante* jogador) {
        if (jogador) {
            pJog1 = jogador;
        }
    }

    // Método para obter o jogador
    Entidades::Personagens::Tripulante* Gerenciador_Salvamento::getJogador() {
        return pJog1;
    }

    // Método para serializar o objeto Jogador para JSON
    json Gerenciador_Salvamento::toJson() const {
        return {
            {"nome", nome},
            {"x", pJog1->getPosicao().x},
            {"y", pJog1->getPosicao().y}
        };
    }

    // Função para verificar se o arquivo existe
    bool Gerenciador_Salvamento::arquivoExiste(const string& caminho) {
        return filesystem::exists(caminho);
    }

}
