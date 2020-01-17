#include<stdio.h>
#include<stdlib.h>
#define DIM 4

void Ris(int mat1[DIM][DIM], int mat2[DIM][DIM]);
void print_matrix(int matrix[DIM][DIM]);

int main(int argc, char *argv[]){
  FILE *fp;
  int mat1[DIM][DIM]={0},mat2[DIM][DIM]={0},i=0,j=0;

  if(argc!=2)
    printf("Errore, nessun file passato\n");

  fp=fopen(argv[1],"r");

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      fscanf(fp,"%d,",&mat1[i][j]);
    }
  }
  Ris(mat1,mat2);
  print_matrix(mat1);
  print_matrix(mat2);
}



void Ris(int mat1[DIM][DIM], int mat2[DIM][DIM]){
  int dispari[25]={0},pos=0;

  //seleziona i numeri dispari e li scrive nell'array
  for (size_t i = 0; i < DIM; i++) {
    for (size_t j = 0; j < DIM; j++) {
      if(((int)mat1[i][j]%2)==1){
        dispari[pos]=mat1[i][j];
        pos++;
      }
    }
  }

  printf("\n\n");

  pos=0;
  //inserisce i valori dispari nella matrice 2
  for (size_t i = 0; i < DIM; i++) {
    for (size_t j = 0; j < DIM; j++) {
      mat2[i][j]=dispari[pos];
      pos++;
    }
  }
}


void print_matrix(int matrix[DIM][DIM]){
  for (size_t i = 0; i < DIM; i++) {
    for (size_t j = 0; j < DIM; j++) {
      printf("%5d", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
