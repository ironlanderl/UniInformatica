#include <stdio.h>
#include <stdlib.h>

int somma(int finoA);

int main(int argc, char const *argv[])
{
    int res;
    int tmp;

    printf("Inserire fino a quale numero sommare: ");
    scanf("%d", tmp);
    res = somma(tmp);
    printf("La somma è: %d", res);
    return 0;
}

int somma(int finoA){
    if (finoA == 1)
        return 1;
    else
    {
        return somma(finoA - 1) + finoA;
    }
    
}
