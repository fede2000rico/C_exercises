#include<stdio.h>
#include<stdlib.h>

typedef struct N {
  int dato;
  struct N *ptr_struct;
}lista;

void lista_print(lista *ptr);
lista *lista_addfirst(lista *inizioptr);
void lista_addsort(lista *ptr,int newdato);

int main(){
  lista elementi;
  lista *inizio;
  lista *ptr;

  inizio=malloc(sizeof(elementi));
  inizio->dato=15;

  ptr=malloc(sizeof(elementi));
  ptr->dato=20;
  ptr->ptr_struct=NULL;

  inizio->ptr_struct=ptr;

  lista_print(inizio);
  inizio=lista_addfirst(inizio);
  printf("\n");
  lista_print(inizio);
}


void lista_print(lista *ptr){
  if(ptr!=NULL){
    printf("%d\n", ptr->dato);
    ptr=ptr->ptr_struct;
    lista_print(ptr);
  }
}

lista *lista_addfirst(lista *inizioptr){
  lista elementi;
  lista *inizio;

  inizio=malloc(sizeof(elementi));
  inizio->dato=88;
  inizio->ptr_struct=inizioptr;
  return inizio;
}
