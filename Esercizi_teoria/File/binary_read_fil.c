#include<stdio.h>
#include<stdlib.h>


//Nel main
//FILE *fp;
//fp=fopen("percorsofile","r") [oppure "rb" per binario]
//int array[30]={0};
//int *ptr=&array[0];
//func(fp,ptr);

//File in input gia settato come lettura binaria
void func(FILE *fp,int *array){
  int k=0;
  while(!feof(fp)){
    fscanf(fp,"%d",&array[k]);
    k++;
  }
}
