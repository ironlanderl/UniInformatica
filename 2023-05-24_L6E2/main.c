#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcola(float valore, float *quad_val, float *cub_val);

int main(int argc, char const *argv[])
{
    float valore, quad, cub;
    printf("Inserire un valore: ");
    scanf("%f", &valore);

    calcola(valore, &quad, &cub);

    printf("Il quadrato è: %f, il cubo è %f\n", quad, cub);
    
    return 0;
}

void calcola(float valore, float *quad_val, float *cub_val)
{
    *quad_val = pow(valore, 2.0);
    *cub_val = pow(valore, 3.0);
}
