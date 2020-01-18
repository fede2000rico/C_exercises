//Calcola il minimo di un array
#include<stdio.h>
#define N 10

//Definizione array default
int array[N]={0,1,2,3,4,5,6,7,8,9};

int min(int array,int min,int k){
  //Caso base
  if (k==N) {
    return min;
  }
  //Caso aggiorno minimo
  if (array[k]<min) {
    min=array[k];
  }
  //Evoluzione ricorsione
  return min(array,min,k);
}

int main(){
  printf("Il minimo è: %d\n", min(array,0,0));
}
