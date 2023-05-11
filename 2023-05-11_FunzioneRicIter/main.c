#include <stdio.h>
#include <stdlib.h>

#define N1 10
#define N2 5

double ricorsiva(double a, int n);
double iterativa(double a, int n);

int main(int argc, char const *argv[])
{
    printf("Ris iter: %lf\n", iterativa(N1, N2));
    printf("Ris rico: %lf\n", ricorsiva(N1, N2));
    return 0;
}

double ricorsiva(double a, int n)
{
    if (n == 1)
        return a - (1 / a);
    else
        return a - (n / a) + ricorsiva(a, n - 1);
}

double iterativa(double a, int n)
{
    double somma = 0;
    int i = 1;
    while (i <= n)
    {
        somma += (a - (i / a));
        i++;
    }

    return somma;
}
