#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pABP* InsereArvore(pABP *a, int ch)
{
     if (a == NULL)
     {
         a =  (pABP*) malloc(sizeof(pABP));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

pABP* consultaABP(pABP *a, int chave) {

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
