#include<stdio.h>
#define R 10
#define C 10
typedef enum{falso,vero} boolean;

int main(){
  int i,j,Matrix2D [R][C],valore=0;
  for (i = 0; i < R; i++) {
    for (j = 0; j < C; j++) {
      Matrix2D [i][j]=valore;
      printf("%-5d", Matrix2D [i][j]);
      valore++;
    }
    printf("\n");
  }
}
