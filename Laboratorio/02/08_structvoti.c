#include<stdio.h>

int main(){
  typedef struct{
    char *nome;
    char *docente;
    int cfu;
    int voto;
  } Esame;
  Esame dati;
  printf("Inserire: Nome Docente CFU Voto\n");
  scanf("%s %s %d %d\n", dati.nome, dati.docente, &dati.cfu, &dati.voto);
  printf("%s %s %d %d\n", dati.nome, dati.docente, dati.cfu, dati.voto);
}
