#include "Listas/Lista_Entidades.h"
#include <iostream>
/*
namespace Listas {

    // ===/===/===/===/ Construtor e Destrutor ===/===/===/===/

    Lista_Entidades::Lista_Entidades() {
        // Construtor vazio, inicialização ocorre automaticamente pela classe Lista
    }

    Lista_Entidades::~Lista_Entidades() {
        LEs.limpar(); // Limpa a lista para evitar vazamentos de memória
    }

    // ===/===/===/===/ Métodos Obrigatórios ===/===/===/===/

    void Lista_Entidades::incluir(Entidade* pE) {
        if (pE != nullptr) {
            LEs.incluir(pE); // Adiciona a entidade à lista
        } else {
            std::cerr << "Erro: Tentativa de incluir uma entidade nula na lista." << std::endl;
        }
    }

    void Lista_Entidades::percorrer() {
        // Percorre a lista e executa alguma operação com cada entidade
        auto* elemento = LEs.getPrimeiro();

        while (elemento != nullptr) {

            Entidade* entidade = elemento->getInfo();

            if (entidade != nullptr) {

                entidade->atualizar(); // Exemplo: Atualizar as entidades
                
            }

            elemento = elemento->getProximo();
        }
    }

    void Lista_Entidades::desenharTodos() {
        // Percorre a lista e desenha todas as entidades
        auto* elemento = LEs.getPrimeiro();
        while (elemento != nullptr) {
            Entidade* entidade = elemento->getInfo();
            if (entidade != nullptr) {
                entidade->desenhar(); // Desenha a entidade
            }
            elemento = elemento->getProximo();
        }
    }

}
*/