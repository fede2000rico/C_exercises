#include<stdio.h>
#include<stdlib.h>
#define N 100

//Definizione struct
typedef struct{
  int max;
  int min;
  float average;
}data;

//Metodo 1
void function1(int array[N],float *valori){
  //Dichiarazionei varie
  int max=0,min=0;
  float average;
  //Ciclo su tutti gli elementi
  for (size_t i = 0; i < N; i++) {
    if (array[i]>max) {
      //Se maggiore di max, allora aggiorna max
      max=array[i];
    }
    if (array[i]<min) {
      //Se minore di min, allora aggiorna min
      min=array[i];
    }
    //Incrementa la somma
    average+=array[i];
  }
  //Calcolo media
  average=average/100.0;
  //Set dei valori nella memoria allocata (array di float)
  valori[0]=max;
  valori[1]=min;
  valori[2]=average;
}

//Metodo 2
void function2(int array[N], data *valori){
  //Dichiarazionei varie
  int max=0,min=0;
  float average;
  //Ciclo su tutti gli elementi
  for (size_t i = 0; i < N; i++) {
    if (array[i]>max) {
      //Se maggiore di max, allora aggiorna max
      max=array[i];
    }
    if (array[i]<min) {
      //Se minore di min, allora aggiorna min
      min=array[i];
    }
    //Incrementa la somma
    average+=array[i];
  }
  //Calcolo media
  average=average/100.0;
  //Set dei valori nella memoria allocata (array di float)
  valori->max=max;
  valori->min=min;
  valori->average=average;
}

int main(){
  //Dichiaro e creo array da 100 valori
  int list[N];
  for (size_t i = 0; i < N; i++) {
    list[i]=i;
  }
//FUNZIONE1 ------------------------------------------------------
  //Creo un array da tre float per max min e media e lo alloco per poterlo passare alla funzione
  float *valori;
  valori=malloc(sizeof(float)*3);
  //Chiamo la funzione
  function1(list,valori);

  //Verifica funzionamento -----> FUNZIONA
  printf("max %f\n", valori[0]);
  printf("min %f\n", valori[1]);
  printf("ave %f\n", valori[2]);


printf("Funzione2\n\n");

//FUNZIONE2 ------------------------------------------------------
  //Creo una struct con max min e media e la alloco
  data *elem;
  elem=malloc(sizeof(data));

  //Chiamo la funzione 2
  function2(list,elem);

  //Verifica funzionamento -----> FUNZIONA
  printf("max %d\n", elem->max);
  printf("min %d\n", elem->min);
  printf("ave %f\n", elem->average);

}
