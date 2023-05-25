#include <stdio.h>
#include <stdlib.h>

void calcolaValoreMedio(const float* A, int N, int P, float* risultati) {
    int i, j;
    float somma;
    int numBlocchi = N / P;

    for (i = 0; i < numBlocchi; i++) {
        somma = 0.0f;
        for (j = 0; j < P; j++) {
            somma += A[i * P + j];
        }
        risultati[i] = somma / P;
    }

    // Se N non è divisibile per P, impostiamo le misurazioni rimanenti a zero
    if (N % P != 0) {
        int resto = N % P;
        somma = 0.0f;
        for (i = numBlocchi * P; i < N; i++) {
            somma += A[i];
        }
        for (i = 0; i < P - resto; i++) {
            somma += 0.0f; // Aggiungiamo misure zero
        }
        risultati[numBlocchi] = somma / P;
    }
}

int main() {
    int N = 10; // Lunghezza dell'array di campioni
    int P = 4;  // Numero di istanti di tempo da considerare per il calcolo del valore medio

    // Esempio di segnale campionato
    float segnaleCampionato[] = {5.5, 2.5, 4, 6, 7, 5, 12, 10, 2, 4};

    // Calcolo del numero di blocchi e dimensione dell'array dei risultati
    int numBlocchi = N / P;
    if (N % P != 0) {
        numBlocchi++;
    }

    // Allocazione dell'array dei risultati
    float* risultati = (float*)malloc(numBlocchi * sizeof(float));

    // Calcolo del valore medio del segnale
    calcolaValoreMedio(segnaleCampionato, N, P, risultati);

    // Stampa dei risultati
    for (int i = 0; i < numBlocchi; i++) {
        printf("Valore medio %d: %.2f\n", i + 1, risultati[i]);
    }

    // Deallocazione dell'array dei risultati
    free(risultati);

    return 0;
}