// N numeri positivi
// Calcolo media
// Fermo con negativo, uso break

#include <stdio.h>
#include <stdbool.h>

int main(){
    int numero, count = 0, media = 0;
    while (true)
    {
        printf("Inserire un numero positivo, o negativo per interrompere: ");
        scanf("%d", &numero);
        if (numero < 0) break;
        media += numero;
        count++;
    }
    // inseriti tutti i numeri, calcolo e stampo la media
    media /= count;
    printf("La media di tutti i numeri inseriti è: %d\n", media);
}