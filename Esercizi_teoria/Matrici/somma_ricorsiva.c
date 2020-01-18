#include<stdio.h>
#define N 4

int mat[N][N]={{1,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,1}}; //Somma 6

int somma_elem(int mat[N][N],int j,int k){
  //Caso base
  if (j==N-1 && k==N-1) {
    //Ritorna la somma incrementata con l'ultimo elemento
    return mat[j][k];
  }

  //Se sono sull'ultimo elemento di una riga, allora incremenra la riga e azzera la colonna
  if (k==N-1) {
    return mat[j][k]+somma_elem(mat,j+1,0);
  }

  //Altrimenti ritorna la somma incrementata dell'elemento corrente
  return mat[j][k] + somma_elem(mat,j,k+1);
}


int main(){
  printf("La somma è: %d\n", somma_elem(mat,0,0));
}
