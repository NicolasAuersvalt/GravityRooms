#include "Gerenciadores/gerenciador_grafico.h"

#include "Entidades/Personagens/tripulante.h"
#include "ente.h"
namespace Gerenciadores {

// Inicializar o atributo estático
Gerenciador_Grafico *Gerenciador_Grafico::grafico = nullptr;

// Construtor
Gerenciador_Grafico::Gerenciador_Grafico() { inicializador(); }

// Destrutor
Gerenciador_Grafico::~Gerenciador_Grafico() { fechar(); }

// Método estático para obter a instância única
Gerenciador_Grafico *Gerenciador_Grafico::getInstancia() {
  if (grafico == nullptr) {
    grafico = new Gerenciador_Grafico();
  }

  return grafico;
}

void Gerenciador_Grafico::inicializador() {
  // Cria a janela corretamente

  window.create(VideoMode(largura, altura), nomeJanela);
  // Define o framerate para 60fps
  window.setFramerateLimit(fps);
}

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
  if (!pE) {
    cerr << "Erro: Ponteiro para Ente é nulo!" << endl;
    return;
  }

  if (!window.isOpen()) {
    cerr << "Erro: A janela não está aberta!" << endl;
    return;
  }

  // Obtém o sprite do Ente
  Sprite sprite = pE->getSprite();

  // Obtém a textura associada ao sprite
  const Texture *texture = pE->getTexture();
  if (!texture) {
    cerr << "Erro: Ente não possui uma textura carregada!" << endl;

    static Texture texturaPadrao;
    if (!texturaPadrao.loadFromFile("textura_padrao.png")) {
      // cerr << "Erro: Não foi possível carregar a textura padrão!" << endl;
      return;
    }

    // Associa a textura padrão ao sprite
    sprite.setTexture(texturaPadrao);
    cerr << "A textura padrão foi aplicada ao sprite do Ente." << endl;
  }

  // Desenha o sprite do Ente na janela

  window.draw(sprite);
}

void Gerenciador_Grafico::fechar() { window.close(); }

void Gerenciador_Grafico::limpar() { window.clear(); }

void Gerenciador_Grafico::exibir() { window.display(); }

// Desenhar todos os objetos na tela
void Gerenciador_Grafico::desenhar(Sprite &sprite) {
  window.clear(); // Limpa a tela

  // Desenha o fundo (ou qualquer sprite que seja passado)
  window.draw(sprite);

  window.display(); // Exibe os objetos na tela
}

void Gerenciador_Grafico::desenharTexto(const Drawable &Texto) {
  // Desenha o fundo (ou qualquer sprite que seja passado)
  window.draw(Texto);
}

// Atualizar a janela (captura eventos)
void Gerenciador_Grafico::atualizar() {
  Event event;
  while (window.pollEvent(event)) {
    if (event.type == Event::Closed) {
      fechar();
    }
  }
}

// Verificar se a janela está aberta
const bool Gerenciador_Grafico::estaAberta() { return window.isOpen(); }

bool Gerenciador_Grafico::processarEvento(Event &event) {
  return window.pollEvent(event);
}

RenderWindow &Gerenciador_Grafico::getJanela() { return window; }

void Gerenciador_Grafico::executar() {
  Event event;

  if (window.pollEvent(event)) {
    if (event.type == Event::Closed) {
      fechar();
    }
    window.display(); // Exibe a tela atualizada
  }
}

void Gerenciador_Grafico::desenharBackground(Sprite &sprite) {
  // Desenha o fundo (ou qualquer sprite que seja passado)
  window.draw(sprite);
}

} // namespace Gerenciadores
