#include<stdio.h>
#define N 5
void Ris(int mat1[N][N], int mat2[N][N]);

int main(){
  int mat1[N][N]={0},mat2[N][N]={0},count=0;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      mat1[i][j]=count;
      count++;
    }
  }


  Ris(mat1,mat2);

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      printf("%5d", mat2[i][j]);
    }
    printf("\n");
  }

printf("\n\n");

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      printf("%5d", mat1[i][j]);
    }
    printf("\n");
  }
}



void Ris(int mat1[N][N], int mat2[N][N]){
  int dispari[25]={0},pos=0;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      if(((int)mat1[i][j]%2)==0){
        printf("%5d\n", mat1[i][j]);
        dispari[pos]=mat1[i][j];
        pos++;
      }
    }
  }

  printf("\n\n");

  pos=0;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      mat2[i][j]=dispari[pos];
      pos++;
    }
  }
}
