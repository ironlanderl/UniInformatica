#include <stdio.h>

int main()
{
    float c = -1;
    printf("Inserire °C: ");
    fflush(stdin);
    scanf("%f", &c);
    
    float f = 32 + c * 9/5;
    
    printf("%.2f °C = %.2f °F", c, f);
    
    return 0;
}
