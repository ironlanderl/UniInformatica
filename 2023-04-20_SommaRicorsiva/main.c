#include <stdio.h>

int somma(int numeri);

int main(int argc, char const *argv[])
{
    int desired;
    do
    {
        printf("Inserire fino a quale numero sommare: ");
        scanf("%d", &desired);
    } while (desired <= 0); // Solo numeri positivi
    int num = somma(desired);
    printf("La somma dei primi %d numeri è %d\n", desired, num);
    return 0;
}

int somma(int n)
{
    if (n == 1)
        return 1;
    else
        return somma(n - 1) + n;
}
