#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char *nome;
  int *matr;
  float *perc;
}studente;

int main(int argc,char *argv[]){
  int n =atoi(argv[1]);
  studente * elenco;
  elenco=calloc(n,sizeof(studente));
  for (size_t i = 0; i < n; i++) {
    printf("Inserisci nome:\n");
    scanf("%s",(elenco+n)->nome);
    printf("Inserisci numero matricola:\n");
    scanf("%d",((elenco+n)->matr));
    printf("Inserisci percentuale:\n");
    scanf("%f",((elenco+n)->perc));
  }
}
