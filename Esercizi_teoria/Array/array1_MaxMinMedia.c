#include<stdio.h>
#define LENGHT 10

int main(){
  int array[LENGHT],Max=0,Min=0,i;
  float Media=0.0;
  for (i=0;i<LENGHT;i++){
    printf("Inserire il valore %d:\n", i+1);
    scanf("%d",&array[i]);
    if (i==0){
      Max=Min=array[i];
    }
    else{
      if (array[i]>Max){
        Max=array[i];
      }
      else {
        if (array[i]<Min){
          Min=array[i];
        }
      }
    }
    Media+=array[i];
  }

  printf("Max: %d\nMin: %d\nMedia: %f\n",Max,Min,Media/(float)LENGHT);
  return 0;
}
