#include "Menus/ranking.h"

namespace Menus {

Ranking::Ranking(IDs::IDs id)
    : Menu(IDs::IDs::menu_colocacao, Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),
           "COLOCACAO", 180) {
  titulo.setPos(Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(Color{0, 200, 0});
}

Ranking::Ranking(const IDs::IDs ID, string nome, const unsigned int tamFonte)
    : Menu(IDs::IDs::menu_pausa, Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),
           nome, tamFonte) {
  titulo.setPos(Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(Color{0, 200, 0});
}

Ranking::~Ranking() {}

void Ranking::criarBotoes() {
  // Adiciona o botão "VOLTAR PARA O MENU" na posição especificada
  addBotao("VOLTAR PARA O MENU",
           Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 1250.0f),
           IDs::IDs::botao_menu, Color{0, 255, 0});

  carregarRanking();      // Carrega os dados do ranking
  inicializarIterator();  // Inicializa o iterador
}

void Ranking::executar() {}
void Ranking::carregarRanking() {
  // Abre o arquivo "rank.json" para leitura
  ifstream file("saves/rank.json");
  if (!file.is_open()) {
    cout << "Erro ao abrir rank.json" << endl;
    return;
  }

  nlohmann::json rankingData;
  file >> rankingData;  // Lê o conteúdo do arquivo JSON
  file.close();

  // Define a posição inicial e o espaçamento para exibir os rankings
  float startY = tamJanela.y * 0.75f;
  float spacing = tamBotao.y * 1.5f;

  // Obtém o array de rankings do JSON e limita a exibição ao top 5
  const auto &rankingArray = rankingData["ranking"];
  int maxDisplay = min(5, static_cast<int>(rankingArray.size()));

  // Itera sobre as entradas do ranking e cria botões para exibição
  for (int i = 0; i < maxDisplay; i++) {
    const auto &entry = rankingArray[i];
    string playerName = entry["nome"];
    int score = entry["pontos"];

    // Formata o texto do ranking
    string rankText =
        to_string(i + 1) + ". " + playerName + " - " + to_string(score);

    // Calcula a posição Y do botão
    float buttonY = startY + (spacing * (i + 1));

    // Adiciona um botão com o texto do ranking
    addBotao(rankText,
             Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, buttonY),
             IDs::IDs::menu_colocacao, Color(0, 255, 0));
  }
}

void Ranking::exibirRanking() {}

}  // namespace Menus