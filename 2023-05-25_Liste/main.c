#include "main.h"

int main(int argc, char const *argv[])
{

    int scelta, dato1;
    PTRnodo ptesta = NULL;
    do
    {
        printf("1: Aggiunta di un elemento in testa.\n");
        printf("2: Aggiunta di un elemento in coda.\n");
        printf("3: Aggiunta di un elemento in posizione.\n");
        printf("4: Visualizzazione della lista\n");
        printf("5: Eliminazione di un elemento\n");
        printf("6: Eliminazione della lista\n");
        printf("7: Conta elementi.\n");
        printf("0: Termine elaborazioni\n");
        printf("digitare la scelta %cda 0 a 7&%c\n", 40, 41);
        scanf("%d", &scelta);
        system("clear");
        switch (scelta)
        {
            case 0:
                elimina_lista(ptesta);
                break;
            case 1:
                ptesta = aggiungi_a_lista(ptesta);
                break;
            case 2:
                ptesta = aggiungi_in_coda(ptesta);
                break;
            case 4:
                if (ptesta != NULL)
                    scandisci_lista(ptesta);
                break;
        }

    } while (scelta != 0);
    return 0;
}

void scandisci_lista(PTRnodo node)
{
    if (node == NULL)
        return;
    printf("Elemento: %d\n", node->dato);
    scandisci_lista(node->prossimo);
}

int conta_elementi(PTRnodo node)
{
    int counter = 0;
    while (node != NULL)
    {
        counter++;
        node = node->prossimo;
    }
    return counter;
}

PTRnodo elimina_lista(PTRnodo node)
{
    if (node == NULL)
        return NULL;
    PTRnodo a = node->prossimo;
    free(node);
    return elimina_lista(a);
}

PTRnodo aggiungi_a_lista(PTRnodo node)
{
    int tmp;
    PTRnodo nuovo = (PTRnodo)malloc(sizeof(nodo));
    if (nuovo == NULL)
    {
        perror("Errore");
        exit(1);
    }
    printf("Inserire valore in testa: ");
    scanf("%d", &tmp);
    nuovo->dato = tmp;
    nuovo->prossimo = node;
    return nuovo;
}

PTRnodo aggiungi_in_coda(PTRnodo node)
{
    int tmp;
    PTRnodo ultimo;
    PTRnodo nuovo = (nodo *)malloc(sizeof(nodo));
    if (nuovo == NULL)
    {
        perror("Errore");
        exit(1);
    }
    printf("Inserire valore in coda: ");
    scanf("%d", &tmp);
    ultimo = node;
    nuovo->dato = tmp;
    nuovo->prossimo = NULL;
    if (node == NULL)
        node = nuovo;
    else
    {
        while (ultimo->prossimo != NULL)
        {
            ultimo = ultimo->prossimo;
        }
        ultimo->prossimo = nuovo;
    }
    return node;
}

PTRnodo aggiungi_in_pos(PTRnodo node, int index)
{
    int tmp;
    PTRnodo nuovo = (PTRnodo)malloc(sizeof(nodo));
    PTRnodo precedente = (PTRnodo)malloc(sizeof(nodo));
    PTRnodo successivo = (PTRnodo)malloc(sizeof(nodo));
    int n_elementi = conta_elementi(node);
    if (nuovo == NULL || precedente == NULL || successivo != NULL)
    {
        perror("Errore");
        exit(1);
    }

    if (n_elementi < index)
    {
        printf("no");
        return node;
    }

    if (index == 0)
    { // Aggiungo direttamente in cima
        node = aggiungi_a_lista(node);
    }
    else
    {
        // Scorro per arrivare alla posizione
        // Prima di tutto copio il puntatore del nodo per non effettuare operazioni distruttive.
        precedente = node;
        for (int i = 0; i < index; i++)
        {
            precedente = precedente->prossimo;
        }
        // Estraggo anche il successivo
        successivo = precedente->prossimo;
        // Prendo il dato
        printf("Inserire valore in coda: ");
        scanf("%d", &tmp);
        nuovo->dato = tmp;
        nuovo->prossimo = NULL;
        // Imposto il nuovo dato come successivo del precedente
        precedente->prossimo = nuovo;
        // Imposro il successivo del nuovo dato
        nuovo->prossimo = successivo;
    }
    return node;
}

PTRnodo elimina_elemento(PTRnodo node, int index)
{
    PTRnodo delete;
    PTRnodo precedente = (PTRnodo)malloc(sizeof(nodo));
    PTRnodo successivo = (PTRnodo)malloc(sizeof(nodo));
    int n_elementi = conta_elementi(node);
    if (precedente == NULL || successivo != NULL)
    {
        perror("Errore");
        exit(1);
    }

    if (n_elementi < index)
    {
        printf("no");
        return node;
    }

    if (index == 0)
    { 
        // Prendo il prossimo elemento
        successivo = node->prossimo;
        // Libero node (?)
        free(node);
        // Ritorno successivo, che contiene il resto della lista.
        return successivo;
    }
    else
    {
        // Scorro per arrivare alla posizione
        // Prima di tutto copio il puntatore del nodo per non effettuare operazioni distruttive.
        precedente = node;
        for (int i = 0; i < index; i++)
        {
            precedente = precedente->prossimo;
        }
        // Il prossimo nodo è quello da eliminare
        delete = precedente->prossimo;
        // Prendo anche il nodo dopo quello da eliminare
        successivo = delete->prossimo;
        // Libero delete
        free(delete);
        // Imposto il nodo successivo
        precedente->prossimo = successivo;
    }
    return node;
}