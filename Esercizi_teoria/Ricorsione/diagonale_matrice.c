#include<stdio.h>
#define N 4

int mat_ok[N][N]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int mat_err[N][N]={{1,0,0,0},{0,1,0,0},{0,0,2,0},{0,0,0,1}};

int check(int mat[N][N], int j,int val){
  val = mat_ok[0][0];
  if (j==N-1 && mat[j][j]==val) {
    return 1;
  }
  if (mat[j][j]!=val) {
    return 0;
  }
  return check(mat,j+1,val);
}

int main(){
  printf("result %d\n", check(mat_ok,0,0));
}
