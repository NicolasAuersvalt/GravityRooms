#include "Gerenciadores/gerenciador_salvamento.h"

namespace Gerenciadores {

    // Construtor
    Gerenciador_Salvamento::Gerenciador_Salvamento() : pJog1(nullptr) {}

    // Destrutor
    Gerenciador_Salvamento::~Gerenciador_Salvamento() {}

    // Método para definir o jogador
    void Gerenciador_Salvamento::setJogador(Entidades::Personagens::Tripulante* jogador) {
        if (jogador) {
            pJog1 = jogador;
        }
    }

    // Método para obter o jogador
    Entidades::Personagens::Tripulante* Gerenciador_Salvamento::getJogador() {
        return pJog1;
    }

    // Método para serializar o objeto Jogador para JSON
    json Gerenciador_Salvamento::toJson() const {
        return {
            {"nome", nome},
            {"x", pJog1->getPosicao().x},
            {"y", pJog1->getPosicao().y}
        };
    }

    // Função para verificar se o arquivo existe
    bool Gerenciador_Salvamento::arquivoExiste(const string& caminho) {
        return filesystem::exists(caminho);
    }

}
