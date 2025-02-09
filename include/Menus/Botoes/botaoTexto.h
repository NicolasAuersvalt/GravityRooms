#ifndef BOTAOTEXTO_H
#define BOTAOTEXTO_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Menus/Botoes/botao.h"
#include "Menus/Botoes/texto.h"

using namespace std;
using namespace sf;

namespace Menus {
namespace Botoes {

class BotaoTexto : public Botao, public Texto {
 private:
  bool selecionado;
  Color corSelecionado;

 public:
  BotaoTexto(const string info, const Vector2f pos,
             const Vector2f tam, const IDs::IDs ID,
             const Color corSelecionado);
  ~BotaoTexto();

  void atualizarPosicaoCaixa(const Vector2f pos);
  void setSelecionado(bool selecionado);
  bool getSelecionado() const;
  void desenhar(Gerenciador_Grafico &pGrafico);
};

}  // namespace Botoes
}  // namespace Menus

#endif
