#include "mate.h"
/*
int MCD(int a, int b);
int power(int base, int exp);*/

int MCD(int a, int b){

  /*Estrae il valore assoluto*/
  if(a<0)
    a=-a;
  if(b<0)
    b=-b;

  /*Ordina i dati*/
  int swap=0;
  if(a<b){
    swap=a;
    a=b;
    b=swap;
  }

  if(b==0)
    return a;

  /*Esegue la parte ricorsiva*/

  if(b==0)
    return a;
  else
    return MCD(b,a%b);
}

int power(int base, int exp){
  if(exp==0)
    return 1;
  else
    return base * power(base, exp-1);
}
