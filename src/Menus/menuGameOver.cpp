#include "Menus/menuGameOver.h"

namespace Menus {

MenuGameOver::MenuGameOver(IDs::IDs id)

    : Menu(IDs::IDs::menu_game_over,
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "COLOCACAO", 180) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuGameOver::MenuGameOver(const IDs::IDs ID, std::string nome,
                           const unsigned int tamFonte)
    : Menu(IDs::IDs::menu_game_over,  // ID CORRETO
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuGameOver::~MenuGameOver() {}
void MenuGameOver::salvarColocacao() {
  // Abrir o arquivo rank.json
  std::ifstream file("saves/rank.json");
  if (!file.is_open()) {
    std::cout << "Erro ao abrir rank.json para leitura" << std::endl;
    return;
  }

  // Ler o conteúdo do arquivo JSON
  nlohmann::json rankingData;
  file >> rankingData;
  file.close();

  // Verificar se o jogador já existe no ranking
  bool jogadorExiste = false;
  for (auto& entry : rankingData["ranking"]) {
    if (entry["nome"] == nome) {
      // Atualizar a pontuação se o jogador já existir
      entry["pontos"] = pontuacao;
      jogadorExiste = true;
      break;
    }
  }

  // Se o jogador não existir, adicionar uma nova entrada
  if (!jogadorExiste) {
    nlohmann::json novoJogador = {{"nome", nome}, {"pontos", pontuacao}};
    rankingData["ranking"].push_back(novoJogador);
  }

  // Ordenar o ranking por pontuação (do maior para o menor)
  std::sort(rankingData["ranking"].begin(), rankingData["ranking"].end(),
            [](const nlohmann::json& a, const nlohmann::json& b) {
              return a["pontos"] > b["pontos"];
            });

  // Salvar o arquivo JSON atualizado
  std::ofstream outFile("saves/rank.json");
  if (!outFile.is_open()) {
    std::cout << "Erro ao abrir rank.json para escrita" << std::endl;
    return;
  }

  outFile << rankingData.dump(4);  // Salvar com indentação de 4 espaços
  outFile.close();
}

void MenuGameOver::executar() {
  // conteúdo do efeito Parallax
}

void MenuGameOver::carregarMenuGameOver() {
  std::ifstream file("saves/rank.json");
  if (!file.is_open()) {
    std::cout << "Erro ao abrir rank.json" << std::endl;
    return;
  }

  nlohmann::json rankingData;
  file >> rankingData;
  file.close();

  // Starting position and spacing
  float startY = tamJanela.y * 0.3f;  // Start 30% from top
  float spacing = tamBotao.y * 1.5f;  // 1.5x button height spacing

  // Access the "ranking" array
  const auto& rankingArray = rankingData["ranking"];
  int position = 1;

  for (const auto& entry : rankingArray) {
    std::string playerName = entry["nome"];
    int score = entry["pontos"];

    // Format ranking text
    std::string rankText = std::to_string(position) + ". " + playerName +
                           " - " + std::to_string(score);

    // Create centered button
    float buttonY = startY + (spacing * position);
    addBotao(rankText, sf::Vector2f(0.f, buttonY),
             IDs::IDs::menu_game_over,  // Use appropriate ID
             sf::Color(0, 255, 0));     // Green color for consistency

    position++;
  }
}
void MenuGameOver::addCaracter(char caracter) {
  if ((caracter >= 'a' && caracter <= 'z') ||
      (caracter >= 'A' && caracter <= 'Z') ||
      (caracter >= '0' && caracter <= '9')) {
    // Limit name length to 10 characters
    if (nome.length() < 10) {
      nome += caracter;

      // Update display text
      Botoes::Texto novoTexto(nome, 30);
      novoTexto.setCorTexto(sf::Color::White);

      // Center text position
      float xPos = tamJanela.x / 2.0f - novoTexto.getTam().x / 2.0f;
      float yPos = tamJanela.y * 0.4f;  // 40% from top
      novoTexto.setPos(sf::Vector2f(xPos, yPos));

      rankingTexts.clear();
      rankingTexts.push_back(novoTexto);
    }
  }
}

void MenuGameOver::removerCaracter() {
  if (!nome.empty()) {
    // Remove last character
    nome = nome.substr(0, nome.length() - 1);

    // Update display text
    if (!nome.empty()) {
      Botoes::Texto novoTexto(nome, 30);
      novoTexto.setCorTexto(sf::Color::White);

      // Center text position
      float xPos = tamJanela.x / 2.0f - novoTexto.getTam().x / 2.0f;
      float yPos = tamJanela.y * 0.4f;
      novoTexto.setPos(sf::Vector2f(xPos, yPos));

      rankingTexts.clear();
      rankingTexts.push_back(novoTexto);
    }
  }
}
void MenuGameOver::exibirMenuGameOver() {
  for (auto& texto : rankingTexts) {
    // texto.desenhar(*GG);  // Assuming GG is a pointer to Gerenciador_Grafico
  }
}

void MenuGameOver::criarBotoes() {
  addBotao("VOLTAR PARA O MENU",
           sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 1250.0f),
           IDs::IDs::estado_menu_principal, sf::Color{0, 255, 0});
}
}  // namespace Menus