#ifndef ENTE_H
#define ENTE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Gerenciadores/gerenciador_grafico.h"
#include "IDs/IDs.h"

using namespace std;
using namespace sf;

using Gerenciadores::Gerenciador_Grafico;

class Gerenciador_Grafico;

class Ente {
private:
protected:
  const IDs::IDs ID;
  static Gerenciador_Grafico
      *pGG; // Ente utiliza Gerenciador Gráfico (Bidirecional)

  Texture *texture;
  Sprite sprite;

public:
  Ente(const IDs::IDs ID);
  ~Ente();

  void desenhar(); // Possui o endereço do gerenciador gráfico em protected,
                   // mas só UTILIZA o gerenciador

  void setSprite(string local, int posX, int posY);
  Texture *getTexture();
  Sprite &getSprite();
  static void setGerenciador(Gerenciadores::Gerenciador_Grafico *gg);

  FloatRect getHitBox() const { return sprite.getGlobalBounds(); }
  const IDs::IDs getID() const;
};

#endif