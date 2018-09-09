#include "ArvoreAVL.h"
#include "No.h"
#include "Informacao.h"
#include <iostream>
#include <cstring>

using namespace std;

ArvoreAVL::ArvoreAVL()
{
    this->raiz = NULL;
}

ArvoreAVL::~ArvoreAVL()
{
    delete raiz;
}

void ArvoreAVL::inserirInfo(Informacao* i) throw(char*)
{
    if(i == NULL)
        throw("A informação não pode ser nula!");
    if(tem(this->raiz, i))
        throw("A informação já existe!");
    this->raiz = inserir(this->raiz, i);
}

No* ArvoreAVL::inserir(No* no, Informacao* i)
{
    if(no == NULL)
        return new No(i);

    int c = i->compareTo(no->getInformacao());

    if(c < 0)
        no->setPtrEsq(inserir(no->getPtrEsq(), i));
    if(c > 0)
        no->setPtrDir(inserir(no->getPtrDir(), i));

    return this->balancear(no);
}

void ArvoreAVL::teste()
{
    this->raiz = this->balancear(this->raiz);
}

No* ArvoreAVL::balancear(No* no)
{
    if(no->getEquilibrio() > 1)
    {
        if(no->getPtrDir()->getEquilibrio() < 0)
            return this->giroDuploParaEsq(no);
        else
            return this->giroParaEsq(no);
    }
    else
        if(no->getEquilibrio() < -1)
        {
            if(no->getPtrEsq()->getEquilibrio() > 0)
                return this->giroDuploParaDir(no);
            else
                return this->giroParaDir(no);
        }
    return no;
}

No* ArvoreAVL::giroParaEsq(No* no)
{
    No* novaRaiz = no->getPtrDir();
    no->setPtrDir(novaRaiz->getPtrEsq());
    novaRaiz->setPtrEsq(no);

    return novaRaiz;
}

No* ArvoreAVL::giroParaDir(No* no)
{
    No* novaRaiz = no->getPtrEsq();
    no->setPtrEsq(novaRaiz->getPtrDir());
    novaRaiz->setPtrDir(no);

    return novaRaiz;
}
No* ArvoreAVL::giroDuploParaEsq(No* no)
{
    no->setPtrDir(this->giroParaDir(no->getPtrDir()));
    return giroParaEsq(no);
}
No* ArvoreAVL::giroDuploParaDir(No* no)
{
    no->setPtrEsq(this->giroParaEsq(no->getPtrEsq()));
    return giroParaDir(no);
}

void ArvoreAVL::excluirInfo(Informacao* i)
{

}

bool ArvoreAVL::tem(Informacao* i)
{
    return tem(this->raiz, i);
}

bool ArvoreAVL::tem(No* no, Informacao* i)
{
    if(no == NULL)
        return false;

    int c = i->compareTo(no->getInformacao());

    if(c < 0)
        return tem(no->getPtrEsq(), i);
    if(c > 0)
        return tem(no->getPtrDir(), i);
    return true;
}

ostream& operator<<(ostream& os, const ArvoreAVL& ar)
{
    if(ar.raiz == NULL)
        os << "()";
    else
        ar.raiz->printar(os);

    return os;
}
