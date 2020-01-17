#include<stdio.h>
#include<stdlib.h>

typedef struct elemlista {
  int dato;
  struct elemlista *next;
}lista;

lista *lista_add_end(lista *ptr,int newdato);
lista *lista_add_sort(lista *head,int newdato);
lista *lista_add_first(lista *inizioptr, int newdato);
void lista_print(lista *ptr);
void lista_print_rev(lista *head);

int main(){
  int control=1,value;
  lista *head=NULL;
  while(control){
    printf("Nuovo controllo\n");
    scanf("%d", &control);
    switch(control){
      case 0:
        control=0;
        break;

      case 1:
        printf("Inserire valore da aggiungere in coda\n");
        scanf("%d",&value);
        head=lista_add_end(head,value);
        break;

      case 2:
        printf("I valori della lista sono:\n");
        lista_print(head);
        break;

      case 3:
        printf("Inserisci valore da aggiungere in ordine:\n");
        scanf("%d", &value);
        lista_add_sort(head,value);
        break;
      case 4:
        printf("I valori della lista al contrario sono:\n");
        lista_print_rev(head);
        break;
      }
  }
}

lista *lista_add_end(lista *ptr,int newdato){
  lista *inizio=ptr;
  if(inizio==NULL){
    inizio=malloc(sizeof(lista));
    inizio->dato=newdato;
    inizio->next=NULL;
    return inizio;
  }
  else{
    while (ptr->next!=NULL) {
      ptr=ptr->next;
    }
    ptr->next=malloc(sizeof(lista));
    ptr=ptr->next;
    ptr->dato=newdato;
    ptr->next=NULL;
    return inizio;
  }
}

void lista_print(lista *ptr){
  if(ptr!=NULL){
    printf("%d\n", ptr->dato);
    ptr=ptr->next;
    lista_print(ptr);
  }
}

lista *lista_add_sort(lista *head,int newdato){

  lista *ptr=NULL;
  if(head==NULL){
    ptr=malloc(sizeof(lista));
    ptr->dato=newdato;
    ptr->next=NULL;
    return ptr;
  }
  if(head->dato<newdato)
    head->next=lista_add_sort(head->next,newdato);
  else
    lista_add_first(head, newdato);
  return ptr;
}

lista *lista_add_first(lista *inizioptr, int newdato){
  lista elementi;
  lista *inizio;

  inizio=malloc(sizeof(elementi));
  inizio->dato=newdato;
  inizio->next=inizioptr;
  return inizio;
}


void lista_print_rev(lista *ptr){
  if(ptr==NULL){
    printf("|--- ");
  }
  else{
    lista_print_rev(ptr->next);
    printf("%d <--- ", ptr->dato);
  }
}
