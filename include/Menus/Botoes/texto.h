
#ifndef TEXTO_H
#define TEXTO_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace Menus {

namespace Botoes {

class Texto {
private:
  string info;

protected:
  Text texto;
  Vector2f tamTexto;
  Vector2f posTexto;
  unsigned int tamFonte;
  Color corTexto;
  Color corBorda;
  Font fonte;
  void inicializa();

public:
  Texto(const string info, const unsigned int tamFonte = 50);
  virtual ~Texto();
  const Text getTexto() const;
  void setPos(const Vector2f pos);
  const Vector2f getPos() const;
  const Vector2f getTam() const;
  void setCorTexto(const Color corTexto);
  void setTamanhoBorda(const float tamBorda);
  void setEspacamento(const float tamEspaco);
  void setString(string nome);
  const string getString() const;
  void setTamFonte(const unsigned int tamFonte);
};

} // namespace Botoes

} // namespace Menus
#endif
