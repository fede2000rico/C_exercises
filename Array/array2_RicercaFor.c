#include<stdio.h>
#define LENGHT 10

int main(){
  int array[LENGHT],Filtro,i,a=0;

  /*Creazione array*/
  for (i=0;i<LENGHT;i++){
    array[i]=i+1;
  }

  /*Utente inserisce valore da cercare*/
  printf("Inserire valore da cercare: \n");
  scanf("%d",&Filtro);
  for (i=0;i<LENGHT;i++){
    if (array[i]==Filtro){
      printf("La posizione è: %d\n",i);
      a=1;
    }
  }
  if (a==0){
      printf("Valore inesistente!\n");
  }
}
