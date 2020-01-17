#include<stdio.h>
#include "string.h"

int i=0,tonda=0;

int main(){
  printf("Inserire una serie di parentesi: (fino a 20)\n");
  char string[20];
  scanf("%s", string);

  for (i = 0; i < 20; i++) {
    if (tonda>=0){
      if (string[i]=='(')
        tonda++;
      else if (string[i]==')'){
          tonda--;
        }
      }
    else {
      tonda=-1;
      }

  }
  if (!tonda)
    printf("Corretto!\n");
  else
    printf("Errore!\n");

  return 0;
}
