#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t thd;
int banyak=0;
char check;
int angka[1000];
int res[1000];
int input;
int maxi=-1;
void* fakt(void *arg)
{
   
    return NULL;
}

int main(){
	int i;
	for(i=0;i<1000;i++)angka[i]=0;
	while(1){
	   scanf("%d%c",&input,&check);
	   if(maxi<input)maxi=input;
	   banyak++;
	   angka[input]=1;
	  if(check=='\n')break;
	}
}
