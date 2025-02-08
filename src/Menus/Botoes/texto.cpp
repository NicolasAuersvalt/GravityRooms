
#include "Menus/Botoes/texto.h"

#include <iostream>

namespace Menus {

namespace Botoes {
Texto::Texto(const std::string info, const unsigned int tamFonte)
    : texto(),
      info(info),
      corTexto(sf::Color::White),
      corBorda(sf::Color::Black),
      tamFonte(tamFonte) {
  if (!fonte.loadFromFile("assets/Fontes/Gameplay.ttf")) {
    std::cout << "Error loading font!" << std::endl;

    if (!fonte.loadFromFile("assets/Fontes/Gameplay.ttf")) {
      std::cerr << "Error loading system font!" << std::endl;
      exit(1);
    }
  }

  inicializa();
}

Texto::~Texto() {}

void Texto::inicializa() {
  texto.setString(info);
  texto.setCharacterSize(tamFonte);
  texto.setFont(fonte);
  texto.setOutlineThickness(2.5f);
  texto.setOutlineColor(corBorda);
  texto.setFillColor(corTexto);

  // Centraliza a origem do texto
  sf::FloatRect textBounds = texto.getLocalBounds();
  texto.setOrigin(
      textBounds.left + textBounds.width / 2.0f,  // Origem X no centro
      textBounds.top + textBounds.height / 2.0f   // Origem Y no centro
  );

  // Atualiza o tamanho do texto
  tamTexto = sf::Vector2f(textBounds.width, textBounds.height);
}

void Texto::setCorTexto(const sf::Color corTexto) {
  this->corTexto = corTexto;
  texto.setFillColor(corTexto);
}

const sf::Text Texto::getTexto() const { return texto; }

void Texto::setPos(const sf::Vector2f pos) {
  this->posTexto = pos;
  texto.setPosition(posTexto);
}

const sf::Vector2f Texto::getPos() const { return posTexto; }

const sf::Vector2f Texto::getTam() const {
  sf::FloatRect bounds = texto.getGlobalBounds();
  return sf::Vector2f(bounds.width, bounds.height);
}

void Texto::setTamanhoBorda(const float tamBorda) {
  texto.setOutlineThickness(tamBorda);
  tamTexto = sf::Vector2f(texto.getGlobalBounds().width,
                          texto.getGlobalBounds().height);
}

void Texto::setEspacamento(const float tamEspaco) {
  texto.setLetterSpacing(tamEspaco);
  tamTexto = sf::Vector2f(texto.getGlobalBounds().width,
                          texto.getGlobalBounds().height);
}

void Texto::setString(std::string nome) {
  texto.setString(nome);
  tamTexto = sf::Vector2f(texto.getGlobalBounds().width,
                          texto.getGlobalBounds().height);
}

const std::string Texto::getString() const { return texto.getString(); }

void Texto::setTamFonte(const unsigned int tamFonte) {
  texto.setCharacterSize(tamFonte);
  tamTexto = sf::Vector2f(texto.getGlobalBounds().width,
                          texto.getGlobalBounds().height);
}
}  // namespace Botoes

}  // namespace Menus
