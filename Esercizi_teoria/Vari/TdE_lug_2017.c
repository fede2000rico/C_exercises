#include<stdio.h>
#define N 10
int matrix[N][N];

void set_matrix(int r,int c,int val){
  int *ptr_matrix=&matrix[0][0];
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++) {
      if(i<r && j<c)
        *(ptr_matrix +j)=val;
    }
    printf("\n");
    ptr_matrix+=10;
  }
  printf("\n");
}

void print_matrix(int *matrix){
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      printf("%5d", *(matrix +j));
    }
    printf("\n");
    matrix+=N;
  }
  printf("\n");
}

int main(/*int argc, char const *argv[]*/) {
  FILE *fp;
  int j=0,r,c,val;
  fp=fopen("lug2017_data.txt","r");
  while(!feof(fp)){
    if(j==0){
      fscanf(fp,"%d %d %d", &r,&c,&val);
      set_matrix(r,c,val);
    }
    for (size_t i = 0; i < 3; i++) {
      fscanf(fp,"%d ",&matrix[j][i]);
    }
    j++;
  }
  print_matrix(&matrix[0][0]);
  return 0;
}
