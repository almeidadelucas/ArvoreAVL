#include "ArvoreAVL.h"
#include "No.h"
#include "Informacao.h"
#include <iostream>

using namespace std;

ArvoreAVL::ArvoreAVL()
{
    this->raiz = NULL;
}

ArvoreAVL::~ArvoreAVL()
{
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
    {
        no->setPtrEsq(inserir(no->getPtrEsq(), i));
        no->incNiveisEsq();
    }
    if(c > 0)
    {
        no->setPtrDir(inserir(no->getPtrDir(), i));
        no->incNiveisDir();
    }

    return this->balancear(no);
}

No* No::balancear(No* no)
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

No* No::giroParaEsq(No* no)
{
    No* raizAntiga = no;
    // Filho da direita vira nova raiz
    no = no->getPtrDir();
    // Raiz original vira filho da  esquerda da nova raiz
    no->setPtrEsq(raizAntiga);
    //Filho da esq do filho da dir vira filho da dir do filho da esq
    no->getPtrEsq()->setPtrDir(raizAntiga->getPtrDir()->getPtrEsq());

    return no;
}

No* No::giroParaDir(No* no)
{
    No* raizAntiga = no;
    //O filho da esquerda vira nova raiz
    no = no->getPtrEsq();
    //A raiz original vira filho da direita da nova raiz
    no->setPtrDir(aux);
    //O filho da dir do filha da esq vira filho da esq da raiz original
    raiz.setPtrEsq(raizAntiga->getPtrEsq()->getPtrDir());

    return no;
}
No* No::giroDuploParaEsq(No* no)
{
    no->setPtrDir(this->giroParaDir(no->getPtrDir()));
    return no->giroParaEsq(no);
}
No* No::giroDuploParaDir(No* no)
{
    no->setPtrEsq(this->giroParaEsq(no->getPtrEsq()));
    return no->giroParaDir(no);
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
