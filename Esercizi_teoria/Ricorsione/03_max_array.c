#include<stdio.h>
#include<stdlib.h>

int search_max(int *array, int max){
  if(*array=='\0')
    return max;
  else{
    if(*array>max)
      max=*array;
    return search_max(array+1,max);
  }
}

int main(){
  int *array,i=0;
  array=(int *)malloc(sizeof(int));
  printf("Inserire numeri separati da spazio\n");
  while(getchar()!='a'){
    scanf("%d", array+i);
    i++;
  }

  printf("%d\n", search_max(array,0));
}
