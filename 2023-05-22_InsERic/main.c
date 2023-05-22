#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 30

int main(int argc, char const *argv[])
{
    int n = -1;
    int *nums;
    int req;
    int trovato = false;

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

    // Richiesta
    printf("Inserire il valore da cercare: ");
    scanf("%d", &req);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == req)
        {
            trovato = true;
            break;
        }
    }

    // Stampo posizione se trovata
    printf("Il numero %d%s è stato inserito \n", req, trovato ? "" : " non");

    /*if (trovato)
    {
        printf("Il numero %d è stato inserito \n", req);
    }
    else
    {
        printf("Il numero %d non è stato inserito\n", req);
    }*/

    // Libero memoria
    free(nums);
    return 0;
}