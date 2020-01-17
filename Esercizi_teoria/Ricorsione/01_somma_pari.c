#include<stdio.h>

int serie(int k){
  if(k==1)
    return 2;
  else
    return 2*k+serie(k-1);
}

int main(){
  int num;
  scanf("%d", &num);
  printf("La somma è: %d\n", serie(num));
}
