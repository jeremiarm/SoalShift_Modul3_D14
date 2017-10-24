#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t thd;
int banyak=0;
char check;
int angka[1000];
int res;
int input;
int maxi=-1;
int now;
void* fakt(void *arg)
{
   int q;
   res=1;
   for(q=now;q>=1;q--){
       res*=q;
   }
   printf("Hasil %d! = %d\n",now,res);
    return NULL;
}

int main(){
	int i;
	for(i=0;i<1000;i++)angka[i]=0;
	while(1){
	   scanf("%d%c",&input,&check);
	   if(maxi<input)maxi=input;
	   banyak++;
	   angka[input]++;
	  if(check=='\n')break;
	}
}
