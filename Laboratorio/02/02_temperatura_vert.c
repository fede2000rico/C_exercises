#include<stdio.h>

int main(){
  int i,k,j;
  float array[7],media,max,min,tag[7];

  for (i = 0; i < 7;i++) {
    printf("Inserire valore temperatura giorno %d: (formato: __,__)\n", i+1);
    scanf("%f", &array[i]);
    if (array[i]>44)
      i--;
  }

  for (i = 0; i < 7; i++) {
    tag[i]=array[i]-34;
  }
  for (i = 10; i>0; i--) {
    for (k = 0; k < 7; k++) {
      if (tag[k]==i){
        printf("  *");
        printf("\t");
        tag[k]--;
      }
      else
        printf(" \t");
    }
    printf("\n");
  }
  for (j = 0; j < 7; j++) {
    printf("%2.2f\t", array[j]);
  }
  printf("\n");
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
