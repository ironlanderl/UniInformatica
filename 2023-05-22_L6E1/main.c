#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n = -1; // Numero di numeri
    int *nums;  // Array dei numeri

    // Richiesta dimensione
    while (n < 1)
    {
        printf("Inserire la dimensione dell'array: ");
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

    // 1° Shift, a sinistra
    for (int i = 0; i < n - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    nums[n - 1] = 0;

    // Stampo dopo il primo shift
    printf("\nVettore dopo shift a sx:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d° elemento: %d\n", i + 1, nums[i]);
    }

    // 2° Shift, a destra
    for (int i = n - 1; i > 0; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[0] = 0;

    // Stampo dopo il secondo shift
    printf("\nVettore dopo shift a dx:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d° elemento: %d\n", i + 1, nums[i]);
    }

    // Libero memoria
    free(nums);
    return 0;
}