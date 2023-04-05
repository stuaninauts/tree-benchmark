#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "abp.h"
#include "avl.h"

#define AVL_PRECISION 10


int main(int argc, char **argv) {

   srand(time(0));

   printf("%s\n", argv[1]);
   printf("%s\n", argv[2]);

   // Create tree
   pABP *ABP = NULL;
   pAVL *AVL = NULL;

   int size_of_tree = atoi(argv[2]);

   // Insert ABP
   FILE * db = fopen(argv[1], "r");
   char buff[1024];
   clock_t start = clock();
      int tmp;
      while(fgets(buff, sizeof(buff), db) != NULL) {
         tmp = atoi(buff);
         ABP = InsereArvore(ABP, tmp);
      }
   clock_t end = clock();
   fclose(db);

   double insert_time_ABP = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Insert %d integers: %lf\n", size_of_tree, insert_time_ABP);

   // Insert AVL
   db = fopen(argv[1], "r");
   start = clock();
      while(fgets(buff, sizeof(buff), db) != NULL) {
         tmp = atoi(buff);
         AVL = InsereArvore(AVL, tmp);
      }
   end = clock();
   fclose(db);

   double insert_time_AVL = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[AVL] Insert %d integers: %lf\n", size_of_tree, insert_time_AVL);


   // Query ABP
   int first = 1;
   int middle = size_of_tree/2;
   start = clock();
   tmp = consultaABP(ABP, first)->info;
   end = clock();
   double search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Query First: %lf\n", search_time);
   start = clock();
   tmp = consultaABP(ABP, middle)->info;
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Query Middle: %lf\n", search_time);
   start = clock();
   tmp = consultaABP(ABP, size_of_tree)->info;
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Query Last: %lf\n", search_time);

   // Query AVL
   double sum = 0;
   for (int i = 0; i < AVL_PRECISION; i++) {
      tmp = (rand() % size_of_tree) + 1;
      start = clock();
      consultaAVL(AVL, tmp);
      end = clock();
      search_time = (double) (end - start) / CLOCKS_PER_SEC;
      sum += search_time;
      printf("[AVL] Query %d: %lf\n", tmp, search_time);
   }
   printf("[AVL] Mean %lf\n", (sum / AVL_PRECISION));

   return 0;
}
