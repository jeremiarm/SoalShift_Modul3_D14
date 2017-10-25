#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[2];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread

int st_lohan=100;
int st_kepit=100;
void* nyawa(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
        system("clear");
        for(iter=st_lohan;iter>0;)
        {
            printf("%i",iter);
            fflush(stdout);
            sleep(10);
	    iter=iter-15;
            system("clear");
        }
    }
    else if(pthread_equal(id,tid[1]))
    {
        system("clear");
        for(iter1=st_kepit;iter1>0;)
        {
            printf("%i",iter);
            fflush(stdout);
            sleep(20);
	    iter1=iter1-10;
            system("clear");
        }
    }
    }
    return NULL;
}
int main(void)
{
    int i=0;
    int err;
    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&nyawa,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
