#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
  int val;
  struct elem *next;
}lista1;

typedef struct elem1{
  int val;
  int rip;
  struct elem1 *next;
}lista2;

lista2 *func(lista1 *ptr1){
  lista2 *ptr2;
  int dato;
  ptr2 =malloc(sizeof(lista2));
  ptr2->val=ptr1->val;
  ptr2->rip=1;
  ptr2->next=NULL;

  ptr1=ptr1->next;
  while (ptr1->next!=NULL) {
    dato=ptr1->val;
    while (ptr2->next!=NULL && ptr2->val!=dato) {
      ptr2=ptr2->next;
    }
    if(ptr2->val==dato){
      ptr2->rip++;
    }
    else{
      ptr2->next=malloc(sizeof(lista2));
      ptr2=ptr2->next;
      ptr2->val=ptr1->val;
      ptr2->rip=1;
      ptr2->next =NULL;
    }
    ptr1=ptr1->next;
  }
}

int main(){
  lista1 *ptr;
  ptr=malloc(sizeof(lista1));
  for (size_t i = 0; i < 6; i++) {

  }
}
