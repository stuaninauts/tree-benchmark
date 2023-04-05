typedef int TipoInfo;

typedef struct TNodoA pAVL;

pAVL * InsereArvore(pAVL * a, TipoInfo ch);
int Altura (pAVL * a);
int Calcula_FB(pAVL * a);
void Desenha(pAVL * a , int nivel);
int is_avl(pAVL * a);
pAVL * rotacao_direita(pAVL * pt);
pAVL * rotacao_esquerda(pAVL * pt);
pAVL * rotacao_dupla_direita (pAVL * pt);
pAVL * rotacao_dupla_esquerda (pAVL * pt);
pAVL * Caso1 (pAVL * a , int *ok);
pAVL * Caso2 (pAVL * a , int *ok);
pAVL * InsereAVL (pAVL * a, TipoInfo x, int *ok);
pAVL* consultaAVL(pAVL *a, TipoInfo chave);

