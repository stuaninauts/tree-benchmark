#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pABP* InsereArvore(pABP *a, tipoinfo ch)
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

void preFixadoE(pABP *a)
{
     if (a!= NULL)
     {
          printf("%d - ",a->info);
          preFixadoE(a->esq);
          preFixadoE(a->dir);
      }
}

void preFixadoD(pABP *a)
{
     if (a!= NULL)
     {
          printf("%d - ",a->info);
          preFixadoD(a->dir);
          preFixadoD(a->esq);
      }
}

void posFixadoE(pABP *a)
{
     if (a!= NULL)
     {
          posFixadoE(a->esq);
          posFixadoE(a->dir);
          printf("%d - ",a->info);
      }
}

void posFixadoD(pABP *a)
{
     if (a!= NULL)
     {
          posFixadoD(a->dir);
          posFixadoD(a->esq);
          printf("%d - ",a->info);
      }
}

void CentralE(pABP *a)
{
     if (a!= NULL)
     {
          CentralE(a->esq);
          printf("%d - ",a->info);
          CentralE(a->dir);
      }
}

void CentralD(pABP *a)
{
     if (a!= NULL)
     {
          CentralD(a->dir);
          printf("%d - ",a->info);
          CentralD(a->esq);
      }
}


pABP* consultaABP(pABP *a, tipoinfo chave) {

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

pABP* consultaABP2(pABP *a, tipoinfo chave) {
    if (a!=NULL) {
       if (a->info == chave)
         return a;
       else
           if (a->info > chave)
                return consultaABP2(a->esq,chave);
            if (a->info < chave)
                return consultaABP2(a->dir,chave);

            else return a;
       }
       else return NULL;
}


