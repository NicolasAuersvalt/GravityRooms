#ifndef ENTE_H
#define ENTE_H

class Figura;
class GerenciadorGrafico;

class Ente{

    private:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

    protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
        int id;
        static GerenciadorGrafico *pGG; // Ente utiliza Gerenciador Gráfico (Bidirecional)
        Figura *pFig;
                

        // ===/===/===/===/ Outros  ===/===/===/===/


      public:

         // ===/===/===/===/ Obrigatório ===/===/===/===/

        Ente();
        ~Ente();
        virtual void executar() = 0; // Pois é abstrata
        void desenhar();

        // ===/===/===/===/ Outros  ===/===/===/===/
        

};

#endif