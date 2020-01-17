#include<stdio.h>

int main(){
  int valore;
  printf("Inserire valore in decimale inferiore a 2^10\n");
  scanf("%d", &valore);

  /*Conversione binaria*/
  int resto=0,dividendo=valore,arraybin[10],i=0;

  /*Set dell adrray con valori 2*/
  for (i = 0; i < 10; i++) {
    arraybin[i]=-1;
  }
  i=0;

  /*Applicazione metodo dei resti in base 2*/
  while (dividendo>0){
    resto = dividendo%2;
    dividendo=dividendo/2;
    arraybin[9-i]=resto;
    i++;
  }

  /*Stampa risultati*/
  printf("Il valore binario: ");
    for (i = 0; i < 10; i++) {
      if (arraybin[i]!=-1)
        printf("%d", arraybin[i]);
  }
  printf("\n");


    /*Applicazione metodo dei resti in base 8*/
  dividendo=valore;
  resto=0;
  for (i = 0; i < 10; i++) {
    arraybin[i]=-1;
    /* code */
  }
  i=0;

  while (dividendo>0){
    resto = dividendo%8;
    dividendo=dividendo/8;
    arraybin[9-i]=resto;
    i++;
  }

  /*Stampa risultati*/
  printf("Il valore ottale: ");
    for (i = 0; i < 10; i++) {
      if (arraybin[i]!=-1)
        printf("%d", arraybin[i]);
      }
    printf("\n");
return 0;
}
