#ifndef NOME
#define NOME

class NOME{

    private:

    // ===/===/===/===/ Obrigatório ===/===/===/===/
        Elemento<TL>* pPrimeiro;
        TE* pinfo;
            

    public:

    // ===/===/===/===/ Obrigatório ===/===/===/===/
    
        Elemento();
        ~Elemento();
        void incluir(TE* incluir);
        void setProx(Elemento<TE>* pE);
        Elemento<TE>* getProximo()
            

    // ===/===/===/===/ Outros  ===/===/===/===/

};


#endif