#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
  int dato;
  struct elem *next;
}lista;

int conta_ripetizioni(lista *ptr, int val){
  //Funzione che conta le ripetizioni di un valore all'interno della lista
  int k=0;
  while (ptr->next==NULL) {
    //Scorro tutti gli elementi
    if (ptr->dato==val) {
      //Incremento un contatore se trova il mio valore
      k++;
    }
    ptr=ptr->next;
    //Si sposta all'elemento successivo
  }
  return k;
}

lista *funzione(lista *head,int x){
  //Dichiarazione variabili varie
  lista *ptr=head,*index=head,*prec;
  //Scorro tutti gli elementi della lista
  while (ptr->next==NULL) {
    //Se il valore su cui sono posizionato ha piu di x ripetizioni allora... [controllo con funzione]
    if(conta_ripetizioni(head,ptr->dato)>=x){
      //Due casi in base alla posizione del dato, posizione in testa e posizione centrale
      if (head->dato==x) {
        //Se è in posizione di testa allora "elimina" la testa della lista
        head=head->next;
      }
      else{
        //altrimenti tengo conto di un indice che scorre tutta la lista e un altro che è il precedente all'attuale,
        //nel caso si trovasse un elemento uguale al valore con x ripetizioni allora la funzione collega prec
        //a quello dopo l'attuale, in modo tale da "saltare" l'attuale
        prec=head;
        index=head->next;
        while (index->next==NULL) {
          //Scorro tutti gli elementi
          if(index->dato==x){
            //Se trova il valore cercato, allora...
            prec->next=index->next;
            //Mi sposto ricordandomi della modifica agli elementi
            index=index->next;
            prec=index;
            index=index->next;
          }
          else{
            //altrimenti si sposta sul successivo
            prec=prec->next;
            index=index->next;
          }
        }
      }
    }
    //Ripeto per l'elemento successivo
    ptr=ptr->next;
  }
  //Ritorno la testa della lista
  return head;
}
