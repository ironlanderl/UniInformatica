#include <stdio.h>
#include <stdlib.h>

int radice(int number);

int main(){
    int numeri[] = {2,4,6,9,11,15,20};
    for (int i = 0; i < sizeof(numeri) / sizeof(int); i++)
    {
        printf("Radice di %d: %d\n", numeri[i], radice(numeri[i]));
    }
    return 0;
}

int radice(int number)
{
    int X;
    for (X = 0; X*X <= number; X++);
    return X-1;
}
