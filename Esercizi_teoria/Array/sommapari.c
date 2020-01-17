#include<stdio.h>
#define N 5

int array_original[N]={12,2,15,38,1};

int somma(int array[N],int k, int sum){
  if(k==N-1){
    return sum;
  }
  if(array[k]%2==0 && k<5){
    sum+=array[k];
  }
  return sum+ somma(array,k+1,sum);
}
int main(){
  printf("somma: %d\n", somma(array_original,0,0));
}
