#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fp;
    int vet[40], i, n;
    if ((fp = fopen("numeri.dat", "rb")) == NULL){
        fprintf(stderr, "Errore");
        exit(1); /* Errore di apertura */
    }
    n = fread(vet, sizeof(int), 40, fp);
    for (i = 0; i < n; i++)
        printf("%d ", vet[i]);
    fclose(fp);
}