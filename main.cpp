/*!
 * USAGE: ./tree-benchmark [input_db] [output-file]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "abp.h"
#include "avl.h"

#define AVL_PRECISION 50

void progressBar(int progress, int total) {
    int barWidth = 69; // Largura da barra de progresso
    float percent = (float)progress / (float)total;
    int progressWidth = (int)(percent * barWidth);

    printf("[");
    for (int i = 0; i < progressWidth; i++) {
        printf("=");
    }
    for (int i = progressWidth; i < barWidth; i++) {
        printf(" ");
    }
    printf("] %d%%\r", (int)(percent * 100));
    fflush(stdout);
}


int main(int argc, char **argv) {

   // Set RNG seed
   srand(time(0));

   // Get size of tree
   char buff[1024];
   int size_of_tree = 0;
   FILE * db = fopen(argv[1], "r");
   while(fgets(buff, sizeof(buff), db) != NULL) {
      size_of_tree++;
   }
   fclose(db);

   // Output file
   FILE * out = fopen(argv[2], "w");
   fprintf(out, "size,abp_insert,avl_insert,abp_fqe,abp_mqe,abp_lqe,avl_fqe,avl_mqe,avl_lqe,abp_rand_mean,avl_rand_mean\n");
   fprintf(out, "%d,", size_of_tree);

   // Create tree
   pABP *ABP = NULL;
   pAVL *AVL = NULL;


   // Insert ABP
   int counter = 0;
   printf("Inserting ABP...\n");
   db = fopen(argv[1], "r");
   clock_t start = clock();
      int tmp;
      while(fgets(buff, sizeof(buff), db) != NULL) {
         tmp = atoi(buff);
         ABP = InsereArvore(ABP, tmp);
         progressBar(counter, size_of_tree);
         counter++;
      }
   clock_t end = clock();
   fclose(db);
   double insert_time_ABP = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Insert %d integers: %lf\n", size_of_tree, insert_time_ABP);
   fprintf(out, "%.10f,", insert_time_ABP);

   // Insert AVL
   counter = 0;
   printf("Inserting AVL...\n");
   db = fopen(argv[1], "r");
   start = clock();
      while(fgets(buff, sizeof(buff), db) != NULL) {
         tmp = atoi(buff);
         AVL = InsereAVL(AVL, tmp);
         progressBar(counter, size_of_tree);
         counter++;
      }
   end = clock();
   fclose(db);
   double insert_time_AVL = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[AVL] Insert %d integers: %lf\n", size_of_tree, insert_time_AVL);
   fprintf(out, "%.10f,", insert_time_AVL);


   printf("Query extremities...\n");
   // Query First, Middle, Last
   // ABP
   int first = 1;
   int middle = size_of_tree/2;
   start = clock();
      consultaABP(ABP, first);
   end = clock();
   double search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Query First: %lf\n", search_time);
   fprintf(out, "%.10f,", search_time);
   start = clock();
      consultaABP(ABP, middle);
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Query Middle: %lf\n", search_time);
   fprintf(out, "%.10f,", search_time);
   start = clock();
      consultaABP(ABP, size_of_tree);
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[ABP] Query Last: %lf\n", search_time);
   fprintf(out, "%.10f,", search_time);

   // AVL
   start = clock();
      consultaAVL(AVL, first);
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[AVL] Query First: %lf\n", search_time);
   fprintf(out, "%.10f,", search_time);
   start = clock();
      consultaAVL(AVL, middle);
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[AVL] Query Middle: %lf\n", search_time);
   fprintf(out, "%.10f,", search_time);
   start = clock();
      consultaAVL(AVL, size_of_tree);
   end = clock();
   search_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("[AVL] Query Last: %lf\n", search_time);
   fprintf(out, "%.10f,", search_time);


   printf("Querying random...\n");
   // Query Random
   // ABP
   double sum = 0;
   for (int i = 0; i < AVL_PRECISION; i++) {
      tmp = (rand() % size_of_tree) + 1;
      start = clock();
         consultaABP(ABP, tmp);
      end = clock();
      search_time = (double) (end - start) / CLOCKS_PER_SEC;
      sum += search_time;
      // printf("[ABP] Query %d: %lf\n", tmp, search_time);
   }
   printf("[ABP] %d Mean %.10lf\n", AVL_PRECISION, (sum / AVL_PRECISION));
   fprintf(out, "%.10f,", (sum / AVL_PRECISION));
   // AVL
   sum = 0;
   for (int i = 0; i < AVL_PRECISION; i++) {
      tmp = (rand() % size_of_tree) + 1;
      start = clock();
         consultaAVL(AVL, tmp);
      end = clock();
      search_time = (double) (end - start) / CLOCKS_PER_SEC;
      sum += search_time;
      // printf("[AVL] Query %d: %lf\n", tmp, search_time);
   }
   printf("[AVL] %d Mean %.10lf\n", AVL_PRECISION, (sum / AVL_PRECISION));
   fprintf(out, "%.10f", (sum / AVL_PRECISION));


   // Close output file
   fclose(out);

   return 0;
}
