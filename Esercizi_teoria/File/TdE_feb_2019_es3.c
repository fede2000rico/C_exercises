//Analizza i numeri letti da file e dice la cifra con piu ripetizioni
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *output;

void read_print(int n){
  //Setup del file scrittura
  FILE *fp;
  fp=fopen(output,"w");

  //Definizione array contacifre
  int cifre[10]={0},max=0;

  //Conta e incrementa l'array
  while(n/10==0){
    cifre[n%10]++;
    n=n/10;
  }

  //Ricava la posizione della cifra con piu ripetizioni
  for(size_t i=0;i<10;i++){
    if(cifre[i]>=max){
      max=i;
    }
  }
  //Scrive su file
  fprintf(fp,"Cifra: %d | Ripetizioni: %d",max,cifra[max]);
}

int main(int argc, char *argv[]){
  //Definizioni varie
  int val;
  if(argc!=3){
    printf("Parametri mancanti");
  }
  //Setto la variabile con il nome del file di output
  strcpy(output,argv[2]);

  //Apertura file in lettura
  FILE *fr;
  fr=fopen(argv[1],"r")

  //Legge tutti gli interi
  while(!feof(fp)){
    fscanf(fr,"%d",&val);

    //Lancio la funzione per ogni intero
    read_print(val);
  }
}
