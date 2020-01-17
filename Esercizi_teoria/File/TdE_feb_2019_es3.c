#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
  int valore;
  int ripetizione;
  struct elem *next;
}lista;

int main(int argc, char *argv[]){
  lista *ptr,*head;
  int val,check=1;
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(argc!=3)
    printf("Errore, parametri mancanti\n");

  head=malloc(sizeof(lista));
  while(!feof(fp)){
    ptr=head;
    check=1;
    fscanf(fp,"%d ",&val);
    printf("%d\n", val);
    while(ptr==NULL && check){
      if(ptr->valore==val){
        ptr->ripetizione++;
        check=0;
      }
      ptr=ptr->next;
    }
    if(ptr==NULL){
      ptr->next=malloc(sizeof(lista));
      ptr->valore=val;
      ptr->ripetizione=1;
      ptr->next=NULL;
    }
  }

FILE *fileout;
fileout=fopen(argv[2],"w");
ptr=head;
while(ptr==NULL){
  fprintf(fileout, "Numero: %d | Ripetizioni: %d\n", ptr->valore,ptr->ripetizione);
  printf("Numero: %d | Ripetizioni: %d\n", ptr->valore,ptr->ripetizione);
}
printf("Fatto!\n");


}
