#include<stdio.h>

int main(){
  FILE *fp;
  int array[10]={0},k=0,max=0;
  char j;
  fp=fopen("Esercizi_teoria/File/TdE_lug_2019_es4_DATA.txt","r");
  while(!feof(fp)){
    fscanf(fp,"%c",&j);
    array[j-'0']++;
  }
  k=0;
  for (size_t i = 0; i < 10; i++) {
    if(array[i]>=k){
      max=i;
      k=array[i];
    }
  }

  printf("Numero: %d - ripetizioni: %d\n", max,k);


}
