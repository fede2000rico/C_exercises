/*{10,3,4,5,1,2} restituisce 10 e 5, ovvero i valori che i successivi ad essi sono inferiori*/
#include<stdio.h>
#include<stdlib.h>

int lenght=0;

int cerca_vette(int *array, int n, int max){

  if(n==0 || n==1)
    return 0;

  if (array[n-2]>max) {
    return 1 + cerca_vette(array,n-1,max);
  }
  else
    return cerca_vette(array,n-1,max);

}

int main(){
  int *array;
  array=(int *)malloc(sizeof(int));
  printf("Inserire la lunghezza dell'array\n");
  scanf("%d", &lenght);
  printf("Inserire i %d valori:\n", lenght);
  for (size_t i = 0; i < lenght; i++) {
    scanf("%d", array+i);
  }
  printf("Le vette sono: %d\n",cerca_vette(&array[lenght-1],lenght,*(array+lenght)));
}
