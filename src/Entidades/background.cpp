#include "Entidades/background.h"

namespace Entidades {

Background::Background(const Vector2f pos, const Vector2f tam,
                       const IDs::IDs ID)
    : Entidade(pos, tam, ID) {
  if ((ID == IDs::IDs::fase_nave)) {
    setSprite("assets/nave.png", 50.0f, 50.0f);
  } else if (ID == IDs::IDs::fase_laboratorio) {
    setSprite("assets/lab.png", 50.0f, 50.0f);
  }

  setTamanho(sf::Vector2f(1280.0f, 920.0f));
  setPosicao(50.0f, 50.0f);
  sprite.setPosition(0.f, 0.f);
}

Background::~Background() {}

void Background::mover() {}

void Background::colisao(Entidade *outraEntidade, sf::Vector2f ds) {}

void Background::atualizarPosicao() {}

void Background::salvar(json &arquivo) {
  // Salva o ID do background no arquivo JSON, convertendo-o para inteiro
  arquivo["id"] = static_cast<int>(getID());

  // Salva a posição X do background no arquivo JSON
  arquivo["posicao"]["x"] = getPosicao().x;

  // Salva a posição Y do background no arquivo JSON
  arquivo["posicao"]["y"] = getPosicao().y;

  // Salva o tipo do background no arquivo JSON
  arquivo["tipo"] = getTipo();
}

std::string Background::getTipo() const { return "background"; };

void Background::carregar(json &arquivo) {}

REGISTRAR_CLASSE(Background, "background")

} // namespace Entidades