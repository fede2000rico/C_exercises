#include<stdio.h>
int main(){
  int N1,N2,D1,D2,N3,D3;
  /*int array1[2],array2[2],array3[2];*/
  printf("Inserire la prima frazione (formato _/_)\n");
  scanf("%d/%d", &N1, &D1);
  
  printf("Inserire la seconda frazione (formato _/_)\n");
  scanf("%d/%d", &N2, &D2);

  D3=D1*D2;
  N3=((D3/D1)*N1)+((D3/D2)*N2);

  printf("Il risultato è: %d/%d\n", N3,D3);
  return 0;
}
