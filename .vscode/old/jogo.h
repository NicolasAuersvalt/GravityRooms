#ifndef JOGO_H
#define JOGO_H

class Jogador;
class GerenciadorGrafico;

namespace Listas{

    class Jogo{

        public:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

            Jogo();
            ~Jogo();
            void executar();

        // ===/===/===/===/ Outros  ===/===/===/===/
        

        protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

        private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

        Jogador pJog1;
        GerenciadorGrafico GG;
                

        // ===/===/===/===/ Outros  ===/===/===/===/

    };
}

#endif