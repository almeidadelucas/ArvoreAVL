#ifndef NO_H
#define NO_H
#include "Informacao.h"
#include <iostream>

using namespace std;

class No
{
    public:
        No(Informacao*);
        virtual ~No();
        Informacao* getInformacao();
        No*         getPtrEsq();
        No*         getPtrDir();
        void        setPtrEsq(No*);
        void        setPtrDir(No*);
        void        incNiveisEsq();
        void        incNiveisDir();
        int         getEquilibrio();
        void        printar(ostream&);
    private:
        Informacao* info;
        No*         ptrEsq;
        No*         ptrDir;
        int         niveisEsq;
        int         niveisDir;
};

#endif // NO_H
