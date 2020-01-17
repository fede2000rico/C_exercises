#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rev_print_it(char *string){
  int lenght=0;
  lenght=strlen(string);
  for (size_t i = lenght; i > 0; i--) {
    printf("%c\t", string[i-1]);
  }
}

char rev_print_ric(char *string, int k){
  if(string[k]=='\0'){
    return string[k-1];
  }
  else{
    printf("%c\t", rev_print_ric(string, k+1));
  }
  return string[k-1];
}

int main(){
  char *string;
  int k=0,i=1;
  string =(char*)malloc(sizeof(char));
  printf("Inserisci caratteri\n");
  do{
    scanf("%c\n", &string[k]);
    if (string[k]=='.') i=0;
    string=realloc(string,sizeof(char));
    k++;
  }while (i);
  //Stringa scrtta in ordine corretto
  printf("%s\n", string);
  printf("\n");
  rev_print_it(string);
  printf("\n");
  rev_print_ric(string,0);
  printf("\n");
}
