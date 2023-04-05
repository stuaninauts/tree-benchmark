#ifndef AVL_H
#define AVL_H

typedef struct TNodoAVL{
    int info;
    int FB;
    struct TNodoAVL *esq;
    struct TNodoAVL *dir;
} pAVL;

// int Altura (pAVL * a);
// pAVL * RotacaoDireita(pAVL * pt);
// pAVL * RotacaoEsquerda(pAVL * pt);
// pAVL * RotacaoDuplaDireita (pAVL * pt);
// pAVL * RotacaoDuplaEsquerda (pAVL * pt);
pAVL * InsereAVL (pAVL * a, int x);
pAVL* consultaAVL(pAVL *a, int chave);

#endif