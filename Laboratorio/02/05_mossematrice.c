#include<stdio.h>
#define K 4
#define DIM 6
int main(){
  typedef struct{
    int vert;
    int oriz;
  } Mossa;

  Mossa A[K];
  int M[DIM][DIM],somma=0;

  /*Definizione*/
  for (size_t j = 0; j < DIM; j++) {
    for (size_t k = 0; k < DIM; k++) {
      M[j][k]=k;
      printf("%10d", M[j][k]);
    }
    printf("\n");
  }
  for (size_t i = 0; i < K; i++) {
    printf("Inserire mossa %d:\n", (int)i);
    scanf("%d,%d",&A[i].vert,&A[i].oriz);
  }

  somma = M[0][0];
  int r=0,c=0;
  for (size_t h = 0; h < K; h++) {
    r+=A[h].oriz;
    c+=A[h].vert;
    if(r>=0 || r<6 || c>=0 || c<6){
    somma+=M[r][c];
    printf("Posizione: %d,%d\n", A[h].oriz,A[h].vert);
  }
  else{
    printf("Errore, fuori dimensione\n");
  }
  }

  printf("Somma: %d\n", somma);
  return 0;
}
