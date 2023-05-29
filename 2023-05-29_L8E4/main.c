#include "main.h"

int main(int argc, char const *argv[])
{
  // Inserisco studente, file scrittura binaria
  FILE *f = fopen("stud.dat", "wb");
  if (f == NULL)
  {
    perror("Errore");
    exit(1);
  }

  ins_studente(f);

  fclose(f);
  // Riapro il file in lettura
  f = fopen("stud.dat", "rb");
  if (f == NULL)
  {
    perror("Errore");
    exit(1);
  }
  leggi_studente(f);
  fclose(f);
  return 0;
}

void ins_studente(FILE *f)
{
  // Dichiaro un nuovo studente
  studente s;
  // Chiedo matricola, nome, cognome e voto
  printf("Inserire matricola: ");
  scanf("%s", s.matricola);
  printf("Inserire nome: ");
  scanf("%s", s.nome);
  printf("Inserire cognome: ");
  scanf("%s", s.cognome);
  printf("Inserire voto: ");
  scanf("%d", &s.voto);
  // Scrivo lo studente nel file
  fwrite(&s, sizeof(studente), 1, f);
}

void leggi_studente(FILE *f)
{
  studente s;
  // come ins, ma legge
  fread(&s, sizeof(studente), 1, f);
  printf("Matricola: %s\n", s.matricola);
  printf("Nome: %s\n", s.nome);
  printf("Cognome: %s\n", s.cognome);
  printf("Voto: %d\n", s.voto);
}
