#include <iostream>
#include "MinhaInformacao.h"
#include "ArvoreAVL.h"

using namespace std;

int main()
{
    ArvoreAVL ar;

    MinhaInformacao* mi1 = new MinhaInformacao(4);
    MinhaInformacao* mi2 = new MinhaInformacao(2);
    MinhaInformacao* mi3 = new MinhaInformacao(1);
    MinhaInformacao* mi4 = new MinhaInformacao(3);

    ar.inserirInfo(mi1);
    ar.inserirInfo(mi2);
    ar.inserirInfo(mi3);
    ar.inserirInfo(mi4);

    cout << ar;
    cout << "\n exclunindo 4... \n";
    ar.excluirInfo(mi1);
    cout << ar;

    return 0;
}
