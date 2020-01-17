#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int code;
  char airport[3];
  int hour;
  int min;
  int hour_dep;
  int min_dep;
  int users;
} volo;

volo *lista_voli;
int count=0;

void lista_print(volo *ptr, int i){
  printf("%d\t", lista_voli[count].code);
  printf("%s\t", lista_voli[count].airport);
  printf("%d\t", lista_voli[count].hour);
  printf("%d\t", lista_voli[count].min);
  printf("%d\t", lista_voli[count].hour_dep);
  printf("%d\t", lista_voli[count].min_dep);
  printf("%d\t", lista_voli[count].users);
  printf("\n");
  if(count<3){
    lista_print(ptr,count ++);
  }
}

int decollo(volo *lista, int code, int hour_dep,int min_dep,int count){
  while(lista[count].code ==code && count<0){
    count--;
  }
  if(count>=0){
    (lista+count)->hour_dep=hour_dep;
    (lista+count)->min_dep=min_dep;
    lista_print(&lista_voli[0],0);
    return 1;
  }
  else
    return 0;
}


int main(){

  lista_voli=(volo*)malloc(6*sizeof(volo));
  int i=0,code,hour,min;
  FILE *fp;
  fp=fopen("ListaVoli.bin","rb");
  while(!feof(fp)){
    fread(&lista_voli[i].code,sizeof(int),1,fp);
    //printf("%d\t", lista_voli[i].code);

    fread(lista_voli[i].airport,sizeof(int),1,fp);
    //printf("%s\t", lista_voli[i].airport);

    fread(&lista_voli[i].hour,sizeof(int),1,fp);
    //printf("%d\t", lista_voli[i].hour);

    fread(&lista_voli[i].min,sizeof(int),1,fp);
    //printf("%d\t", lista_voli[i].min);

    fread(&lista_voli[i].hour_dep,sizeof(int),1,fp);
    //printf("%d\t", lista_voli[i].hour_dep);

    fread(&lista_voli[i].min_dep,sizeof(int),1,fp);
    //printf("%d\t", lista_voli[i].min_dep);

    fread(&lista_voli[i].users,sizeof(int),1,fp);
    //printf("%d\t", lista_voli[i].users);

    //printf("\n");
    i++;
  }
  lista_print(&lista_voli[0],5);
  printf("\n");

  printf("Inserire codice-ora:minuto del decollo:\n");
  scanf("%d-%d:%d",&code,&hour,&min);

  printf("%d\n",decollo(&lista_voli[0],code,hour,min,5));
  lista_print(&lista_voli[0],5);
}
