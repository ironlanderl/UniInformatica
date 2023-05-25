#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodolista
{
    int dato;
    struct nodolista *prossimo;
}nodo;

typedef nodo *PTRnodo;

void scandisci_lista(PTRnodo);
int conta_elementi(PTRnodo);
PTRnodo elimina_lista(PTRnodo);
PTRnodo aggiungi_a_lista(PTRnodo);
PTRnodo aggiungi_in_coda(PTRnodo);
PTRnodo aggiungi_in_pos(PTRnodo, int);
PTRnodo elimina_elemento(PTRnodo, int);
int main(int argc, char const *argv[]);