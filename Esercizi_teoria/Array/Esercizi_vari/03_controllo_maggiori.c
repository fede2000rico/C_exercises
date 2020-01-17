/*Scrivere una funzione ricorsiva che, avendo in input un array A di N interi, un valore K e parametri a necessità, dia in output 1 se tutti i valori dell'array sono maggiori di K, 0 altrimenti.*/
#include<stdio.h>
#include<stdlib.h>
int lenght=0;
int check_over_array(int *array,int K);

int main(){
  int *array,k;
  array=(int *)malloc(sizeof(int));
  printf("Inserire la lunghezza dell'array\n");
  scanf("%d", &lenght);
  printf("Inserire i %d valori:\n", lenght);
  for (size_t i = 0; i < lenght; i++) {
    scanf("%d", array+i);
  }

  printf("Inserire valore K:\n");
  scanf("%d", &k);
  printf("%d\n", check_over_array(array,k));
}

int check_over_array(int *array,int K){
  while(*array=='\0'){
    if (*array>K) {
      check_over_array(array+1, K);
    }
    else
      return 0;
  }
  return 1;
}
