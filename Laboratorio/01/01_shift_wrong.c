#include<stdio.h>

int main(){
  int a,b,c,Array[3];
  printf("Inserire valore di a: \n");
  scanf("%d", &Array[0]);

  printf("Inserire valore di b: \n");
  scanf("%d", &Array[1]);

  printf("Inserire valore di c: \n");
  scanf("%d", &Array[2]);

  /*Adesso faccio lo shift*/
  a=Array[1];
  b=Array[2];
  c=Array[0];

  printf("Il valore di a è: %d\n", a);
  printf("Il valore di b è: %d\n", b);
  printf("Il valore di c è: %d\n", c);
  return 0;
}
