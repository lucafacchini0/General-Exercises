#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 200000

int ix = 0;

void quick_sort_ricorsivo(int array[], int basso, int alto) {
    if (basso < alto) {
        int pivot = array[alto];  // Scelta del pivot (ultimo elemento)
        int i = (basso - 1);  // Indice dell'elemento più piccolo
        for (int j = basso; j < alto; j++) {
            // Se l'elemento corrente è minore del pivot
            if (array[j] < pivot) {
                i++;
                // Scambia array[i] e array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // Scambia il pivot con l'elemento successivo a i
        int temp = array[i + 1];
        array[i + 1] = array[alto];
        array[alto] = temp;
        int pi = i + 1;  // Nuova posizione del pivot
        // Chiamate ricorsive per le due sotto-sequenze
        printf("%d\n", ix++);
        quick_sort_ricorsivo(array, basso, pi - 1);
        quick_sort_ricorsivo(array, pi + 1, alto);
    }
}

int main() {
    srand(time(NULL));
    int *v = (int *)malloc(N * sizeof(int));
    if (v == NULL) {
        printf("Memoria insufficiente\n");
        return 1;
    }

    for(int i = 0; i < N; i++) {
        v[i] = N - i;
    }
    printf("Vettore caricato.\n");

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // QuickSort
    quick_sort_ricorsivo(v, 0, N - 1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo impiegato per l'ordinamento: %f secondi\n", cpu_time_used);

    free(v);
    return 0;
}
