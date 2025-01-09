#ifndef GERENCIADOR_COLISOES_H
#define GERENCIADOR_COLISOES_H

class Inimigo;
class Entidade;
class Projetil;
class Obstaculo;
class Jogador;

#include <iostream>
#include <vector>

namespace Gerenciadores{

    class Gerenciador_Colisoes{

        public:

            // ===/===/===/===/ Obrigatórios ===/===/===/===/

            // Construtor (FALTA)
            Gerenciador_Colisoes();
            
            // Destrutor (FALTA)
            ~Gerenciador_Colisoes();
            /*
            const bool verificarColisao(Entidade *pe1, Entidade *pe2);
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimgs();
            void ColisoewsJogsProjeteis();
            void incluirInimigo(Inimigo *pi);
            void incluirObstcaulo(Inimigo *po);
            void incluirProjetil(Projetil *pj);
            void executar();
            */
            // ===/===/===/===/ Outros  ===/===/===/===/


        protected:

            // ===/===/===/===/ Obrigatório ===/===/===/===/


            // ===/===/===/===/ Outros ===/===/===/===/

        private:

            // ===/===/===/===/ Obrigatório ===/===/===/===/
            //vector<Inimigo*> LIs;  
            //list<Obstaculo*> LOs;   
            //set<Projetil*> LPs;     
            //Jogador pJog1;

            

            // ===/===/===/===/ Outros ===/===/===/===/


    };
} using namespace Gerenciadores;

#endif
