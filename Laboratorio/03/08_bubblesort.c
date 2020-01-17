#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *array, int n);
void print_array(int *array,int n);


int main(int argc,char *argv[]){
  int array[atoi(argv[1])];
  printf("Inserire %d valori\n", atoi(argv[1]));
  for (size_t k = 0; k < atoi(argv[1]); k++) {
    scanf("%d",&array[k]);
  }
  bubblesort(array, atoi(argv[1]));
  print_array(array, atoi(argv[1]));
}

void bubblesort(int *array, int n){
  int swap=0;
  for (size_t h = 0; h <= n; h++) {
    if(*(array+h)>*(array+h+1)){
      swap=*(array+h);
      *(array+h)=*(array+h+1);
      *(array+h+1)=swap;
      h=0;
    }
  }
}
void print_array(int *array,int n){
  for (size_t i = 0; i < n; i++) {
    printf("%5d", array[i]);
  }
  printf("\n");
}
