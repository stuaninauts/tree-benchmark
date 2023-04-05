#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"


struct TNodoA{
TipoInfo info;
int FB;
struct TNodoA *esq;
struct TNodoA *dir;
};


// pAVL* InsereArvore(pAVL* a, TipoInfo ch)
// {
//   if (a == NULL)
//   {
//     a = (pAVL*) malloc(sizeof(pAVL));
//     a->info = ch;
//     a->esq = NULL;
//     a->dir = NULL;
//     a->FB = 0; // o nodo � sempre inserido como folha ent�o seu fator de balanceamento � 0
//   }
//   else
//   if (ch < (a->info))
//     a->esq = InsereArvore(a->esq,ch);
//   else
//     a->dir = InsereArvore(a->dir,ch);
//     return a;
// }

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

int Calcula_FB(pAVL *a)
{
    return (Altura(a->esq) - Altura(a->dir));
}

void Desenha(pAVL *a , int nivel)
{
int x;

 if (a !=NULL)
 {
   for (x=1; x<=nivel; x++)
      printf("=");
  printf("%d FB= %d\n", a->info, Calcula_FB(a));
   if (a->esq != NULL) Desenha(a->esq, (nivel+1));
   if (a->dir != NULL) Desenha(a->dir, (nivel+1));
 }
}

int is_avl(pAVL *a)
{
  int alt_esq, alt_dir;

  if (a!=NULL)
  {
     alt_esq = Altura(a->esq);
     alt_dir = Altura(a->dir);
     return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) && (is_avl(a->esq)) && (is_avl(a->dir)) );
  }
  else
  return 1;
}


pAVL* rotacao_direita(pAVL *pt){
   pAVL* ptu;

   ptu = pt->esq; 
   pt->esq = ptu->dir; 
   ptu->dir = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
}

pAVL* rotacao_esquerda(pAVL *pt){
   pAVL* ptu;

   ptu = pt->dir; 
   pt->dir = ptu->esq; 
   ptu->esq = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
} 

pAVL* rotacao_dupla_direita (pAVL* pt){
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

pAVL* rotacao_dupla_esquerda (pAVL* pt){
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


pAVL* Caso1 (pAVL* a , int *ok)
{
   pAVL *ptu; 

	ptu = a->esq;
	if (ptu->FB == 1) 
    {    
        printf("fazendo rotacao direita em %d\n",a->info);
        a = rotacao_direita(a);
     }
    else
    {
        printf("fazendo rotacao dupla direita em %d\n",a->info);
        a = rotacao_dupla_direita(a);
    }
	
    a->FB = 0;
	*ok = 0;
	return a;
}

pAVL* Caso2 (pAVL *a , int *ok)
{
    pAVL *ptu; 

	ptu = a->dir;
	if (ptu->FB == -1) 
    {
       Desenha(a,1);
       printf("fazendo rotacao esquerda em %d\n",a->info);
       a=rotacao_esquerda(a);
    }
    else
    {
       Desenha(a,1);
       printf("fazendo rotacao dupla esquerda em %d\n",a->info);
       a=rotacao_dupla_esquerda(a);
    }
	a->FB = 0;
	*ok = 0;
	return a;
}

pAVL* InsereAVL (pAVL *a, TipoInfo x, int *ok)
{
/* Insere nodo em uma �rvore AVL, onde A representa a raiz da �rvore,
  x, a chave a ser inserida e h a altura da �rvore */

     if (a == NULL) 
     {
     	a = (pAVL*) malloc(sizeof(pAVL));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0; 
	    *ok = 1;
     }
     else
     if (x < a->info) 
     {
		a->esq = InsereAVL(a->esq,x,ok);
        if (*ok) 
        {
   		    switch (a->FB) {
        	  case -1:  a->FB = 0; *ok = 0; break;
			  case  0:  a->FB = 1;  break;
			  case  1:  a=Caso1(a,ok); break;
            }
         }
     }
	 else
     {
  		    a->dir = InsereAVL(a->dir,x,ok);
            if (*ok)
            { 
              switch (a->FB) {
                case  1:  a->FB = 0; *ok = 0; break;
                case  0:  a->FB = -1; break;
			    case -1:  a = Caso2(a,ok); break;
             }
            }
     }
     return a;
}

pAVL* consultaAVL(pAVL *a, TipoInfo chave) {

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
