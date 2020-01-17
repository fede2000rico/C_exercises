#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  int valore;
  struct lista *next;
} numero;

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

int check_duplicate(int n){

}

float media_no_duplicati(numero *ptr){
  int n=0,i=0;
  float somma=0.0;
  while (ptr==NULL) {
    n++;
  }
  while(ptr==NULL){
    if(check_duplicate(ptr->valore)){
      somma+=ptr->valore;
    }
  }

  return (float)somma/i;
}

int main(){

}
