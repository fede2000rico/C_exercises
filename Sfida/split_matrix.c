#include<stdio.h>
#include<stdlib.h>


int mat_corretta[N][N] = {{4,5,2,3,1},{3,1,4,5,2},{1,2,5,4,3},{5,3,1,2,4},{2,4,3,1,5}};
int mat_sbagliata[N][N] = {{4,2,5,3,1},{3,1,4,5,2},{1,2,5,4,3},{5,3,1,2,4},{2,4,3,1,5}};

void print_array(int *array){
  for (size_t i = 0; i < N; i++) {
    printf("%5d", array[i]);
  }
  printf("\n");
}

int **create_matrix(int n){
  int **matrix;

  matrix=(int**)malloc(sizeof(int*)*n);
  for (size_t i = 0; i < n; i++) {
    matrix[i]=(int*)malloc(sizeof(int)*n);
  }

  matrix[0][0]=mat_corretta[0][0];
  matrix[1][0]=mat_corretta[1][0];
  matrix[0][1]=mat_corretta[0][1];

  return matrix;
}

int *create_external(int n){
  int *array;
  array=malloc(n*4);
  return array;
}

void gestisci_mat(int N,int **matrix,int *array_val){
  int k=0;
  int *array;
  array=(int*)malloc(sizeof(int)*N);
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      array[j]=mat_corretta[j][i];
    }
    vette(array,N,array_val[k]);
    k++;
  }

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      array[j]=mat_corretta[i][N-1-j];
    }
    vette(array,N,array_val[k]);
    k++;
  }

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      array[j]=mat_corretta[N-1-j][N-1-i];
    }
    vette(array,N,array_val[k]);
    k++;
  }

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      array[j]=mat_corretta[N-1-i][j];
    }
    vette(array,N,array_val[k]);
    k++;
  }

}
