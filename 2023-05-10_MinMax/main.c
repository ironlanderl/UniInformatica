#include <stdio.h>
#include <stdlib.h>

void MaxMin(int nums);
void MaxMinArray(int nums);

int main(int argc, char const *argv[])
{
    int nums = 0;
    while (nums <= 0)
    {
        printf("Inserire quanti numeri da chiedere: ");
        scanf("%d", &nums);
    }

    MaxMinArray(nums);

    return 0;
}

void MaxMin(int nums)
{
    int max = 0;
    int min = 0;
    int tmp = 0;
    for (int i = 0; i < nums; i++)
    {
        printf("Inserire un numero: ");
        scanf("%d", &tmp);

        if (i == 0)
        { // La prima volta imposto entrambi i max e min al primo numero immesso
            max = tmp;
            min = tmp;
        }
        else
        {
            if (tmp > max)
            {
                max = tmp;
            }

            if (tmp < min)
            {
                min = tmp;
            }
        }
    }
    printf("Il numero massimo è %d, il numero minimo è %d\n", max, min);
}

void MaxMinArray(int nums)
{
    int *numbers = malloc(sizeof(int) * nums);

    int max, min;

    for (int i = 0; i < nums; i++)
    {
        printf("Inserire un numero: ");
        scanf("%d", &numbers[i]);
    }

    // Max e Min uguali al primo elemento
    max = numbers[0];
    min = numbers[0];

    for (int i = 0; i < nums; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    printf("Il numero massimo è %d, il numero minimo è %d\n", max, min);
}
