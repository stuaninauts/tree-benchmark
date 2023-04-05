typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pABP;

pABP* InsereArvore(pABP *a, tipoinfo ch);
void preFixadoE(pABP *a);
void preFixadoD(pABP *a);
void posFixadoE(pABP *a);
void posFixadoD(pABP *a);
void CentralE(pABP *a);
void CentralD(pABP *a);
pABP* consultaABP(pABP *a, tipoinfo chave);
pABP* consultaABP2(pABP *a, tipoinfo chave);

