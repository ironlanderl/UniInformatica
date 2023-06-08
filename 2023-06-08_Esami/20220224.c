#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int main(int argc, char const *argv[])
{
    bool uguali = true;
    FILE *f;
    char parola[MAX];
    char ricerca[MAX];

    f = fopen("20220224.txt", "r");

    printf("Parola da cercare: ");
    scanf("%s", ricerca);

    while (!feof(f))
    {
        fscanf(f, "%s", parola);

        // Se hanno due lunghezze diverse posso immediatamente saltarla
        if (strlen(parola) != strlen(ricerca)) continue;

        uguali = true; // Default

        for (int i = 0; i < strlen(parola); i++)
        {
            if (parola[i] != ricerca[i] && ricerca[i] != '*'){
                // Lettera diversa, tutta parola diversa
                uguali = false;
                continue;
            }
        }
        // Solo se uguali
        if (uguali)
            printf("%s\n", parola);
    }
    
    fclose(f);
    return 0;
}
