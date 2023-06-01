#include "studente.h"

void cerca_studente(char* cognome){
    FILE *f;
    f = fopen("studenti.dat", "r");
    if (f == NULL){
        perror("Errore:");
        exit(1);
    }
    studente s;
    while (!feof(f))
    {
        fscanf(f, "%s\t%d\t%f", s.cognome, &s.eta, &s.media);
        if (strcmp(s.cognome, cognome) == 0){
            printf("Media di %s: %f\n", s.cognome, s.media);
            return;
        }
    }
    printf("Non trovato\n");
}

int main(int argc, char const *argv[])
{
    char* cognome = "ASAF";
    cerca_studente(cognome);
    return 0;
}
