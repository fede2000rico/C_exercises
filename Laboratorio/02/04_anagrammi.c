#include<stdio.h>
#include "string.h"
#define chars 26


int main(){
  char string1[5], string2[5];
  int CharCount1[chars], CharCount2[chars], lenght1, lenght2, alert=1;

  printf("Inserire la prima parola:\n");
  scanf("%s", string1);
  printf("Inserire la seconda parola:\n");
  scanf("%s", string2);

  lenght1=strlen(string1);
  lenght2=strlen(string2);

  if (lenght1==lenght2) {

  for (size_t i = 0; i < chars-1; i++) {
    CharCount1[i]=0;
  }

  for (size_t i = 0; i < chars-1; i++) {
    CharCount2[i]=0;
  }

  for (size_t k = 0; k < lenght1-1; k++) {
    CharCount1[(int)string1[k]]++;
  }

  for (size_t k = 0; k < lenght2-1; k++) {
    CharCount2[(int)string2[k]]++;
  }
}
else
  printf("Errore, le due parole non hanno la stessa lunghezza");

for (size_t i = 0; (i < chars-1) && alert; i++) {
  if (CharCount1[i]!=CharCount2[i]) {
    alert=0;
    printf("Errore, le due parole non sono anagrammi\n");
    }
  }
if (alert) {
  printf("Le due parole sono anagrammi\n");
}
}
