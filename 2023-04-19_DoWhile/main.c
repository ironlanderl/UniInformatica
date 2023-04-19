#include <stdio.h>

#define MAX 50
#define MIN 10

int main(){
    int numero;
    do
    {
        printf("Inserire un numero tra %d e %d: ", MIN, MAX);
        scanf("%d", &numero);
    } while (numero < MIN || numero > MAX);
    printf("Hai inserito: %d\n", numero);    
}