//Conta le occorrenze delle 26 lettere minuscole dell'alfabeto, ignorando gli altri caratteri.
#include<stdio.h>
#include<string.h>

//Array per contare le occorrenze delle lettere
int alfabeto[26]={0};

int main(){
  char *string="abc";
  //strcpy(string,argv[1]);

  for(size_t i=0;i<strlen(string);i++){

    if(string[i]-'a'>=0 && string[i]-'a'<26){
      alfabeto[string[i]-'a']++;
    }
  }

  for (size_t i = 0; i < 26; i++) {
    printf("%5d", alfabeto[i]);
  }
  printf("\n");
}
