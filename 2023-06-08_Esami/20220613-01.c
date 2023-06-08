#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void ricerca(float *a, float *b, float la, float lb, float **loc_somma, float **loc_media)
{
    // Imposto a null
    *loc_somma = NULL;
    *loc_media = NULL;
    float somma = 0, media = 0;
    for (int i = 0; i < la; i++)
    {
        somma += a[i];
    }
    media = somma / la;

    // Adesso ricerco
    for (int i = 0; i < lb; i++)
    {
        if (b[i] == somma)
        {
            *loc_somma = &b[i];
        }
        if (b[i] == media)
        {
            *loc_media = &b[i];
        }
    }
}

int main()
{
    float a[] = {1, 2, 3, 4};
    float b[] = {5, 34, 10, 2.5};
    float *loc_somma = NULL, *loc_media = NULL;

    ricerca(a, b, 4, 5, &loc_somma, &loc_media);
    printf("Sum location: %p\n", (void *)loc_somma);  // Expected output: 0
    printf("Mean location: %p\n", (void *)loc_media); // Expected output: 2
 
    float c[] = {2, 7};
    float d[] = {9, 7, 3, 10, 6};

    ricerca(c, d, 2, 5, &loc_somma, &loc_media);
    printf("Sum location: %p\n", (void *)loc_somma);  // Expected output: 1
    printf("Mean location: %p\n", (void *)loc_media); // Expected output: 2

    float e[] = {3, 5, 1, 4};
    float f[] = {0};

    ricerca(e, f, 4, 1, &loc_somma, &loc_media);
    printf("Sum location: %p\n", (void *)loc_somma);  // Expected output: 3
    printf("Mean location: %p\n", (void *)loc_media); // Expected output: 2
 
    return 0;
}
