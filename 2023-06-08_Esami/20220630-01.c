#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int nErrori;
    int nBit;
    float durataMedia;
} ritorno;

ritorno correggi(bool *s, int l, int k)
{
    int tmp = 0;
    ritorno ret;
    bool checker = false;

    ret.nErrori = 0;
    ret.nBit = 0;
    ret.durataMedia = 0;

    for (int i = 0; i < l; i++)
    {
        if (s[i])
        {
            tmp++;
            checker = true;
        }
        else
        {
            if (tmp < k && checker)
            {
                ret.nErrori++;
                for (int j = i - 1; j >= (i - tmp); j--)
                {
                    *(s + (sizeof(bool) * j)) = 0;
                    ret.nBit++;
                }
            }
            tmp = 0;
            checker = false;
        }
    }

    float somma = 0.0;
    int counter = 0;

    // Errore risolto, adesso calcolo la durata media
    for (int i = 0; i < l; i++)
    {
        if (s[i])
        {
            somma++;
        }
        else if (!s[i] && s[i - 1])
        {
            counter++;
        }
    }
    ret.durataMedia = somma / counter;

    return ret;
}

int main(int argc, char const *argv[])
{
    bool s[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int k = 5;

    printf("Originale: ");

    for (int i = 0; i < sizeof(s) / sizeof(bool); i++)
    {
        printf("%d", s[i]);
    }

    printf("\n");

    ritorno ret = correggi(s, sizeof(s) / sizeof(bool), k);

    printf("Corretto:  ");

    for (int i = 0; i < sizeof(s) / sizeof(bool); i++)
    {
        printf("%d", s[i]);
    }

    printf("\n");

    printf("nErrori: %d\nnBit cambiati: %d\nMedia: %.2fms\n", ret.nErrori, ret.nBit, ret.durataMedia);

    return 0;
}
