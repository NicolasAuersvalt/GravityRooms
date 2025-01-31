#include <iostream>
#include <fstream>  // Para manipulação de arquivos
#include <string>
#include <vector>
#include "json.hpp"  // Incluir a biblioteca nlohmann/json.hpp

using namespace std;
using json = nlohmann::json;  // Alias para o tipo json da biblioteca

// Classe Abstrata GerenciadorArquivos
class GerenciadorArquivos {
public:
    virtual void abrirArquivo(const string& nome) = 0;
    virtual void fecharArquivo() = 0;
    virtual ~GerenciadorArquivos() {}
};

// Classe JsonHandler (herda de GerenciadorArquivos)
class JsonHandler : public GerenciadorArquivos {
public:
    void abrirArquivo(const string& nome) override {
        cout << "Abrindo arquivo JSON: " << nome << endl;
    }

    void fecharArquivo() override {
        cout << "Fechando arquivo JSON." << endl;
    }

    virtual void parseJson() {
        cout << "Parsing JSON data..." << endl;
    }

    // Método para salvar dados em formato JSON
    void salvarJson(const string& nomeArquivo, const json& dados) {
        ofstream out(nomeArquivo);  // Abre o arquivo para escrita
        if (out.is_open()) {
            out << dados.dump(4);  // Salva os dados formatados com indentação de 4 espaços
            cout << "Dados JSON salvos em " << nomeArquivo << endl;
        } else {
            cout << "Erro ao abrir o arquivo para salvar dados." << endl;
        }
        out.close();  // Fecha o arquivo
    }

    // Método para carregar dados JSON
    json carregarJson(const string& nomeArquivo) {
        ifstream in(nomeArquivo);  // Abre o arquivo para leitura
        json dados;
        if (in.is_open()) {
            in >> dados;  // Carrega os dados do arquivo JSON
        } else {
            cout << "Erro ao abrir o arquivo para carregar dados." << endl;
        }
        in.close();  // Fecha o arquivo
        return dados;
    }
};

// Classe Ranking (herda de GerenciadorArquivos)
class Ranking : public GerenciadorArquivos {
private:
    vector<string> dadosRanking;

public:
    void abrirArquivo(const string& nome) override {
        cout << "Abrindo arquivo de ranking: " << nome << endl;
        ifstream in(nome);  // Abre o arquivo para leitura
        string linha;
        while (getline(in, linha)) {
            dadosRanking.push_back(linha);  // Adiciona cada linha ao vetor de dados
        }
        in.close();  // Fecha o arquivo
    }

    void fecharArquivo() override {
        cout << "Fechando arquivo de ranking." << endl;
    }

    void exibirRanking() {
        cout << "Ranking dos jogadores:" << endl;
        for (const string& dado : dadosRanking) {
            cout << dado << endl;
        }
    }
};

int main() {
    // Criando objetos
    JsonHandler jsonHandler;
    Ranking ranking;

    // Dados fictícios do ranking
    vector<string> dados = {
        "Jogador1: 1000 pontos",
        "Jogador2: 950 pontos",
        "Jogador3: 900 pontos"
    };

    // Criando um objeto JSON com o ranking
    json dadosJson = {{"ranking", dados}};

    // Salvando dados JSON
    string arquivoJson = "ranking.json";
    jsonHandler.salvarJson(arquivoJson, dadosJson);

    // Carregando e exibindo o ranking
    json dadosCarregados = jsonHandler.carregarJson(arquivoJson);
    cout << "Dados carregados do arquivo JSON:" << endl;
    cout << dadosCarregados.dump(4) << endl;

    return 0;
}
