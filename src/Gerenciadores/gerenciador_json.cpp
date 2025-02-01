#include "Gerenciadores/gerenciador_json.h"

namespace Gerenciadores 
{

    // Construtor
    Gerenciador_Json::Gerenciador_Json() :
     x(0), y(0), nome(""), pontos(0) 
    {

    }

    // Destruidor
    Gerenciador_Json::~Gerenciador_Json() 
    {


    }

    // Método para converter os dados para o formato JSON
    json Gerenciador_Json::toJson(const int x, const int y, const string& nome) 
    {
        json j;
        j["nome"] = nome;
        j["x"] = x;
        j["y"] = y;
        cout << nome << endl;
        cout << x << endl;
        cout << y << endl;
        return j;
    }

    // Método para carregar os dados do arquivo JSON
    void Gerenciador_Json::carregarJson(const std::string& local, bool carregado) 
    {
        std::string conteudo;

        if (carregado) 
        {

            try 
            {

                json dadosCarregados = json::parse(conteudo);
                nome = dadosCarregados["nome"];
                x = dadosCarregados["x"];
                y = dadosCarregados["y"];
                std::cout << "Dados carregados: nome = " << nome 
                          << ", x = " << x 
                          << ", y = " << y << std::endl;
                
            } 
            catch (const json::parse_error& e) {
                std::cerr << "Erro ao parsear o arquivo JSON: " << e.what() << std::endl;
             
            }

        }
     
    }

    // Métodos de acesso
    string Gerenciador_Json::getNome() const 
    {
        return nome;
    }

    int Gerenciador_Json::getPontos() const 
    {
        return pontos;
    }

    Vector2f Gerenciador_Json::getPos() const 
    {
        return Vector2f(x, y);
    }

    // Método para gerar um objeto JSON
    json Gerenciador_Json::getJson(const std::string& local, const int x, const int y, const string& nome) 
    {
        json j = toJson(x, y, nome);
        return j;
    }

}
