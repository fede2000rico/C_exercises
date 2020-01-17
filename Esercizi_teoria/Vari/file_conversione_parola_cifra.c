/*  Programma nel quale viene letto in input un file con il seguente formato:
    uno due tre ***
    uno uno ***
    restituisce di ritorno un file con:
    123
    11
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int somma(char *nomefile);
int conversione(char * cifra);

int main(int argc,char * argv[]){
  int ris;
  if (argc!=2)
    printf("Manca il percorso del file\n");
  else{
    ris=somma(argv[1]);
    if (ris==-1)
      printf("Il file non è stato aperto correttamente\n");
    else
      printf("La somma è: %d\n", ris);
  }
  return 0;
}

int somma(char * nomefile){
  int somma=0,num;
  char cifra[8];
  FILE * fp;
  fp=fopen(nomefile,"r");
  if (fp==NULL)
    return -1;
  while (fscanf(fp,"%s",cifra)!=EOF){
    num =0;
    while (strcmp(cifra,"***")){
      if(conversione(cifra)!=-1){
        num=num*10 + conversione(cifra);
        fscanf(fp,"%s",cifra);
      }
    }
    somma+=num;
  }
  fclose(fp);
  return somma;
}

int conversione(char * cifra){
  int k;
  const char *numeri[] = {"zero", "uno", "due", "tre", "quattro", "cinque", "sei" ,"sette", "otto", "nove"};

  for (k = 0; k < 10; k++) {
    if ((int)cifra[0]==(int)numeri[k][0]) {
      if(!strcmp(numeri[k],cifra))
        return k;
    }
  }
  return -1;
}
