#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char valore;
  char seme;
} str_carta;

void set_struct(str_carta *mazzo,int dim, char *filepath){
  FILE *fp;
  fp=fopen(filepath, "rb");
  for (size_t i = 0; i < dim; i++) {
    fscanf(fp,"%c",&(mazzo+i)->valore);
    fscanf(fp,"%c",&(mazzo+i)->seme);
  }
  //Stampa array di struct letto
  /*
  for (size_t k = 0; k < dim; k++) {
    printf("%c", (mazzo+k)->valore);
    printf("%c\n", (mazzo+k)->seme);
  }*/
  fclose(fp);
}
void select_random(str_carta *mazzo){
  int n;
  FILE *write;
  write =fopen("mazzo_studente.bin","wb");
  for(size_t i=0;i<21;i++) {
    n=rand() % 52;

    if((mazzo+n)->valore=='-')
      --i;
    else  {
      fwrite(&((mazzo+n)->valore), sizeof(char),1,write);
      fwrite(&((mazzo+n)->seme), sizeof(char),1,write);

      //printf("%c", (mazzo+n)->valore);
      //printf("%c\n", (mazzo+n)->seme);
      (mazzo+n)->valore='-';
    }
  }
  fclose(write);

}
void display_cards(str_carta *mazzo, int dim){
  for (size_t k = 0; k < dim/7; k++) {
    for (size_t i = 0; i < dim/3; i++) {
      printf("%c", (mazzo+i+3*k)->valore);
      printf("%c\t", (mazzo+i+3*k)->seme);
    }
  printf("\n" );
  }
}
void dispose_cards(str_carta *mazzo, str_carta *m1, str_carta *m2, str_carta *m3){
  int k=0;
  for (size_t i = 0; i < 21; i++,k++) {
    m1[k]=mazzo[i];
    printf("%c", m1[k].valore);
    printf("%c\t", m1[k].seme);
    i++;
    m2[k]=mazzo[i];
    printf("%c", m2[k].valore);
    printf("%c\t", m2[k].seme);
    i++;
    m3[k]=mazzo[i];
    printf("%c", m3[k].valore);
    printf("%c\t\n", m3[k].seme);
  }
}
void regenerate_mazzo(str_carta *newmazzo, str_carta *m1, str_carta *m2, str_carta *m3){
  for (size_t i = 0; i < 7; i++) {
    newmazzo[i].valore=m1[i].valore;
    newmazzo[i].seme=m1[i].seme;
    //printf("%c%c\t", m1[i].valore, m1[i].seme);
  }

  for (size_t i = 7; i < 14; i++) {
    newmazzo[i].valore=m2[i-7].valore;
    newmazzo[i].seme=m2[i-7].seme;
  }

  for (size_t i = 14; i < 21; i++) {
    newmazzo[i].valore=m3[i-14].valore;
    newmazzo[i].seme=m3[i-14].seme;
  }
}


int main(){
  str_carta mazzo_intero[52],mazzo_studente[21],m1[7],m2[7],m3[7];
  int mazzetto=0;

  set_struct(&mazzo_intero[0],52,"mazzoPolimi.bin");
  select_random(&mazzo_intero[0]);
  set_struct(&mazzo_studente[0],21,"mazzo_studente.bin");
  set_struct(&mazzo_intero[0],52,"mazzoPolimi.bin");
  display_cards(&mazzo_studente[0],21);
  getchar();
  for (size_t i = 0; i < 3; i++) {
    dispose_cards(mazzo_studente,m1,m2,m3);
    printf("Selezionare il mazzo, inserendo 1-2-3:\n");
    scanf("%d", &mazzetto);
    switch (mazzetto) {
      case 1:
        regenerate_mazzo(mazzo_studente,m2,m1,m3);
        break;
      case 2:
        regenerate_mazzo(mazzo_studente,m1,m2,m3);
        break;
      case 3:
        regenerate_mazzo(mazzo_studente,m2,m3,m1);
        break;
    }

  }
  printf("La tua carta è: %c%c!\n", mazzo_studente[10].valore,mazzo_studente[10].seme);




}
