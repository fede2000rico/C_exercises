#include <stdio.h>
#include<stdlib.h>

#define N 9

int sudoku_corretto[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,6,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,9,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,3,1,7,4,9,2,5,8},{4,9,2,8,5,6,1,3,7}};
int sudoku_sbagliato[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,1,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,4,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,8,1,7,4,9,2,5,8},{4,9,2,8,5,2,1,3,7}};

int colonne(int *matrix);
int righe(int *matrix);
int blocchi(int *matrix);
int compare_array(int *array, int n);
void print_array(int *array);
void print_matrix(int *matrix);


int main() {
  int *mat=NULL;

  mat=&sudoku_corretto[0][0];


  if(!colonne(mat) || !righe(mat) || !blocchi(mat))
    printf("La matrice non è un sudoku!\n");
  else
    printf("La matrice è un sudoku!\n");
	return 0;
}


int blocchi(int *matrix){
  int status=1;
  int *array = calloc(N,sizeof(int));

  for (size_t j = 0; j < 3; j++) {
    for (size_t k = 0; k < 3 && status; k++) {
      for (size_t i = 0; i < 3; i++) {
        for (size_t h = 0; h < 3; h++) {
          array[(3*i)+h]=*(matrix+9*i+h+3*k+27*j);
        }
      }
      status=compare_array(array,0);
      print_array(array);
    }
  }
  if(status)
    return 1;
  else{
    printf("\n0\n");
    return 0;
  }
}

int colonne(int *matrix){
  int status=1,k;
  int *array = calloc(N,sizeof(int));

  for (k = 0; k < N && status; k++) {
    for (size_t j = 0; j < N; j++) {
      array[j]=*(matrix+(9*j)+k);
    }
    status=compare_array(array,0);
    print_array(array);
  }
  if(status)
    return 1;
  else{
    printf("\n0\n");
    return 0;
  }
}


int righe(int *matrix){
  int status=1,k;
  int *array = calloc(N,sizeof(int));

  for (k = 0; k < N && status; k++) {
    array=matrix+(9*k);
    status=compare_array(array,0);
    print_array(array);
  }
  if(status)
    return 1;
  else{
    printf("\n0\n");
    return 0;
  }
}

int compare_array(int *array, int n){
  if (n==9)
    return 1;
  else
    for (size_t i = n+1; i < 9; i++) {
      if (array[n]==array[i]){
        return 0;
      }
    }
  compare_array(array,n+1);
  }


void print_array(int *array){
  for (size_t i = 0; i < N; i++) {
    printf("%5d", array[i]);
  }
  printf("\n");
}


void print_matrix(int *matrix){
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      printf("%5d", *(matrix +j));
    }
    printf("\n");
    matrix+=9;
  }
  printf("\n");
}
