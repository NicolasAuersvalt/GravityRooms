#ifndef GERENCIADOR_GRAFICO_H
#define GERENCIADOR_GRAFICO_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <mutex>  // Para usar mutex, se necessário
#include <string>
#include <thread>  // Para usar thread

using namespace std;
using namespace sf;

class Ente;

// =====/=====/=====/=====/=====/=====/

// Requisitos Conceituais 1.1
// Requisitos Conceituais 1.2
// Requisitos Conceituais 6.3
// Requisitos Conceituais 6.4
// Requisitos Conceituais 7.1

// =====/=====/=====/=====/=====/=====/

namespace Gerenciadores {

class Gerenciador_Grafico {
 private:
  static Gerenciador_Grafico *grafico;  // Instância única

  string nomeJanela = "GravityRooms";  // Nome da janela
  RenderWindow window;                 // Janela de renderização
  const int fps = 60;                  // Limite de frames por segundo

  const int largura = 1280;
  const int altura = 920;

  // Adicionar o mutex para proteger acesso a recursos compartilhados entre as
  // threads, se necessário
  mutex mtx;

  // Impedir cópia SINGLETON
  Gerenciador_Grafico(const Gerenciador_Grafico &) = delete;
  Gerenciador_Grafico &operator=(const Gerenciador_Grafico &) = delete;

 public:
  // Construtor
  Gerenciador_Grafico();

  // Destrutor
  ~Gerenciador_Grafico();

  // Método para obter a instância única
  static Gerenciador_Grafico *getInstancia();

  void desenharTexto(const Drawable &Texto);

  // Desenhar um ente OBRIGATÓRIO
  void desenharEnte(Ente *pE);

  void desenhar(Sprite &sprite);

  bool processarEvento(Event &event);

  // Verificar se a janela está aberta
  const bool estaAberta();

  // Inicializador de janela
  void inicializador();

  void fechar();

  void limpar();

  void exibir();

  void atualizar();

  void executar();

  // Remover depois
  RenderWindow &getJanela();

  void desenharBackground(Sprite &sprite);
};

}  // namespace Gerenciadores

#endif
