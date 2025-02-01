#include"Gerenciadores/ranking.h"

Ranking::Ranking():
dados()
{
    dados.setLocal("saves/rank.json");
}

Ranking::~Ranking(){
    
}

void Ranking::setJogador(Entidades::Personagens::Tripulante* jogador) {
        if (jogador) {
            pJog1 = jogador;
        }
    }

Entidades::Personagens::Tripulante* Ranking ::getJogador() {
    return pJog1;
}

void Ranking::gravarDados(){

    dados.setNome("Jogador1");
    dados.setPos(make_pair(pJog1->getPosicao().x, pJog1->getPosicao().y));
    dados.setLocal("saves/rank.json");
}

void Ranking::salvar()
{
    // Salva os dados do Jogador
    gravarDados();

    // Cria um arquivo de texto Json
    json j = getJson(dados);

    // Envia para o salvamento
    salvarArquivo(dados, j);

}

void Ranking::carregar()
{
    cout << "Ranking::carregar()" << endl;
    bool carregado = arquivoExiste(dados);
    if(carregado){

        carregarJson(dados);

    }
    pJog1->setPosicao(dados.getPos().first, dados.getPos().first);

}

 void Ranking::carregarJson(Dados& dados) {
        ifstream arquivo("ranking.json");
        if (arquivo.is_open()) {
            json j;
            arquivo >> j;  // Lê o arquivo JSON

            // Atualiza os dados
            dados.setNome(j["nome"]);
            dados.setPontos(j["pontos"]);
            dados.setPos(make_pair(j["x"], j["y"]));

            cout << "Dados carregados: " << dados.getNome() << ", Pontos: " << dados.getPontos() << ", Posição: (" << dados.getPos().first << ", " << dados.getPos().second << ")" << endl;

            arquivo.close();
        } else {
            cerr << "Erro ao abrir o arquivo para leitura!" << endl;
        }
    }

void Ranking::salvarArquivo(const Dados& dados, const json& j) {
    ofstream arquivo("ranking.json");
    if (arquivo.is_open()) {
        arquivo << j.dump(4);
        cout << "Dados salvos no arquivo." << endl;
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para gravação!" << endl;
    }
}
