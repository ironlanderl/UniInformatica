#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char filename[100], text[100];
    printf("Inserire nome file (con estensione): ");
    fgets(filename, sizeof(filename), stdin);
    // Rimuovo la nuova linea
    filename[strcspn(filename, "\n")] = '\0';

    // Apro il file
    FILE *f;
    f = fopen(filename, "w");

    // Controllo
    if (f == NULL){
        perror("Errore");
        exit(1);
    }

    // Chiedo la stringa
    printf("Testo da inserire: ");
    fgets(text, sizeof(text), stdin);

    // Scrivo la riga
    fprintf(f, text);
    
    // Chiudo il file
    fclose(f);

    return 0;
}