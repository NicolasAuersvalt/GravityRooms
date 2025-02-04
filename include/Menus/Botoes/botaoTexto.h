#ifndef BOTAOTEXTO_H
#define BOTAOTEXTO_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Menus/Botoes/botao.h"

namespace Menus {
namespace Botoes {

class BotaoTexto : public Botao {
 private:
 protected:
  bool selecionado;
  sf::Color corSelecionado;
  sf::Text texto;
  sf::Font font;
  const sf::Vector2f getTamTexto() const;

 public:
  BotaoTexto(const std::string info, const sf::Vector2f pos,
             const sf::Vector2f tam, const IDs::IDs ID,
             const sf::Color corSelecionado);
  ~BotaoTexto();

  void atualizarAnimacao();
  void atualizarPosicaoCaixa(const sf::Vector2f pos);
  void setSelecionado(bool selecionado);
  const bool getSelecionado() const;
  void desenhar(Gerenciador_Grafico &pGrafico);
  void setText(const std::string &text);
};

}  // namespace Botoes
}  // namespace Menus

#endif
