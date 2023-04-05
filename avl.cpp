#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

int Altura (pAVL *a)
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
      return 0;
    else
    {
       Alt_Esq = Altura (a->esq);
       Alt_Dir = Altura (a->dir);
       if (Alt_Esq > Alt_Dir)
         return (1 + Alt_Esq);
       else
         return (1 + Alt_Dir);
     }
}

pAVL* RotacaoDireita(pAVL *pt){
   pAVL* ptu;

   ptu = pt->esq; 
   pt->esq = ptu->dir; 
   ptu->dir = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
}

pAVL* RotacaoEsquerda(pAVL *pt){
   pAVL* ptu;

   ptu = pt->dir; 
   pt->dir = ptu->esq; 
   ptu->esq = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
} 

pAVL* RotacaoDuplaDireita (pAVL* pt){
   pAVL* ptu, *ptv;

   ptu = pt->esq; 
   ptv = ptu->dir; 
   ptu->dir = ptv->esq; 
   ptv->esq = ptu; 
   pt->esq = ptv->dir; 
   ptv->dir = pt; 
   if (ptv->FB == 1)   pt->FB = -1;
      else pt->FB = 0;
   if (ptv->FB == -1)  ptu->FB = 1;
      else ptu->FB = 0;
   pt = ptv; 
   return pt;
} 

pAVL* RotacaoDuplaEsquerda (pAVL* pt){
   pAVL *ptu, *ptv;

   ptu = pt->dir; 
   ptv = ptu->esq; 
   ptu->esq = ptv->dir; 
   ptv->dir = ptu; 
   pt->dir = ptv->esq; 
   ptv->esq = pt; 
   if (ptv->FB == -1) pt->FB = 1;
     else pt->FB = 0;
   if (ptv->FB == 1) ptu->FB = -1;
      else ptu->FB = 0;
   pt = ptv; 
   return pt;
}


pAVL* InsereAVL(pAVL* a, int x) {
    if (a == NULL) {
        // A árvore está vazia, criamos um novo nodo com a informação x
        pAVL* novo = (pAVL*) malloc(sizeof(pAVL));
        novo->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->FB = 0;
        return novo;
    }

    // A árvore não está vazia, devemos procurar o local correto para inserir o novo nodo
    if (x < a->info) {
        // O novo nodo deve ser inserido na subárvore esquerda
        a->esq = InsereAVL(a->esq, x);

        // Verifica se a inserção afetou o fator de balanceamento do nodo atual
        if (Altura(a->esq) - Altura(a->dir) == 2) {
            if (x < a->esq->info) {
                a = RotacaoDireita(a);
            } else {
                a = RotacaoDuplaDireita(a);
            }
        }
    } else {
        // O novo nodo deve ser inserido na subárvore direita
        a->dir = InsereAVL(a->dir, x);

        // Verifica se a inserção afetou o fator de balanceamento do nodo atual
        if (Altura(a->dir) - Altura(a->esq) == 2) {
            if (x > a->dir->info) {
                a = RotacaoEsquerda(a);
            } else {
                a = RotacaoDuplaEsquerda(a);
            }
        }
    }

    // Atualiza o fator de balanceamento do nodo atual
    a->FB = Altura(a->esq) - Altura(a->dir);

    return a;
}


pAVL* consultaAVL(pAVL *a, int chave) {

    while (a!=NULL){
          if (a->info == chave )
             return a; //achou entao retorna o ponteiro para o nodo
          else
            if (a->info > chave)
               a = a->esq;
            else
               a = a->dir;
            }
            return NULL; //se nao achou
}