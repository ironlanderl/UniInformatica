#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int count = 0;
    double num;
    double somma = 0.0;
    while (true)
    {
        printf("Inserire un numero o 0 per terminare: ");
        scanf("%lf", &num);
        if (num == 0) break;
        somma += num;
        count++;
    }

    if (count == 0){
        printf("Non sono stati inseriti numeri.\n");
        return 0;
    }

    printf("Inseriti %d numeri. La somma è %.3lf. La media inserita è %.3lf\n",count, somma, somma/count);

    return 0;
}