#include <math.h>
#include <stdio.h>
#include <stdbool.h>

void checkNumbers();
bool isPrime(int n);

int main()
{
    checkNumbers();
    return 0;
}

bool isPrime(int n)
{
    int max, i;
    if (n >= 1 && n <= 3)
        return true; // 1,2,3
    if (n % 2 == 0)
        return false; // numeri pari
    max = sqrt(n);
    for (i = 3; i <= max; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void checkNumbers()
{
    int numeri[] = {1, 2, 3, 4, 11, 16, 17, 18, 20, 23};
    for (int i = 0; i < sizeof(numeri) / sizeof(int); i++)
    {
        printf("%d: %s\n", numeri[i], isPrime(numeri[i]) ? "Primo" : "Non primo");
    }
}