#ifndef LISTA_H
#define LISTA_H


namespace Listas{

    template <typename TL>

    class Lista{

        private:

            template <typename TE>

            class Elemento { // Classe aninhada

                private:

                    // ===/===/===/===/ Obrigatório ===/===/===/===/

                    Elemento<TE>* pProx;  // Ponteiro para o próximo elemento
                    TE* pinfo;  // Ponteiro para o tipo de dado

                    // ===/===/===/===/ Outros  ===/===/===/===/


                public:

                    // ===/===/===/===/ Obrigatório ===/===/===/===/

                    Elemento();  // Construtor
                    ~Elemento();  // Destruidor

                    void incluir(TE* p);
                    void setProx(Elemento<TE>* pE);
                    const Elemento<TE>* getProximo() const;


            };

            Elemento<TL>* pPrimeiro;
            Elemento<TL>* pUltimo;


        public:

            Lista();
            ~Lista();

            void incluir(TL *p);
            void limpar();                

        // ===/===/===/===/ Outros  ===/===/===/===/

    };

}
#endif