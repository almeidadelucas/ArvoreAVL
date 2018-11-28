#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "No.h"
#include "Informacao.h"
#include <iostream>

using namespace std;

class ArvoreAVL
{
    public:
        ArvoreAVL();
        virtual ~ArvoreAVL();
        void inserirInfo(Informacao*);
        void excluirInfo(Informacao*);
        bool tem(Informacao*);
        friend ostream& operator<<(ostream&, const ArvoreAVL&);
    private:
        No* raiz;
        No* balancear(No*);
        No* giroParaEsq(No*);
        No* giroParaDir(No*);
        No* giroDuploParaEsq(No*);
        No* giroDuploParaDir(No*);
        No* inserir(No*,Informacao*);
        No* excluir(No*,Informacao*);
        bool tem(No*, Informacao*);
        Informacao* encontrarMaior(No*);
        Informacao* encontrarMenor(No*);
};

#endif // ARVOREAVL_H
