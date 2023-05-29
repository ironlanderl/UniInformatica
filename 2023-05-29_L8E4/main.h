#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHARS 100

typedef struct
{
    char matricola[MAXCHARS];
    char nome[MAXCHARS];
    char cognome[MAXCHARS];
    int voto;
}studente;


int main(int argc, char const *argv[]);
void ins_studente(FILE*);
void leggi_studente(FILE*);