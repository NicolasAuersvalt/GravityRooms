#include "Menus/menu.h"

// ===/===/===/===/ Obrigatório ===/===/===/===/

namespace Menus {
Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao,
           const std::string nome, const unsigned int tamFonte)
    : Ente(ID),
      listaBotaoTexto(),
      it(),
      tamBotao(tamBotao),
      botaoSelecionado(false),
      titulo(nome, tamFonte) {}

Menu::~Menu() {
  if (!listaBotaoTexto.empty()) {
    for (it = listaBotaoTexto.begin(); it != listaBotaoTexto.end(); it++) {
      delete (*it);
      *it = nullptr;
    }
    listaBotaoTexto.clear();
  }
}

void Menu::mudarEstadoObservador() {}

void Menu::addBotao(const std::string info, const sf::Vector2f pos,
                    const IDs::IDs ID, const sf::Color corSelecionado) {
  Botoes::BotaoTexto* botao =
      new Botoes::BotaoTexto(info, tamBotao, pos, ID, corSelecionado);
  if (botao == nullptr) {
    cout << "ERROR::Jungle::Menu::nao foi possivel criar um botao" << endl;
  }
  listaBotaoTexto.push_back(botao);
}

void Menu::atualizarPosicaoFundo() {}

void Menu::inicializarIterator() {
  try {
    it = listaBotaoTexto.begin();
    (*it)->setSelecionado(true);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
}

void Menu::selecionaCima() {
  Botoes::BotaoTexto* botao = *it;
  botao->setSelecionado(false);
  if (it == listaBotaoTexto.begin()) {
    it = listaBotaoTexto.end();
  }
  it--;
  botao = *it;
  botao->setSelecionado(true);
}

void Menu::selecionaBaixo() {
  Botoes::BotaoTexto* botao = *it;
  botao->setSelecionado(false);
  it++;
  if (it == listaBotaoTexto.end()) {
    it = listaBotaoTexto.begin();
  }
  botao = *it;
  botao->setSelecionado(true);
}

const IDs::IDs Menu::getIDBotaoSelecionado() const { return (*it)->getID(); }

void Menu::eventoTeclado(const sf::Keyboard::Key tecla) {
  if (!listaBotaoTexto.empty()) {
    // Desmarcar o botão atual
    (*it)->setSelecionado(false);

    if (tecla == sf::Keyboard::Down) {
      // Mover para o próximo botão
      it++;
      if (it == listaBotaoTexto.end()) {
        it = listaBotaoTexto.begin();  // Volta ao primeiro botão
      }

    } else if (tecla == sf::Keyboard::Up) {
      // Mover para o botão anterior
      if (it == listaBotaoTexto.begin()) {
        it = listaBotaoTexto.end();  // Define como o "fim"
      }
      it--;

    } else if (tecla == sf::Keyboard::Enter) {
      // Seleciona o botão atual e atualiza a variável

      botaoSelecionado = true;
    }

    // Marcar o botão selecionado
    (*it)->setSelecionado(true);
  }
}
bool Menu::getSelecionado() { 
  return botaoSelecionado;
   }

void Menu::setSelecionado(bool status) { 
  botaoSelecionado = status;
   }

void Menu::desenhar(Gerenciador_Grafico* GG) {

  // desenha todos os botões na janela
  std::list<Botoes::BotaoTexto*>::iterator aux;
  for (aux = listaBotaoTexto.begin(); aux != listaBotaoTexto.end(); aux++) {
    Botoes::BotaoTexto* botao = *aux;
    botao->desenhar(*GG);
    botao = nullptr;
  }

}

// namespace Menu
// ===/===/===/===/ Outros  ===/===/===/===/
}  // namespace Menus
