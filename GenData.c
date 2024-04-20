
#include <stdio.h>
#include <stdlib.h>

void printData(int col) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", rand() % 1000 + 1);
    }
    printf("\n");
  }
}

/* void genData(int col) { */
/*   int **M = malloc(25 * sizeof(int *)); */
/*   int data = 0; */
/*   for (int i = 0; i < 25; i++) { */
/*     M[i] = malloc(col * sizeof(int)); */
/*     for (int j = 0; j < col; j++) { */
/*       M[i][j] = rand() % 1000 + 1; */
/*       data++; */
/*     } */
/*   } */
/*   printData(M, col); */
/* } */

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Enviar un argumento ./[app] [argument] \n");
    exit(1);
  }
  int n = atoi(argv[1]);
  for (; n > 0; n -= 10) {
    printData(n);
  }
  /* printData(n); */
  /* genData(n); */
  /* printf("%s", argv[1]); */
  return 0;
}
