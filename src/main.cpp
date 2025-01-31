//#include "jogo.h"
#include "gravity_rooms.h"
#include <iostream>
#include <fstream>
#include <iostream>


int main() {

	Gravity_Rooms gravity_rooms;

	/*
    // Criando dados em JSON com valores de ponto flutuante
    json dados;
    dados["nome"] = "Jogador1";
    dados["x"] = 1145.0;  // Valor de ponto flutuante
    dados["y"] = 650.0;   // Valor de ponto flutuante

    // Criação do subdiretório "saves", se não existir
    filesystem::create_directory("saves");

    // Salvar os dados em um arquivo dentro do subdiretório "saves"
    ofstream arquivo("saves/save.json");
    if (arquivo.is_open()) {
        arquivo << dados.dump(4);  // Escreve os dados com indentação de 4 espaços
        arquivo.close();  // Fecha o arquivo após salvar
        cout << "Salvamento concluído com sucesso em saves/save.json" << endl;
    } else {
        cerr << "Erro ao abrir o arquivo saves/save.json para escrita." << endl;
        return 1;  // Retorna erro se não conseguir abrir o arquivo
    }



    // Carregar os dados do arquivo
    ifstream arquivoLeitura("saves/save.json");

    if (arquivoLeitura.is_open()) {
	
        json dadosCarregados;
        arquivoLeitura >> dadosCarregados;  // Lê os dados do arquivo
        arquivoLeitura.close();  // Fecha o arquivo após ler os dados

        // Exibe os dados carregados
        cout << "Dados carregados com sucesso de saves/save.json:" << endl;
        cout << "Nome: " << dadosCarregados["nome"] << endl;
        cout << "Posição: (" 
             << dadosCarregados["x"].get<float>() << ", " 
             << dadosCarregados["y"].get<float>() << ")" << endl;
    } else {
        cerr << "Erro ao abrir o arquivo saves/save.json para leitura." << endl;
        return 1;  // Retorna erro se não conseguir abrir o arquivo
    }
	*/


    return 0;
}