#include<stdio.h>
#include<math.h>
int dim,riga_scan=0,l,k,check=1;

/*Variabili per la divisione per 10*/
int resto,riga_scan_copy;

int main(){
  printf("Inserire la dimensione della matrice quadrata:\n");
  scanf("%d", &dim);
  int matrice[dim][dim];

  /*Procedura per compilare la matrice*/
  for (l = 0; (l < dim) && check; l++) {
    printf("Inserire i valori della riga %d (ES: 1234 per una matrice di dimensione 4)\n", l+1);
    scanf("%d", &riga_scan);

    riga_scan_copy=riga_scan;

    for (k = 0; (k < dim) && check; k++) {
      resto=riga_scan_copy%10;
      matrice [l][dim-1-k]=resto;
      riga_scan_copy=riga_scan_copy/10;
    }
    if (k!=dim)
      check=0;
  }

  for (l = 0; l < dim; l++) {
    for (k = 0; k < dim; k++) {
      printf("%-5d", matrice[l][k]);
    }
    printf("\n");
  }

  /*Variabili per la verifica del quadrato latino*/
  int i=0,j=0;

  /*Procedura per verificare che sia un quadrato latino! Parte RIGHE*/
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      for (k = j+1; (k < dim) && check; k++) {
        if (matrice[i][j] == matrice[i][k])
          check=0;
      }
    }
  }

  /*Procedura per verificare che sia un quadrato latino! Parte COLONNE*/
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      for (k = j+1; (k < dim) && check; k++) {
        if (matrice[j][i] == matrice[k][i])
          check=0;
      }
    }
  }

  if (check){
    printf("La matrice è un quadrato latino! :)\n");
    return 0;
  }
  else{
    printf("La matrice non è un qudrato latino! :(\n");
    return 1;
  }


/*CODICE*/

}
