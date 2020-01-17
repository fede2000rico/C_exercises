#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
  int n = atoi(argv[1]);
  printf("Inserire %d valori\n", n);
  int *array = calloc(n,sizeof(int));
  for (size_t i = 0; i < n; i++) {
    scanf("%d", array+i);
  }

  for (size_t i = 0; i < n; i++) {
    printf("%d", *(array+i));
  }
}
