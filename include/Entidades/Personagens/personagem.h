#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>

#include "Entidades/entidade.h"
#include "json.hpp"

using namespace sf;
using namespace std;

namespace Entidades::Personagens {

class Personagem : public Entidade {

 protected:

  // ===/===/===/===/ Obrigatório ===/===/===/===/
  
  Vector2f vel;

  int pontosVida = 100;
  bool noChao;

  // ===/===/===/===/ Outros  ===/===/===/===/

  bool vivo;

 public:
  // ===/===/===/===/ Obrigatório ===/===/===/===/

  // Personagem(pair<int, int> p, pair<int, int> d); //verificar
  Personagem(const Vector2f pos, const Vector2f tam);
  ~Personagem();

    // Métodos para manipulação de vida
    void setVida(int life);
    void recebeDano(int dano);
    void setPisando(bool pisa);
    void salvar();
    int getVida();
    bool verificarVivo();
    void morrer();
    bool getPisando(); 
    
    // Método para obter o corpo (RectangleShape)
    const RectangleShape& getCorpo() const;

    //virtual void executar() = 0;
    virtual void salvarDataBuffer(nlohmann::ordered_json& json) = 0; 
    virtual void mover() = 0; 
};

} 

#endif