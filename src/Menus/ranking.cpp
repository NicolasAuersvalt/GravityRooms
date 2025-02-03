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
    : Menu(IDs::IDs::menu_pausa, // ID CORRETO
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

Ranking::~Ranking() {}

void Ranking::criarBotoes() {
  // Centralizar horizontalmente (igual ao menu principal)
  // float bottomY = tamJanela.y * 0.85f;
  // Botões em maiúsculas e centralizados
  addBotao("VOLTAR PARA O MENU",
           sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 1250.0f),
           IDs::IDs::estado_menu_principal, sf::Color{0, 255, 0});

  carregarRanking();
  inicializarIterator(); // Inicializa o iterador
}

void Ranking::executar() {}
void Ranking::carregarRanking() {
  std::ifstream file("saves/rank.json");
  if (!file.is_open()) {
    std::cout << "Erro ao abrir rank.json" << std::endl;
    return;
  }

  nlohmann::json rankingData;
  file >> rankingData;
  file.close();

  // Display settings
  float startY = tamJanela.y * 0.75f;
  float spacing = tamBotao.y * 1.5f;

  // Display top 5 only
  const auto &rankingArray = rankingData["ranking"];
  int maxDisplay = std::min(5, static_cast<int>(rankingArray.size()));

  for (int i = 0; i < maxDisplay; i++) {
    const auto &entry = rankingArray[i];
    std::string playerName = entry["nome"];
    int score = entry["pontos"];

    std::string rankText = std::to_string(i + 1) + ". " + playerName + " - " +
                           std::to_string(score);

    float buttonY = startY + (spacing * (i + 1));
    addBotao(rankText,
             sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, buttonY),
             IDs::IDs::menu_colocacao, sf::Color(0, 255, 0));
  }
}

void Ranking::exibirRanking() {
  for (auto &texto : rankingTexts) {
    // texto.desenhar(*GG);  // Assuming GG is a pointer to Gerenciador_Grafico
  }
}

} // namespace Menus