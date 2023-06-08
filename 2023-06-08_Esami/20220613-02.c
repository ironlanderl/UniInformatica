#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char nome[40];
    float prezzo;
    char categoria[40];
}prodotto;


int main(int argc, char const *argv[])
{
    prodotto prod;
    float pMax, pMin;
    char categoria[40];
    FILE *f;
    f = fopen("20220613-02.txt", "r");

    printf("Inserire categoria: ");
    scanf("%s", categoria);

    printf("Inserire prezzo minimo: ");
    scanf("%f", &pMin);

    printf("Inserire prezzo massimo: ");
    scanf("%f", &pMax);



    while (!feof(f))
    {
        fscanf(f, "%s %f %s", prod.nome, &prod.prezzo, prod.categoria);
        // Prima controllo la categoria
        if (strcmp(categoria, prod.categoria) == 0){
            // Prezzo
            if (pMax >= prod.prezzo && pMin <= prod.prezzo){
                // Posso stampare
                printf("%s Prezzo: %.2f\n", prod.nome, prod.prezzo);
            }
        }
    }
    



    fclose(f);

    return 0;
}
