#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int main(){
    float numeri[MAX];
    float tmp;
    int count = 0;
    float media;

    // Chiedo massimo MAX numeri
    while (count < MAX)
    {
        printf("Inserire una temperatura, o \"-1\" per interrompere: ");
        scanf("%f", &tmp);
        if (tmp == -1) break;
        numeri[count] = tmp;
        count++;
    }

    // Calcolo la media
    for (int i = 0; i < count; i++){
        media += numeri[i];
    }
    media /= count;


    printf("La media di tutte le temperature inserite è: %.2f\n", media);
}
