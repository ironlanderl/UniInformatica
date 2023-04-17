#include <math.h>
#include <stdio.h>

void checkNumbers();
int isPrime(int n);

int main()
{
    checkNumbers();
    return 0;
}

int isPrime(int n)
{
    int max, i;
    if (n >= 1 && n <= 3)
        return 1; // 1,2,3
    if (n % 2 == 0)
        return 0; // numeri pari
    max = sqrt(n);
    for (i = 3; i <= max; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

void checkNumbers()
{
    int numeri[] = {1, 2, 3, 4, 11, 16, 17, 18, 20, 23};
    for (int i = 0; i < sizeof(numeri) / sizeof(int); i++)
    {
        printf("%d: %s\n", numeri[i], isPrime(numeri[i]) ? "Primo" : "Non primo");
    }
}