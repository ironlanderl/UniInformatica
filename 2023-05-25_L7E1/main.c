#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void compress(float *a, float *b, int peace, int n);
void write(float *array, int elementi);

int main()
{
    float a[] = {5.5, 2.5, 4, 6, 7, 5, 12, 10, 2, 4};
    float *b;
    int dim = sizeof(a) / sizeof(float);
    int peace = 4;

    // Dimensione di b
    int b_dim = ceil((float)dim / peace);
    // Alloco b
    b = (float*)malloc(b_dim * sizeof(float));
    if (b == NULL)
    {
        perror("Errore");
        exit(1);
    }

    write(a, dim);
    printf("\nCompressing, peace = %d\n", peace);
    compress(a, b, peace, dim);
    write(b, b_dim);
    free(b);
}

void compress(float *a, float *b, int peace, int n)
{
    int counter = 0;
    float tmp = 0;
    
    // Scorro a
    for (int i = 0; i < n; i++)
    {
        tmp += a[i];
        if ((i+1) % peace == 0) // Eseguito ogni 'peace' valori
        {
            b[counter] = tmp / peace;
            counter++;
            tmp = 0;
        }
    }

    // Se tmp è diverso da zero, sono rimasti numeri vuoti. Forzo il valore di b.
    if (tmp != 0){
        b[counter] = tmp / peace;
    }
    
    
}

void write(float *array, int elementi)
{
    for (int i = 0; i < elementi; i++)
    {
        printf("Elemento %d: %.2f\n", i, array[i]);
    }
    
}
