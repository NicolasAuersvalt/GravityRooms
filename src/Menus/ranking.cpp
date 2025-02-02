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
    : Menu(IDs::IDs::menu_pausa,  // ID CORRETO
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

Ranking::~Ranking() {}

void Ranking::criarBotoes() {
  // Centralizar horizontalmente (igual ao menu principal)
  float centerX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
  float startY = tamJanela.y * 0.4f;  // Posição Y inicial
  float spacing = tamBotao.y * 1.5f;

  // Botões em maiúsculas e centralizados
  addBotao("VOLTAR PARA O MENU", sf::Vector2f(centerX, startY),
           IDs::IDs::estado_menu_principal, sf::Color{0, 255, 0});

  carregarRanking();
  exibirRanking();
  inicializarIterator();  // Inicializa o iterador
}

void Ranking::executar() {
  exibirRanking();
  // conteúdo do efeito Parallax
}
void Ranking::carregarRanking() {
  std::ifstream file("saves/rank.json");
  if (!file.is_open()) {
    std::cout << "Erro ao abrir rank.json" << std::endl;
    return;
  }

  nlohmann::json rankingData;
  file >> rankingData;
  file.close();

  rankingTexts.clear();
  float startY = 200.0f;
  float spacing = 50.0f;

  // Access the "ranking" array
  const auto& rankingArray = rankingData["ranking"];

  int position = 1;
  for (const auto& entry : rankingArray) {
    std::string playerName = entry["nome"];
    int score = entry["pontos"];

    std::string rankText = std::to_string(position) + ". " + playerName +
                           " - " + std::to_string(score);
    Botoes::Texto texto(rankText, 30);

    float centerX = tamJanela.x / 2.0f - texto.getTam().x / 2.0f;
    texto.setPos(sf::Vector2f(centerX, startY + spacing * position));
    texto.setCorTexto(sf::Color::White);
    std::cout << "Player Name: " << playerName << std::endl;
    rankingTexts.push_back(texto);
    position++;
  }
}

void Ranking::exibirRanking() {
  for (auto& texto : rankingTexts) {
    // texto.desenhar(*GG);  // Assuming GG is a pointer to Gerenciador_Grafico
  }
}

}  // namespace Menus