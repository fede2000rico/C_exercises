#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

typedef struct elem{
  char string[N];
  struct elem *next;
}lista;

lista *func(char *s, char ch, lista *head){
  int first,second,i=0,k=0,lenght;
  lista *ptr= head;
  char strcp[5];
  lenght=strlen(s);
  while(s[i]==ch && i<lenght) i++;
  first=i;
  i++;
  while(s[i]==ch && i<lenght) i++;
  second=i;
  while (ptr->next==NULL) {
    ptr=ptr->next;
  }

  ptr->next=malloc(sizeof(lista));
  ptr=ptr->next;

  if (first==lenght || second==lenght) {
    strcpy(ptr->string,"");
  }
  else{
    for (size_t i = first+1; i < second; k++,i++) {
      strcp[k]=s[i];
    }
    strcpy(ptr->string,strcp);

  }
  return head;
}

int main(){
  lista *head;
  head =malloc(sizeof(lista));
  head->next=NULL;
  
}
