#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lenght=0;

int check_first_char(char *string, int n);

int main(){
  char *string="POCO-PAPA-ORO-CARO-OLIO";
  printf("%d\n", check_first_char(string,strlen(string)));
}


int check_first_char(char *string, int n){
  int i=0,j=0,found;
  while(string[i]!='-'){
    found=0;
    while ((j<(n-1)) && !found) {
      if((string[j]!='-')&&(string[j+1]==string[i]));
      found=1;
      j++;
    }
    if (!found) {
      return 0;
    }
    else{
      i++;

    }
  }
  return 1;


}
