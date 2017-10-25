#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid;
int angka[1000];
long double res;
int maxi=-1;
int now;
void* fakt(void *arg)
{
   int q;
   res=(long double)1;
   for(q=now;q>=1;q--){
       res=res*(long double)q;
   }
   printf("Hasil %d! = %0.Lf\n",now,res);
    return NULL;
}

int main(int argc, char** argv){
	int i;
	int ubah;
	for(i=0;i<1000;i++){
		angka[i]=0;
	}
	for(i=1;i<argc;i++){
		ubah=atoi(argv[i]);
		angka[ubah]++;
		if(maxi<ubah)maxi=ubah;
	}
	for(i=1;i<=ubah;i++){
		now=i;
		while(angka[now]--){
			pthread_create(&(tid),NULL,&fakt,NULL);
			pthread_join(tid,NULL);
		}
	}
}
