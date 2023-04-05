#ifndef ABP_H
#define ABP_H

typedef struct TNodoABP{
        int info;
        struct TNodoABP *esq;
        struct TNodoABP *dir;
} pABP;

pABP* InsereArvore(pABP *a, int ch);
pABP* consultaABP(pABP *a, int chave);

#endif
