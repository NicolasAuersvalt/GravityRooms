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

        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            
                    

            // ===/===/===/===/ Outros  ===/===/===/===/


        public:

            // ===/===/===/===/ Obrigatório ===/===/===/===/

            Projetil();
            virtual ~Projetil();

            // Métodos Virtuais
           // void executar() override;

            // ===/===/===/===/ Outros  ===/===/===/===/
            
            void atualizar();
            void setAtirador(Entidade* a); 
            void colisao(Entidade* e);
            bool getColidir(Entidade* e);
            void danificar(Personagem* p);
            int getDano(){return danoProjetil;}
    };

}

#endif