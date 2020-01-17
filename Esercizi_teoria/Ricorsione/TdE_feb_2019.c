#include<stdio.h>
#include<stdlib.h>
#define N 9

int somma_pari(int mat[N][N],int pos,int somma){
  if(pos<9){
    for (size_t j = 0; j < 9; j++) {
      somma+=mat[pos][j];
    }
    return somma_pari(mat,pos+2,somma);
  }
  else return somma;
}
int somma_dispari(int mat[N][N],int pos,int somma){
  if(pos<9){
    for (size_t j = 0; j < 9; j++) {
      somma+=mat[pos][j];
    }
    return somma_pari(mat,pos+2,somma);
  }
  else return somma;
}

int main(){
  int mat[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,6,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,9,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,3,1,7,4,9,2,5,8},{4,9,2,8,5,6,1,3,7}};
  printf("Somma pari: %d\n", somma_pari(mat,0,0));
  printf("Somma dispari: %d\n", somma_dispari(mat,1,0));
}
