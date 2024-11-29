#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 20000

int main() {
    srand(time(NULL));
    int *v = (int *)malloc(N * sizeof(int));
    if (v == NULL) {
        printf("Memoria insufficiente\n");
        return 1;
    }
    
    for(int i = 0; i < N; i++) {
        v[i] = N-i;
    }
    printf("Vettore caricato.\n");
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    // Bubble sort
    int cont = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-i-1; j++) {
            if (v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
                        cont++;

    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo impiegato per l'ordinamento: %f secondi\n\nCicli: %d", cpu_time_used, cont);

    free(v);
    return 0;
}
