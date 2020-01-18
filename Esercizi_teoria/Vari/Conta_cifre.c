#include<stdio.h>
#include<stdlib.h>

int conta_cifre(int val,int cifre){
  if (val/10==0) {
    return 1;
  }
  return conta_cifre(val/10,cifre+1);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("Le cifre necessarie sono: %d\n",conta_cifre(n));
}
