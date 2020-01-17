//abc(def) ----> abc(#)

#include<stdio.h>
#include<stdlib.h>

typedef struct N {
  char carattere;
  struct N *next;
}lista;

void substring(char *string){

}

void lista_print(lista *ptr){
  if(ptr!=NULL){
    printf("%c\n", ptr->carattere);
    ptr=ptr->next;
    lista_print(ptr);
  }
}

int main(){
  lista *head,*prec=NULL,*ptr;


  while(getchar()!='0'){
    head=malloc(sizeof(lista));
    head->carattere=getchar();
    head->next=prec;
    if (prec==NULL) {
      ptr=head;
    }
    prec=head;

  }

  lista_print(ptr);
}
