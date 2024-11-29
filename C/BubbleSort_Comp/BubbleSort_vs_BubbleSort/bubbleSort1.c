#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 2000000

int ix = 0;

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
    int scambiato = 1;
    int indiceUltimoScambio = N - 1;
    int indiceScambio = 0;
    int cont = 0;
    
    while (scambiato) {
        scambiato = 0;
        for (int i = 0; i < indiceUltimoScambio; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                scambiato = 1;
                indiceScambio = i + 1;
            }
        }
        indiceUltimoScambio = indiceScambio;
        cont++; // conto dei cicli while
                printf("%d\n", ix++);

    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo impiegato per l'ordinamento: %f secondi\n\nCicli: %d", cpu_time_used, cont);

    free(v);
    return 0;
}


// WINNER