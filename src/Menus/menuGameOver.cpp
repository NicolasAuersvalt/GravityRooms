#include "Menus/menuGameOver.h"

namespace Menus {

MenuGameOver::MenuGameOver(IDs::IDs id)
    : Menu(IDs::IDs::menu_game_over,
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "COLOCACAO", 180),
      texto("", 30), nome(""), pontuacao(0) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuGameOver::MenuGameOver(const IDs::IDs ID, std::string nome,
                           const unsigned int tamFonte)
    : Menu(IDs::IDs::menu_game_over,
           sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte),
      texto("", 30), pontuacao(0) {
  titulo.setPos(
      sf::Vector2f(tamJanela.x / 2.0f - titulo.getTam().x / 2.0f, 25.0f));
  titulo.setCorTexto(sf::Color{0, 200, 0});
}

MenuGameOver::~MenuGameOver() {}
void MenuGameOver::salvarColocacao(int pontos) {
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
  for (auto &entry : rankingData["ranking"]) {
    if (entry["nome"] == nome) {
      // Atualizar a pontuação se o jogador já existir
      entry["pontos"] = pontos;
      jogadorExiste = true;
      break;
    }
  }

  // Se o jogador não existir, adicionar uma nova entrada
  if (!jogadorExiste) {
    nlohmann::json novoJogador = {{"nome", nome}, {"pontos", pontos}};
    rankingData["ranking"].push_back(novoJogador);
  }

  // Ordenar o ranking por pontuação (do maior para o menor)
  std::sort(rankingData["ranking"].begin(), rankingData["ranking"].end(),
            [](const nlohmann::json &a, const nlohmann::json &b) {
              return a["pontos"] > b["pontos"];
            });

  // Salvar o arquivo JSON atualizado
  std::ofstream outFile("saves/rank.json");
  if (!outFile.is_open()) {
    std::cout << "Erro ao abrir rank.json para escrita" << std::endl;
    return;
  }

  outFile << rankingData.dump(4); // Salvar com indentação de 4 espaços
  outFile.close();
}

void MenuGameOver::executar() {}

void MenuGameOver::carregarMenuGameOver() {
  std::ifstream file("saves/rank.json");
  if (!file.is_open()) {
    std::cout << "Erro ao abrir rank.json" << std::endl;
    return;
  }

  nlohmann::json rankingData;
  file >> rankingData;
  file.close();

  float startY = tamJanela.y * 0.3f;
  float spacing = tamBotao.y * 1.5f;

  const auto &rankingArray = rankingData["ranking"];
  int position = 1;

  for (const auto &entry : rankingArray) {
    std::string playerName = entry["nome"];
    int score = entry["pontos"];

    std::string rankText = std::to_string(position) + ". " + playerName +
                           " - " + std::to_string(score);

    float buttonY = startY + (spacing * position);
    addBotao(rankText, sf::Vector2f(0.f, buttonY), IDs::IDs::menu_game_over,
             sf::Color(0, 255, 0));

    position++;
  }
}
void MenuGameOver::addCaracter(char caracter) {
  if (nome.length() < 10) {
    if ((caracter >= 'a' && caracter <= 'z') ||
        (caracter >= 'A' && caracter <= 'Z') ||
        (caracter >= '0' && caracter <= '9')) {
      nome += caracter;

      for (auto it = listaBotaoTexto.begin(); it != listaBotaoTexto.end();
           ++it) {
        if ((*it)->getID() == IDs::IDs::botao_nome) {
          (*it)->setText(nome + "_");
          break;
        }
      }
    }
  }
}

void MenuGameOver::exibirMenuGameOver() {
  for (auto &texto : rankingTexts) {
  }
}

void MenuGameOver::criarBotoes() {
  addBotao("DIGITE SEU NOME:",
           sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 600.0f),
           IDs::IDs::menu_game_over, sf::Color(0, 255, 0));

  addBotao("_", sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 800.0f),
           IDs::IDs::botao_nome, sf::Color(0, 255, 0));
  addBotao("VOLTAR PARA O MENU",
           sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 1250.0f),
           IDs::IDs::estado_menu_principal, sf::Color{0, 255, 0});
  inicializarIterator();
}

} // namespace Menus