#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

/* int len(int *L) { */
/*   int i = 0; */
/*   while (*L) { */
/*     L++; */
/*     i++; */
/*   } */
/*   return i; */
/* } */

void insertionSort(int *L) {
  for (int j = 1; j < MAX_SIZE; j++) {
    int key = L[j];
    int i = j - 1;
    while (i >= 0 && L[i] > key) {
      L[i + 1] = L[i];
      i = i - 1;
    }
    L[i + 1] = key;
  }
}

void avergae(int *L) {}

void timeofSort(int *arr, double *dots, int i) {
  clock_t start, end;
  start = clock();
  insertionSort(arr);
  end = clock();
  dots[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
  int c;
  int arr[MAX_SIZE];
  int cont = 0;
  double dots[25];

  FILE *fp = popen("gnuplot -persistent", "w");

  for (int i = 0; i < 25; i++) {

    while (cont < MAX_SIZE && scanf("%d", &c)) {
      arr[cont++] = c;
    }

    timeofSort(arr, dots, i);
    // Esto solo era para ver si estaba funcionando el ordenamiento
    /* for (int i = 0; i < 10; i++) { */
    /*   printf("%d ", arr[i]); */
    /*   arr[i] = 0; */
    /* } */
    /* printf("\n"); */

    cont = 0;
  }
  fclose(fp);
  return 0;
}
