#include<stdio.h>
#include<stdlib.h>
int lenght=0;

int somma(int *array, int n){
  if(n==0)
    return 0;
  return array[n-1]+somma(array,n-1);
}

int main(){
  int *array;
  array=(int *)malloc(sizeof(int));
  printf("Inserire la lunghezza dell'array\n");
  scanf("%d", &lenght);
  printf("Inserire i %d valori:\n", lenght);
  for (size_t i = 0; i < lenght; i++) {
    scanf("%d", array+i);
  }

  printf("La somma è: %d\n", somma(array,lenght));
}
