#include<stdio.h>

int main(){
  int i,k,j;
  float array[7],media,max,min;
  char string[10];
  for (i = 0; i < 7;i++) {
    printf("Inserire valore temperatura giorno %d: (formato: __,__)\n", i+1);
    scanf("%f", &array[i]);
  }

  printf("%s\t%s\t%s\n", "GIORNO","TEMPERATURA","ISTOGRAMMA");

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 10; j++) {
      string[j]=' ';
    }
    for (k = 0; k < (int)(array[i]-34); k++) {
      string[k]='*';
    }
    printf("%d\t%2.2f\t%-s\n", i+1,array[i],string);
  }
  /*Ricerca massimo e minimo*/
  i=0;
  max=array[i];
  min=array[i];
  while (i<7){
    if (array[i]<min)
      min=array[i];
    if (array[i]>max)
      max=array[i];
    i++;
  }
  for (k = 0; k < 7; k++) {
    media+=array[k];
  }
  printf("La temperatura massima è: %2.2f\n", max);
  printf("La temperatura minima è: %2.2f\n", min);
  printf("La temperatura media è: %2.2f\n", media/7);
}
