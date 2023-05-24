#include <stdio.h>
#include <stdlib.h>

int ricercadicotomica(int a[], int n, int sx, int dx);

int main(int argc, char const *argv[])
{
    int a[] = {1,3,4,6,7,8,10,13,14};
    int n = 2;
    int sx = 0;
    int dx = 8;
    printf("Numero a pos %d\n", ricercadicotomica(a, n, sx, dx));
    return 0;
}

int ricercadicotomica(int a[], int n, int sx, int dx){
    while (sx != dx)
    {
        if (n < a[dx])
        {
            dx--;
        }
        if (n > a[sx]){
            sx++;
        }
        if (n == a[sx] || n == a[dx]){
            return n == a[sx] ? sx : dx;
        }
    }
    return -1;
    
}
