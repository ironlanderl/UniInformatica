#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHARS 30

typedef struct studentelista{
    char cognome[30];
    int eta;
    float media;
    struct studentelista *prossimo;
}studente;

typedef studente* PTRStudente;