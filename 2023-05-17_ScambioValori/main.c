#include <stdlib.h>
#include <stdio.h>

void scambia_valori(int* a, int* b);

int main(int argc, char const *argv[])
{
    int a,b;
    printf("Inserire il valore di 'a' e 'b' separati da uno spazio per scambiarli: ");
    scanf("%d%d", &a, &b);
    scambia_valori(&a, &b);
    printf("I nuovi valori sono:\n'a' = %d\n'b' = %d\n", a, b);
    return 0;
}

void scambia_valori(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
