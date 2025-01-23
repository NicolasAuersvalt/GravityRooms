#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include "Entidades/Personagens/personagem.h"
#include "json.hpp"

namespace Entidades::Personagens{

    class Tripulante : public Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Tripulante();
            ~Tripulante();
            void executar() override;  

            /*
            void salvar(nlohmann::ordered_json& json) {

                // json[chave] = {info}

                json["posicao"] = { {"x", posicao[0]}, {"y", posicao[1]}};

                json["tamanho"] = { {"x", tamanho[0]}, {"y", tamanho[1]}};

                json["vida"] = vida;

             }
            */

            // ===/===/===/===/ Outros  ===/===/===/===/

            void mover();
            
    };

}

#endif