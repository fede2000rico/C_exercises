#include<stdio.h>
#include<string.h>
#define LEN 15

int main(){
  char *str1="testprova123", str2[15];

  for (size_t k = 0; k < 15; k++) {
    *(str2+k)=*(str1+k);
  }

  printf("%s\n%s\n", str1,str2);
}
