#include<stdio.h>
#include<stdlib.h>
#define N 9

int sudoku_corretto[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,6,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,9,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,3,1,7,4,9,2,5,8},{4,9,2,8,5,6,1,3,7}};
int sudoku_sbagliato[N][N] = {{5,8,6,4,2,1,3,7,9},{3,2,7,9,1,5,4,8,1},{9,1,4,3,7,8,6,2,5},{1,6,3,5,8,4,7,9,2},{2,4,5,1,9,7,8,6,3},{8,7,4,6,3,2,5,1,4},{7,5,8,2,1,3,9,4,6},{6,8,1,7,4,9,2,5,8},{4,9,2,8,5,2,1,3,7}};


int main(int argc, char *argv[]){
  FILE *fp;
  fp=fopen(argv[1],"w");

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      fprintf(fp, "%d,", sudoku_sbagliato[i][j]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  printf("File generato!\n");
}
