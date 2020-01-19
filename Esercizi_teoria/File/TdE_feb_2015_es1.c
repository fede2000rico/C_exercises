//Legge da file una matrice formattata in modo da essere un cruciverba e scrive la lista di parole verticali e orizzontali
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definizione file sorgente e uscita
#define FILEIN "percorso"
#define FILEOUT "percorso"

//Funzione che scrive su file le parole, in ingresso riceve un array e poi lo edita per ottenere le varie possibilità
void write_words(char *string, int lenght){
  FILE *fw;
  fw=fopen(FILEOUT,"r");
  if (string[1]=='*') {
    for (size_t i = 2; i < lenght; i++) {
      fprintf(fw,"%c",string[i]);
    }
  }
  else if(string[lenght-2]=='*'){
    for(size_t k=0,k<lenght-2,k++){
      fprintf(fw,"%c",string[k]);
    }
  }
  int j=0;
  else{
    while(string[j]!='*'){
      fprintf(fw,"%c",string[j]);
    }
    j++;
    fprintf(fw, "\n");
    for (size_t k = j; k < lenght-1; k++) {
      fprintf(fw,"%c",string[k]);
    }
  }
  fprintf(fw,"\n");
}

int main(){
  int k=0,rig,col;
  char **matrix;
  FILE *fr;
  fr=fopen(FILEIN,"r");

  matrix=(**char)malloc(col*sizeof(*char));

  //Scrittura della matrice -----------------------------------------------------------------
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

  //Chiamata della funzione per scrivere le parole ------------------------------------------
  //Parole in riga
  for (size_t i = 0; i < rig; i++) {
    write_words(matrix[i]);
  }
  char string[rig];
  for (size_t k = 0; k < col; k++) {
    for (size_t j = 0; j < rig; j++) {
      string[j]=matrix[j][k];
    }
    write_words(string);
  }

}
