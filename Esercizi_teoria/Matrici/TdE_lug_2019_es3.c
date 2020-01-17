#include<stdio.h>
#define N 3

int mat_simm[N][N] = {{1,0,0},{0,1,0},{0,0,1}};
int mat_sbag[N][N] = {{1,0,0},{0,1,0},{1,0,1}};

int verify(int mat[N][N],int j,int k){
  if (j==N-1 && k==N-1) return 0;
  if (k==N-1) {
    if (mat[j][k]==mat[k][j]) {
      return verify(mat,j+1,j+1);
    }
    else return 1;
  }
  else{
    if (mat[j][k]!=mat[k][j]) {
      return 1;
    }
  }
  return verify(mat,j,k+1);
}

int main(){
  int j=0,k=0;
  printf("result %d\n", verify(mat_simm,j,k));
}
