//Legge da file una matrice formattata in modo da essere un cruciverba e scrive la lista di parole verticali e orizzontali
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definizione file sorgente
#define FILE "percorso"

int main(){
  int k=0,rig,col;
  char **matrix;
  FILE *fr;
  fr=fopen(FILE,"r");

  matrix=(**char)malloc(col*sizeof(*char));

  if(!k){
    fscanf(fr,"%d %d",&rig,&col);
    matrix=(**char)malloc(rig*sizeof(*char));
    for (size_t i = 0; i < rig; i++) {
      matrix[i]=(char*)malloc(sizeof(char)*col);
    }
    k++;
  }
  for (size_t j = 0; j < rig; j++) {
    for (size_t k = 0; k < col; k++) {
      fscanf(fr,"%c",&matrix[j][k]);
    }
}

}
