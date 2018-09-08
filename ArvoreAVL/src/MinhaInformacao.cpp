#include "MinhaInformacao.h"
#include <informacao.h>
#include <sstream>

MinhaInformacao::MinhaInformacao(int cod)
{
    this->codigo = cod;
}

MinhaInformacao::~MinhaInformacao()
{

}

int MinhaInformacao::getCodigo()
{
    return this->codigo;
}

int MinhaInformacao::compareTo(Informacao* info) throw(char*)
{
    if(info == NULL)
        throw("A informação não pode ser nula");

    MinhaInformacao* mi = (MinhaInformacao*)info;

    if(this->codigo == mi->getCodigo())
        return 0;
    else
        if(this->codigo < mi->getCodigo())
            return -1;
    return 1;
}
