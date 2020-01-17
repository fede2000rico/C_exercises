#include<stdio.h>
#include<math.h>
#define N 50

int main(){
  int array[N];

  /*Inizializzo array*/
  for (size_t i = 0; i < N; i++) {
    array[i]=i+1;
  }

  /*Ciclo su ogli elemento e "setaccio"*/
  for (size_t i = 2; i <= sqrt(N); i++) {
    if(array[i]!=0){
      for (size_t k = 0; k < N; k++) {
        if((array[k]%array[i])==0){
          array[k]=0;
        }
      }
    }
  }

  printf("I numeri primi (fino a %d) sono:\n", N);
  for (size_t j = 0; j < N; j++) {
    if(array[j]!=0){
      printf("%d\n", array[j]);
    }
  }

}
