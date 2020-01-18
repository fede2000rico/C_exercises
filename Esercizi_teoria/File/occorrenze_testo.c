//Conta le occorrenze delle 26 lettere minuscole dell'alfabeto, ignorando gli altri caratteri.
#include<stdio.h>

//Array per contare le occorrenze delle lettere
int alfabeto[26]={0};

int main(){
  //Creo e apro il file in modalità lettura
  FILE *fp;
  fp=fopen("percorso file","r");

  //Ciclo su tutto il contenuto del file
  while(!feof(fp)){
    char val;
    //Scannerizzo ogni carattere
    fscanf(fp,"%c",&val);

    //Verifico che sia nel range valido ed incremento l'array alfabeto
    if(val-'a'>=0 && val-'a'<26){
      alfabeto[val]++;
    }
  }
}
