#include "Menus/ranking.h"

namespace Menus {

Ranking::Ranking(IDs::IDs id)
    : Menu(IDs::IDs::menu_colocacao,
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "COLOCACAO", 180) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

Ranking::Ranking(const IDs::IDs ID, std::string nome,
                 const unsigned int tamFonte)
<<<<<<< HEAD
    : Menu(IDs::IDs::menu_pausa, // ID CORRETO
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
=======
    : Menu(IDs::IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),
           nome, tamFonte) {
>>>>>>> psave
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

Ranking::~Ranking() {}

void Ranking::criarBotoes() {
  // Adiciona o botão "VOLTAR PARA O MENU" na posição especificada
  addBotao("VOLTAR PARA O MENU",
           sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 1250.0f),
           IDs::IDs::estado_menu_principal, sf::Color{0, 255, 0});

<<<<<<< HEAD
  carregarRanking();
=======
  carregarRanking();     // Carrega os dados do ranking
>>>>>>> psave
  inicializarIterator(); // Inicializa o iterador
}

void Ranking::executar() {}
void Ranking::carregarRanking() {
  // Abre o arquivo "rank.json" para leitura
  std::ifstream file("saves/rank.json");
  if (!file.is_open()) {
    std::cout << "Erro ao abrir rank.json" << std::endl;
    return;
  }

  nlohmann::json rankingData;
  file >> rankingData; // Lê o conteúdo do arquivo JSON
  file.close();

  // Define a posição inicial e o espaçamento para exibir os rankings
  float startY = tamJanela.y * 0.75f;
  float spacing = tamBotao.y * 1.5f;

  // Obtém o array de rankings do JSON e limita a exibição ao top 5
  const auto &rankingArray = rankingData["ranking"];
  int maxDisplay = std::min(5, static_cast<int>(rankingArray.size()));

  // Itera sobre as entradas do ranking e cria botões para exibição
  for (int i = 0; i < maxDisplay; i++) {
    const auto &entry = rankingArray[i];
    std::string playerName = entry["nome"];
    int score = entry["pontos"];

    // Formata o texto do ranking
    std::string rankText = std::to_string(i + 1) + ". " + playerName + " - " +
                           std::to_string(score);

    // Calcula a posição Y do botão
    float buttonY = startY + (spacing * (i + 1));

    // Adiciona um botão com o texto do ranking
    addBotao(rankText,
             sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, buttonY),
             IDs::IDs::menu_colocacao, sf::Color(0, 255, 0));
  }
}

void Ranking::exibirRanking() {}

} // namespace Menus