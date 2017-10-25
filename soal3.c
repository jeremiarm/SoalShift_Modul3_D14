#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[3];//inisialisasi array untuk menampung thread dalam kasus ini ada 3 thread

int st_lohan=100;
int st_kepit=100;
void* nyawa(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int a=1,b=1;
    int input;
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
        while(st_lohan>0)
        {
            printf("lohan %i\n",st_lohan);
            sleep(3);
	    st_lohan-=15;
	if(st_lohan>100){break;}
        }
	printf("lohan udah mati");
	a=0;
    }
    else if(pthread_equal(id,tid[1]))
    {
        while(st_kepit>0)
        {
            printf("kepiting %i\n",st_kepit);
            sleep(5);
	    st_kepit-=10;
	if(st_kepit>100){break;}
        }
	printf("kepiting udah mati");
	b=0;
    }
    if(pthread_equal(id,tid[2]))//thread untuk menjalankan counter
    {
	while(a==1&&b==1){
        printf("pilih :\n1. beri makan lohan\n2. beri makan kepiting\n");
	scanf("%d",&input);
	if(input==1){st_lohan+=10;}
	else if(input==2){st_kepit+=10;}
	else printf("input error");}
	if(st_lohan>100)st_lohan=0;
	if(st_kepit>100)st_kepit=0;
}
    return NULL;
}
int main(void)
{
    int i=0;
    int err;
    while(i<3)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&nyawa,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    return 0;
}
