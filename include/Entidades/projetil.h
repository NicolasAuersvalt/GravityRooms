#ifndef PROJETIL_H
#define PROJETIL_H

#include "Entidades/entidade.h"

namespace Entidades{
    class Personagem;

    class Projetil : public Entidade{

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
            static int danoProjetil;
            bool ativo;


            // ===/===/===/===/ Outros  ===/===/===/===/
            bool colidiu;
            Entidade* atirador;
            int dano;
            const float vel_bala = 10.0f;
            sf::Vector2f direcao;

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Projetil();
            virtual ~Projetil();

            void executar() override;

            // ===/===/===/===/ Outros  ===/===/===/===/
            void mover() override;  
            void salvar() override;
            void atualizar();
            // void atirar();
            void setDirecao(const sf::Vector2f& dir);
            void atirar(const sf::Vector2f& posicao);
            void setAtirador(Entidade* a); 
            void colisao(Entidade* e);
            bool getColidir(Entidade* e);
            void danificar(Personagem* p);
            int getDano(){return danoProjetil;}
    };

}

#endif