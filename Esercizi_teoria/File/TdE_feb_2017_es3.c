#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definizione lista
typedef struct elem{
  int val;
  struct elem *next;
}lista;

//Definizione stringhe con nome file
char *file_input,*file_output;

//Funzione che legge i dati e li scrive in una lista che viene creata all'interno della funzione seguente
lista *read(){
  //Dichiarazioni varie
  FILE *fp;
  lista *head=NULL,*ptr;

  //Apertura file in modalità lettura
  fp=fopen(file_input,"r");

  //Legge fino alla fine del file
  while(!feof(fp)){
    //Se la variabile head è NULL (caso iniziale), allora ...
    if (head==NULL) {
      //Creo e alloco la memoria
      head=malloc(sizeof(lista));

      //Leggo da file e setto il nodo della lista appena creato NB: setto anche il valore next con NULL
      fscanf(fp,"%d,",&(head->val));
      head->next=NULL;
    }
    else{
      //Se non è NULL, allora avvio la ricerca del primo NULL
      ptr=head;

      //All'uscita da questo while avrò il puntatore ptr al nodo della lista con il next=NULL
      while(ptr->next==NULL){
        ptr=ptr->next;
      }

      //Creo e alloco una nuova zona di memoria
      ptr->next=malloc(sizeof(lista));

      //Aggiorno il nodo corrente
      ptr=ptr->next;

      //Leggo da file e setto il nodo della lista appena creato NB: setto anche il valore next con NULL
      fscanf(fp,"%d,",&(ptr->val));
      ptr->next=NULL;
    }
  }
  //Ritorno la testa della lista
  return head;
}

//Funzione che crea e scrive in un nuovo file le sottosequenze di minimo 2 elementi
void write(lista *head){
  //Dichiarazioni varie
  lista *prec,*actual;
  FILE *fp;

  //Apertura file in modalità write
  fp=fopen(file_output,"w");

  //Setto i due puntatori che mi indicheranno il nodo attuale e quello precedente
  prec=head;
  actual=head->next;

  //Scorro tutti gli elementi della lista finche non trovo l'ultimo
  while (actual->next!=NULL) {
    //Se il precedente è minore dell'attuale, allora...
    if (prec->val<actual->val) {
      //Scrive su file i due valori
      fprintf(fp,"%d,%d,",prec->val,actual->val);

      //Aggiorna la posizione
      prec=actual;
      actual=actual->next;

      //Inizia un ciclo per scrivere su file tutti i valori che sono crescenti consecutivi
      while (prec->val<actual->val && actual->next!=NULL) {
        //Scrivo solo l'attuale
        fprintf(fp, "%d,", actual->val);
      }
      //Terminata la serie di numeri crescenti mando a capo
      fprintf(fp, "\n");

      //Aggiorno la posizione
      prec=actual;
      actual=actual->next;
    }
  }
}

int main(int argc, char const *argv[]) {
  //Dichiarazioni varie
  lista *head,*ptr;

  //Se non ci sono i parametri richiesti allora termina con errore
  if(argc!=3) {
    printf("Errore nei parametri di input\n");
    return 0;
  }

  //Setto le variabili dei nomi dei file
  strcpy(file_input,argv[1]);
  strcpy(file_output,argv[2]);

  //Lancio la funzione che crea la lista
  head=read();
  ptr=head;

  //Stampo la lista
  while (ptr->next==NULL) {
    printf("%d\t", ptr->val);
    ptr=ptr->next;
  }

  //Scrivo su file
  write(head);

}
