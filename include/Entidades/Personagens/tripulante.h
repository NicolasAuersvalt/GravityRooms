#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include "Entidades/Personagens/personagem.h"
#include "json.hpp"

namespace Entidades::Personagens{

    class Tripulante : public Personagem{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            int pontos;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Tripulante();
            ~Tripulante();
            void executar() override;  

            
            void salvarDataBuffer(nlohmann::ordered_json& json) {
                
                auto [x, y] = getPosition(); // Desempacota a posição

                json = {

                    {"posicao", { {"x", x}, {"y", y} }},

                    {"vida", getVida()},

                    {"pontos", getPontos()}


                };

            }

            void carregarDataBuffer(const nlohmann::ordered_json& json) {
                if (json.contains("posicao")) {
                    int posicaoX = json["posicao"]["x"].get<int>();
                    int posicaoY = json["posicao"]["y"].get<int>();
                    setPosition(make_pair(posicaoX, posicaoY));
                }

                if (json.contains("vida")) {
                    setVida(json["vida"].get<int>());
                }
                if (json.contains("pontos")) {
                    setPontos(json["pontos"].get<int>());
                }
            }

            int getPontos(){
                return pontos;
            }

            void setPontos(int ponto){
                pontos = pontos;
            }
            

            // ===/===/===/===/ Outros  ===/===/===/===/

            void mover();
            
    };

}

#endif