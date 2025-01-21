#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidades/entidade.h"
#include <iostream>

namespace Entidades::Personagens{

    class Personagem : public Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            

                    

            // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            float velocidadeY = 0.f;
            float velocidadeX = 0.f;
            int pontosVida;
            bool noChao;
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Personagem(pair<int,int>p, pair<int, int>d);
            ~Personagem();
            void salvar();

            // Métodos Virtuais
            virtual void executar() = 0;
            virtual void salvarDataBuffer(){


            }
            void setPisando(bool pisa){
                noChao = pisa;
            }
            bool getPisando(){
                return noChao;

            }
            void recebeDano(int dano){
                pontosVida -= dano;
                if(!verificarVivo()){
                    morrer();
                }
            }

            bool verificarVivo(){
                return (pontosVida>0);
            }
            void morrer(){
                std::cout << "FUlano Morreu" << std::endl;
                // REMOVER DA LISTA DE ENTIDADES SEI LÁ
            }

            
            
            

            // ===/===/===/===/ Outros  ===/===/===/===/
            

    };

}

#endif