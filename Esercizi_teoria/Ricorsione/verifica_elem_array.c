//Programma che verifica ricorsivamente se un elemento è all'interno di un array
#include<stdio.h>
#define N 10

//Definizione array default
int array[N]={0,1,2,3,4,5,6,7,8,9};

int verify(int *array, int val, int k){
  //Caso base
  if (array[k]==val && k==N) {
    return 1;
  }
  //Caso termine array
  else if (k==N) {
    return 0;
  }
  //Evoluzione ricorsione
  return verify(array,val,k+1);
}

int main(){
  printf("Inserire numero da 0 a 9:\n");
  int val;
  scanf("%d", &val);
  printf("Result:\n", verify(array,val,0));
}
