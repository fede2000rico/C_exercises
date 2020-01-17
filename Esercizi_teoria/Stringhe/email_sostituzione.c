#include<stdio.h>
#include<string.h>

int main() {
  char string[100];
  int k=0;
  scanf("%s", string);
  char new_string[strlen(string)+11];
  for (size_t i = 0; i < strlen(string); i++,k++) {
    if (string[i]=='.') {
      new_string[k]='_';
      new_string[k+1]='D';
      new_string[k+2]='O';
      new_string[k+3]='T';
      new_string[k+4]='_';
      k=k+5;
    }
    else
      if (string[i]=='@') {
        new_string[k]='_';
        new_string[k+1]='A';
        new_string[k+2]='T';
        new_string[k+3]='_';
        k=k+4;
      }
      else
        new_string[k]=string[i];
  }
  printf("%s\n", new_string);
}
