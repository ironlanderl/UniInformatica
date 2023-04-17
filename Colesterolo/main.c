#include <stdlib.h>
#include <stdio.h>

int getRisk(int age, int cholesterol);

int main()
{
    int eta, colesterolo;
    printf("Inserire l'età: ");
    fflush(stdin);
    scanf("%d", &eta);
    printf("Inserire il colesterolo: ");
    fflush(stdin);
    scanf("%d", &colesterolo);

    int rischio = getRisk(eta, colesterolo);

    printf("Incremento del %d%%.\n", rischio);
}

int getRisk(int age, int cholesterol)
{
    if (age <= 30)
    {
        if (cholesterol > 240)
        {
            return 40;
        }
        else /* <= 240 */
        {
            return 0;
        }
    }
    else /* > 30 */
    {
        if (cholesterol > 240)
        {
            return 70;
        }
        else /* <= 240 */
        {
            return 10;
        }
    }
}