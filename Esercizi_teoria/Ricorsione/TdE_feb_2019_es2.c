//restituire una lista che somma ad ogni elemento tutti i successivi
#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
  int val;
  struct elem *next;
}lista;

int edit(lista *ptr, int sum){
  //Caso base
  if(ptr->next==NULL){
    sum+=ptr->val;
  }
  else
    ptr->val+=edit(ptr->next,sum);
}
