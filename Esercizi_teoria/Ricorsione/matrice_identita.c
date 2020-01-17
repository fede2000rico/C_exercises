#include<stdio.h>
#define N 4

int mat_identita[N][N]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int mat_err[N][N]={{1,0,1,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

int check(int mat[N][N],int j,int k){
  //Caso base
  if(j==N-1 && k==N-1 && mat[j][k]==1){
    //Se l'elemento corrente è quello in basso a destra (ultimo da verificare) e vale 1, allora è identita
    return 1;
  }
  //Evoluzione della ricorsione
  if (mat[j][k]!=mat[k][j]) {
    //Se non è simmetrica, allora non è identita
    return 0;
  }
  if (j!=k && mat[j][k]!=0) {
    //Se un elemento fuori dalla diagonale non è 0, allora non è identita
    return 0;
  }
  else{
    if(k==N-1){
      //Se il valore attuale è l'ultimo della riga, allora aggiorna la chiamata successiva con
      //la posizione sulla diagonale della riga successiva (per fare questo gli mando le coordinate (j,k) con j+1
      //in entrambi cosi mi trovero sulla diagonale).
      //Faccio questo per evitare di fare controlli ripetuti che sarebbero inutili
      return check(mat,j+1,j+1);
    }
    //Altrimenti incrementa la colonna e basta
    else return check(mat,j,k+1);
  }
}

int main(){
  printf("result: %d\n", check(mat_identita,0,0));
}
