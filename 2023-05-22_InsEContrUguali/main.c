#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 30

int main(int argc, char const *argv[])
{
    int n = -1; // Numero di numeri
    int *nums; // Array dei numeri
    bool uguali = true; // Di default sono uguali

    // Richiesta dimensione
    while (n < 1 || n > MAX)
    {
        printf("Inserire il valore massimo dell'array (max 30): ");
        scanf("%d", &n);
    }

    nums = (int *)malloc(sizeof(int) * n);
    if (nums == NULL)
    {
        perror("Errore nell'allocare memoria");
        exit(1);
    }

    // Inserimento valori
    for (int i = 0; i < n; i++)
    {
        printf("Inserire il %d° numero: ", i + 1);
        scanf("%d", &nums[i]);
    }

    // Controllo se tutti i numeri sono uguali
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            uguali = false;
            break;
        }
    }

    if (uguali)
    {
        printf("I numeri inseriti sono tutti uguali.\n");
    }
    else
    {
        printf("I numeri inseriti non sono tutti uguali.\n");
    }

    // Libero memoria
    free(nums);
    return 0;
}