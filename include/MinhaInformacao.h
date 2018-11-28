#ifndef MINHAINFORMACAO_H
#define MINHAINFORMACAO_H
#include <informacao.h>
#include <string>

class MinhaInformacao : public Informacao
{
    public:
        MinhaInformacao(int);
        virtual ~MinhaInformacao();
        int getCodigo();
        int compareTo(Informacao*);
        std::string toString();
    private:
        int codigo;
};

#endif // MINHAINFORMACAO_H
