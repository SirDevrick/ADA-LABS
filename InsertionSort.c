#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000

/* int len(int *L) { */
/*   int i = 0; */
/*   while (*L) { */
/*     L++; */
/*     i++; */
/*   } */
/*   return i; */
/* } */

void insertionSort(int *L, int size) {
  for (int j = 1; j < size; j++) {
    int key = L[j];
    int i = j - 1;
    while (i >= 0 && L[i] > key) {
      L[i + 1] = L[i];
      i = i - 1;
    }
    L[i + 1] = key;
  }
}
void clearDots(double *dots, int size) {

  for (int i = 0; i < size; i++) {
    dots[i] = 0;
  }
};
double average(double *dots, int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += dots[i];
  }
  clearDots(dots, size);
  return sum / MAX_SIZE;
}

void timeofSort(int *arr, double *dots, int i, int size) {
  clock_t start, end;
  start = clock();
  insertionSort(arr, size);
  end = clock();
  dots[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
  int c;
  int arr[MAX_SIZE];
  int cont = 0;
  double dots[25];

  FILE *fp = popen("gnuplot -persistent", "w");

  int allArrays = MAX_SIZE;

  fprintf(fp, "set title 'Gráfico de un Punto'\n");
  fprintf(fp, "plot '-' with lines title 'Punto'\n");
  for (; allArrays > 0; allArrays -= 10) {

    for (int i = 0; i < 25; i++) {

      while (cont < allArrays && scanf("%d", &c)) {
        arr[cont++] = c;
      }

      timeofSort(arr, dots, i, allArrays);
      // Esto solo era para ver si estaba funcionando el ordenamiento
      for (int i = 0; i < allArrays; i++) {
        printf("%d ", arr[i]);
        arr[i] = 0;
      }
      printf("\n");

      cont = 0;
    }

    fprintf(fp, "%lf %lf\n", (double)allArrays, average(dots, allArrays));
  }

  fprintf(fp, "e\n");
  fclose(fp);
  return 0;
}
