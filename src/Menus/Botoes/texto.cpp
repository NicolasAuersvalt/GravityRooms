
#include "Menus/Botoes/texto.h"

#include <iostream>

namespace Menus {

namespace Botoes {
Texto::Texto(const string info, const unsigned int tamFonte)
    : texto(), info(info), corTexto(Color::White), corBorda(Color::Black),
      tamFonte(tamFonte) {
  if (!fonte.loadFromFile("assets/Fontes/Gameplay.ttf")) {
    cout << "Error loading font!" << endl;

    if (!fonte.loadFromFile("assets/Fontes/Gameplay.ttf")) {
      cerr << "Error loading system font!" << endl;
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
  FloatRect textBounds = texto.getLocalBounds();
  texto.setOrigin(
      textBounds.left + textBounds.width / 2.0f, // Origem X no centro
      textBounds.top + textBounds.height / 2.0f  // Origem Y no centro
  );

  // Atualiza o tamanho do texto
  tamTexto = Vector2f(textBounds.width, textBounds.height);
}

void Texto::setCorTexto(const Color corTexto) {
  this->corTexto = corTexto;
  texto.setFillColor(corTexto);
}

const Text Texto::getTexto() const { return texto; }

void Texto::setPos(const Vector2f pos) {
  this->posTexto = pos;
  texto.setPosition(posTexto);
}

const Vector2f Texto::getPos() const { return posTexto; }

const Vector2f Texto::getTam() const {
  FloatRect bounds = texto.getGlobalBounds();
  return Vector2f(bounds.width, bounds.height);
}

void Texto::setTamanhoBorda(const float tamBorda) {
  texto.setOutlineThickness(tamBorda);
  tamTexto =
      Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Texto::setEspacamento(const float tamEspaco) {
  texto.setLetterSpacing(tamEspaco);
  tamTexto =
      Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Texto::setString(string nome) {
  texto.setString(nome);
  tamTexto =
      Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

const string Texto::getString() const { return texto.getString(); }

void Texto::setTamFonte(const unsigned int tamFonte) {
  texto.setCharacterSize(tamFonte);
  tamTexto =
      Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}
} // namespace Botoes

} // namespace Menus
