#ifndef BOTAOTEXTO_H
#define BOTAOTEXTO_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Menus/Botoes/botao.h"
#include "Menus/Botoes/texto.h"

namespace Menus {
namespace Botoes {

class BotaoTexto : public Botao, public Texto {
 private:
  bool selecionado;
  sf::Color corSelecionado;

 public:
  BotaoTexto(const std::string info, const sf::Vector2f pos,
             const sf::Vector2f tam, const IDs::IDs ID,
             const sf::Color corSelecionado);
  ~BotaoTexto();

  void atualizarPosicaoCaixa(const sf::Vector2f pos);
  void setSelecionado(bool selecionado);
  bool getSelecionado() const;
  void desenhar(Gerenciador_Grafico &pGrafico);
};

}  // namespace Botoes
}  // namespace Menus

#endif
