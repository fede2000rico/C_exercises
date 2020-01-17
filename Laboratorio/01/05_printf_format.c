#include<stdio.h>

int main(){
  int number=0,i;

  printf("%-10s%-10s%-10s\n","N","N^2","N^3");

  for (i = 0; i < 5; i++) {
    printf("%-10d%-10d%-10d\n",number,number*number,number*number*number );
    number++;
  }
  return 0;
}
