#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
  int val;
  struct elem *next;
}lista;

lista *read(char filename[]){
  FILE *fp;
  lista *head=NULL,*ptr;
  fp=fopen(filename,"r");
  while(!feof(fp)){
    if (head==NULL) {
      head=malloc(sizeof(lista));
      fscanf(fp,"%d,",&(head->val));
      head->next=NULL;
    }
    else{
      ptr=head;
      while(ptr->next==NULL){
        ptr=ptr->next;
      }
      ptr->next=malloc(sizeof(lista));
      ptr=ptr->next;
      fscanf(fp,"%d,",&(ptr->val));
      ptr->next=NULL;
    }
  }
  return head;
}

int main(int argc, char const *argv[]) {
  lista *head;
  if(argc!=3) {
    printf("Erroooore nei parametri di input\n");
    return 0;
  }
  head=read();

}
