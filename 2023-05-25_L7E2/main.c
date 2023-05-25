#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void compress(int *a, int *b, int n, int *contatore);
void write(int *array, int elementi);

int main()
{
    int n = 7;
    int a[] = {23,2,0,0,0,2,4};
    int *b;
    int contatore = 0;

    // Dimensiono b come a, uso variabile esterna per tracciare il numero di elementi.
    b = (int *)malloc(n * sizeof(int));
    if (b == NULL)
    {
        perror("Errore");
        exit(1);
    }

    printf("Numeri inseriti:\n");
    write(a, n);
    compress(a, b, n, &contatore);
    printf("Array compresso:\n");
    write(b, contatore);
    free(b);
}

void compress(int *a, int *b, int n, int *contatore)
{
    bool presente = false;
    int start = 0;

    // Primo elemento inserito forzatamente
    // Scorro finchè il primo non sia 0
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0){
            b[0] = a[i];
            (*contatore)++;
            start = i;
            break;
        }
    }
    

    // Scorro a iniziando dal primo elemento inserito
    for (int i = start + 1; i < n; i++)
    {
        //printf("i = %d, contatore = %d", i, *contatore);
        presente = false;
        // Scorro b. Se l'elemento di a appare in qualunque posizione, oppure è zero, salto al prossimo valore.
        // Altrimenti lo inserisco in b ed aumento il contatore.
        for (int j = 0; j < *contatore; j++)
        {
            //printf("a[i]: %d, b[j]: %d", a[i], b[j]);
            
            if (a[i] == 0 || a[i] == b[j])
            {
                presente = true;
                break; // Salto
            }
        }
        if (!presente)
        {
            b[*contatore] = a[i];
            (*contatore)++;
        }
    }
}

void write(int *array, int elementi)
{
    for (int i = 0; i < elementi; i++)
    {
        printf("Elemento %d: %d\n", i, array[i]);
    }
}
