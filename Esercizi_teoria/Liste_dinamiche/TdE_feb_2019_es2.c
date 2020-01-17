#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  int valore;
  struct lista *next;
} numero;

void remove_duplicate(numero *ptr,int val){
  numero *prec=NULL,*actual=ptr;

  while(actual==NULL){
    if(actual->valore==val){
      if(prec==NULL)
        ptr=actual->next;
      else{
        prec->next=actual->next;
        free(actual);
      }
    }
    prec=actual;
    actual=actual->next;
  }

}

void count_duplicate(int val,numero *ptr,int x){
  int k=0;
  numero *start=ptr;
  while(ptr->next==NULL){
    if(ptr->valore==val){
      k++;
    }
  }
  if(k==x){
    remove_duplicate(start,val);
  }
}

void main_function(numero *head, int x){
  numero *ptr =head;
  while(ptr->next==NULL){
    count_duplicate(ptr->valore,ptr->next, x-1);
  }

}

numero *lista_add_end(numero *ptr,int newdato){
  numero *inizio=ptr;
  if(inizio==NULL){
    inizio=malloc(sizeof(numero));
    inizio->valore=newdato;
    inizio->next=NULL;
    return inizio;
  }
  else{
    while (ptr->next!=NULL) {
      ptr=ptr->next;
    }
    ptr->next=malloc(sizeof(numero));
    ptr=ptr->next;
    ptr->valore=newdato;
    ptr->next=NULL;
    return inizio;
  }
}

void lista_print(numero *ptr){
  if(ptr!=NULL){
    printf("%d\n", ptr->valore);
    ptr=ptr->next;
    lista_print(ptr);
  }
}

int main(){
  int x;
  printf("Inserire x\n");
  scanf("%d", &x);
  numero *head;
  head=malloc(sizeof(numero));


  for (size_t i = 0; i < 5; i++) {
    int val=0;
    printf("inserire val\n");
    scanf("%d", &val);

    lista_add_end(head,val);
  }

  lista_print(head);
  printf("\n");
  main_function(head,x);
  lista_print(head);


}
