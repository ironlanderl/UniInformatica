#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double risolvi(double a, double b);

int main(int argc, char const *argv[])
{
    double a,b,x;
    printf("Inserire il valore di 'a' e 'b' separati da uno spazio per la seguente equazione: ax+b=0: ");
    scanf("%lf%lf", &a, &b);
    x = risolvi(a,b);
    printf("'x' è uguale a: %lf\n", x);
    return 0;
}

double risolvi(double a, double b){
    if (a == 0.0 && b == 0.0){
        printf("Risposta indeterminata\n");
        return NAN;
    }
    if (a == 0.0 && b != 0.0){
        printf("Risposta non esistente\n");
        return NAN;
    }
    return (-b)/a;
}
