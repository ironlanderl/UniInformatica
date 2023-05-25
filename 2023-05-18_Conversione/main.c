#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool converti(int numero, int n_bits, bool *bits);

int main(int argc, char const *argv[])
{
    int num = 7;
    int nbits = 2;
    bool *bits = (bool *)malloc(nbits * sizeof(bool));
    if (converti(num, nbits, bits))
    {
        printf("Il numero convertito è: ");
        for (int i = 0; i < nbits; i++)
        {
            printf("%d", bits[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Non è possibile convertire con i bit dati\n");
    }

    return 0;
}

bool converti(int numero, int n_bits, bool *bits)
{
    while (numero != 0)
    {
        // Se ho finito i bit ma il numero non è ancora zero
        if (n_bits == 0 && numero != 0)
        {
            return false;
        }

        bits[--n_bits] = numero % 2;

        numero = numero / 2;
    }
    return true;
}
