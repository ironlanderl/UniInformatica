#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char id[5];
    char domanda[51];
    char risposta[51];
}domanda;


int main(int argc, char const *argv[])
{
    char risposta[51];
    FILE *f;
    char cont[3];
    f = fopen("20220630-02.txt", "r");
    domanda dom;
    while (!feof(f))
    {
        fscanf(f, "%s%50c%s", dom.id, dom.domanda, dom.risposta);
        dom.id[4] = '\0'; dom.domanda[50] = '\0';
        printf("%s: %s\n", dom.id, dom.domanda);
        printf("Risposta (usare '_' al posto degli spazi): ");
        scanf("%s", risposta);
        if (strcmp(risposta, dom.risposta) == 0){
            printf("Bravo!\n");
        }
        else{
            printf("Somaro!\n");
        }
        printf("Vuoi continuare? [si/no]: ");
        scanf("%2s", cont);
        if (strcmp(cont, "si") != 0)
            break;
    }
    

    fclose(f);
    return 0;
}
