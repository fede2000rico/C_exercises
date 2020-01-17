#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *string_edited(char *string,char *search, char *string_edited){

  int check=1;
  strcpy(string_edited,string);

  for (size_t i = 0; i < strlen(string); i++) {
    if(string[i]==search[0]){
      for (size_t k = 1; k < strlen(search) && check; k++) {
        if(string[i+k]==search[k]){

        }
      }
      if(check){
        for (size_t j = 0; j < strlen(search)-1; j++) {
          string_edited[i+j]='+';
        }
        i+=strlen(search)-1;
      }

    }
  }
  return string_edited;
}


int main(){
  char *string_edit,*search,*string;
  string = (char*) malloc(128);
  search = (char*) malloc(128);
  string_edit = (char*) malloc(128);

  printf("inserire string\n");
  fgets(string,128, stdin);

  printf("inserire search\n");
  fgets(search,128, stdin);

  string_edit=string_edited(string,search,string_edit);

  printf("%s\n", string_edit);
  printf("%s\n", search);
  printf("%s\n", string);

}
