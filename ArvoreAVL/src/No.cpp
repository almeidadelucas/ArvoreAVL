#include "No.h"
#include "Informacao.h"
#include <sstream>

No::No(Informacao* i)
{
    this->niveisDir = 0;
    this->niveisEsq = 0;
    this->ptrDir    = NULL;
    this->ptrEsq    = NULL;
    this->info      = i;
}

No::~No()
{
}

Informacao* No::getInformacao()
{
    return this->info;
}

No* No::getPtrEsq()
{
    return this->ptrEsq;
}

No* No::getPtrDir()
{
    return this->ptrDir;
}

int No::getEquilibrio()
{
    return this->niveisDir - this->niveisEsq;
}

void No::setPtrEsq(No* no)
{
    this->ptrEsq = no;
}

void No::setPtrDir(No* no)
{
    this->ptrDir = no;
}

void No::incNiveisEsq()
{
    this->niveisEsq++;
}

void No::incNiveisDir()
{
    this->niveisDir++;
}

void No::printar(ostream& os)
{
    os << "(";
    cout << "esq: " << this->ptrEsq << "\n";
    if(this->ptrEsq != NULL)
        this->ptrEsq->printar(os);

    os << this->info->getCodigo();

    if(this->ptrDir != NULL)
        this->ptrDir->printar(os);

    os << ")";
}
