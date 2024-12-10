#ifndef NOME
#define NOME

namespace Lista{

    template <typename TL>

    class Lista{

        private:
            Elemento<TL>* pPrimeiro;
            Elemento<TL>* pUltimo

        // ===/===/===/===/ Obrigatório ===/===/===/===/

            

        // ===/===/===/===/ Outros  ===/===/===/===/

        protected:

        // ===/===/===/===/ Obrigatório ===/===/===/===/

                

        // ===/===/===/===/ Outros  ===/===/===/===/

        public:

        // ===/===/===/===/ Obrigatório ===/===/===/===/
            Lista();
            ~Lista();
            void incluir(TL *p);
            void limpar();
            Elemento<TL>* getUltimo();
            Elemento<TL>* getPrimeiro();
            bool estaVazio();
                

        // ===/===/===/===/ Outros  ===/===/===/===/

    };

}
#endif