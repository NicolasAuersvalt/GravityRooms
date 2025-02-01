#include "Gerenciadores/gerenciador_eventos.h"

namespace Gerenciadores {
void Gerenciador_Eventos::processarEventoJanela(Gerenciador_Grafico &GG,
                                                MenuPrincipal &menuGeral) {
  Event evento;

  // Verificar se há eventos na fila
  while (GG.getJanela().pollEvent(evento)) {
    if (evento.type == Event::KeyPressed) {
      string teclaPressionada = processarTecla(evento.key.code);

      // FAZ ALGUMA COISA, COMO
      // menuGeral.eventoTeclado(eventao.key.code);

    } else if (evento.type == Event::Closed) {
      GG.fechar();
    }
  }
}

string Gerenciador_Eventos::processarTecla(Keyboard::Key tecla) {
  // Mapeamento das teclas para strings
  static map<Keyboard::Key, string> teclas{{Keyboard::A, "A"},
                                           {Keyboard::B, "B"},
                                           {Keyboard::C, "C"},
                                           {Keyboard::D, "D"},
                                           {Keyboard::E, "E"},
                                           {Keyboard::F, "F"},
                                           {Keyboard::G, "G"},
                                           {Keyboard::H, "H"},
                                           {Keyboard::I, "I"},
                                           {Keyboard::J, "J"},
                                           {Keyboard::K, "K"},
                                           {Keyboard::L, "L"},
                                           {Keyboard::M, "M"},
                                           {Keyboard::N, "N"},
                                           {Keyboard::O, "O"},
                                           {Keyboard::P, "P"},
                                           {Keyboard::Q, "Q"},
                                           {Keyboard::R, "R"},
                                           {Keyboard::S, "S"},
                                           {Keyboard::T, "T"},
                                           {Keyboard::U, "U"},
                                           {Keyboard::V, "V"},
                                           {Keyboard::W, "W"},
                                           {Keyboard::X, "X"},
                                           {Keyboard::Y, "Y"},
                                           {Keyboard::Z, "Z"},
                                           {Keyboard::Up, "Up Arrow"},
                                           {Keyboard::Down, "Down Arrow"},
                                           {Keyboard::Left, "Left Arrow"},
                                           {Keyboard::Right, "Right Arrow"},
                                           {Keyboard::Enter, "Enter"},
                                           {Keyboard::Space, "Space"},
                                           {Keyboard::Num2, "Num2"}};
                                           {Keyboard::Escape, "Escape"}};

                                           // Retorna a tecla em formato string,
                                           // ou "Desconhecida" se a tecla não
                                           // estiver mapeada
                                           if (teclas.find(tecla) !=
                                               teclas.end()) {
                                             return teclas[tecla];
                                           }
                                           return "Desconhecida";
                                           }

                                           string Gerenciador_Eventos::
                                               isTeclaPressionada(
                                                   const Keyboard::Key tecla) {
                                             if (Keyboard::isKeyPressed(
                                                     tecla)) {
                                               // Chama processarTecla quando a
                                               // tecla está pressionada
                                               string teclaPressionada =
                                                   processarTecla(tecla);

                                               return teclaPressionada;  // Retorna
                                                                         // o
                                                                         // nome
                                                                         // da
                                                                         // tecla
                                                                         // processada
                                             }
                                             return "";  // Retorna string vazia
                                                         // caso a tecla não
                                                         // esteja pressionada
                                           }

                                           Vector2f Gerenciador_Eventos::
                                               obterMovimento() {
                                             // Define o vetor de movimento
                                             // inicial como (0.f, 0.f)
                                             Vector2f movimento(0.f, 0.f);

                                             // Verificar eventos
                                             Event event;

                                             // Movimentação baseada nas teclas
                                             // pressionadas
                                             if (Keyboard::isKeyPressed(
                                                     Keyboard::Left)) {
                                               movimento.x =
                                                   -5.f;  // Move para a
                                                          // esquerda
                                             }

                                             if (Keyboard::isKeyPressed(
                                                     Keyboard::Right)) {
                                               movimento.x =
                                                   5.f;  // Move para a direita
                                             }

                                             if (Keyboard::isKeyPressed(
                                                     Keyboard::Up)) {
                                               movimento.y =
                                                   -5.f;  // Move para cima
                                             }

                                             // if (!noChao) {
                                             //     movimento.y = 5.f;   // Move
                                             //     para baixo
                                             // }

                                             return movimento;
                                           }
                                           }  // namespace Gerenciadores
