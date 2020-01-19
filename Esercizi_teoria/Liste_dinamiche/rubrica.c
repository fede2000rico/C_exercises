//Inserimento contatto in rubrica
#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
  char nome[10];
  struct elem *next;
}contatto;

int ordine(char string1[10],char string2[10]){ //1. da inserire | 2. dall'elenco
  //Funzione che restituisce 0 se il nome da inserire è successivo all'elemento della rubrica corrente (string2)
  for (size_t i = 0; i < 10; i++) {
    if (string1[i]!=string2[i] && string1[i]>string2[i]) {
      return 0;
    }
    else return 1;
  }
}


void insert(contatto *head, char nome[10]){
  if(head->next==NULL || ordine(nome,head->nome)){
    head=malloc(sizeof(contatto));
    strcpy(head->nome,nome); //Funzione per copiare il contenuto di una stringa
    head->next==NULL;
  }

  //Setto i valori del ptr (attuale) e precedente
  contatto *ptr=head->next,*prec=head;

  else {
    while (!(ordine(nome,prec->nome) && ordine(nome,ptr->nome)) && ptr->next!=NULL) {
    //Aggiorno gli indici
    prec=prec->next;
    ptr=ptr->next;
    }

    //Condizione sono al termine della lista
    if(ptr->next!=NULL && !ordine(nome,ptr->nome)){
      ptr->next=malloc(sizeof(contatto));
      ptr=ptr->next;
      strcpy(ptr->nome,nome);
      ptr->next=NULL;
    }
    else{
      prec->next=malloc(sizeof(contatto));
      prec=prec->next;
      strcpy(prec->nome,nome);
      prec->next=ptr;
    }

    //Condizione inserimento in mezzo
    if(!ordine(nome,prec->nome) && ordine(nome,ptr->nome)){
      prec->next=malloc(sizeof(contatto));
      prec=prec->next;
      strcpy(prec->nome,nome);
      prec->next=ptr;
    }
  }
}
