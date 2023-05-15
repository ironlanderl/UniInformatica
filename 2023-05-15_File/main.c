#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    //int n;
    char msg[] = "Ah, l'esame\nsi avvicina!\nTab\t\t\tTest\n\nL\nP";
    fp = fopen("/home/ironlanderl/uni/UniInformatica/2023-05-15_File/testo.txt", "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file");
        exit(1); /* Errore di apertura */
    }
    fwrite(msg, 1, strlen(msg), fp);
    fclose(fp);
    return 0;
}