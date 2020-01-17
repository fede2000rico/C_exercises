#include<stdio.h>
#define DIM 5

int main(int argc,char *argv[]){
  FILE *data;
  int M[DIM][DIM],i=0,j=0,e=1;
  data=fopen(argv[1],"rf");

  printf("%s\n", argv[1]);
  while (!feof(data)){
    for (j = 0; j < DIM; j++) {
      fscanf(data,"%d",&M[i][j]);
    }
    i++;
  }

  for (size_t l = 0; l < DIM; l++) {
    for (size_t k = 0; k < DIM; k++) {
      printf("%-5d", M[l][k]);
    }
    printf("\n");
  }

  for (size_t k = 0; k < DIM && e; k++) {
    if(M[i][j]!=M[j][i]){
      printf("Error\n");
      e=0;
    }
  }
  if (e)
    printf("La matrice è simmetrica\n");
}
