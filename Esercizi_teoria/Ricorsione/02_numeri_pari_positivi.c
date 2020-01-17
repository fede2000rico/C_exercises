#include<stdio.h>

int somme(int val){
  int static somma=0;
  if(val==2)
    somma+=2;
  else{
    if (val%2==0)
      somma+=val;
    somme(val-1);
  }
  return somma;
}

int main(){
  int val;
  printf("Inserire il valore:\n");
  scanf("%d", &val);
  printf("La somma dei numeri pari fino a %d è: %d\n", val,somme(val));
}
