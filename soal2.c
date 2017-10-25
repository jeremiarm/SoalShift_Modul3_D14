#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int status;
int player=0;
int input;
int lubang1[10];
int lubang2[10];
int angka;
int check;
int breaker=0;
char player1[100];
char player2[100];
int point1=0;
int point2=0;
void* turn1(void *arg)
{
    status = 0;
    while(status==1){}
    printf("Masukkan jumlah lubang yang diisi(1-4) %s\n",player1);
    scanf("%d",&input);
    check=1;
    while(input){
        printf("Cara ke-%d: ",check);
        scanf("%d",angka);
        angka--;
        if(lubang1[angka]==1){
                printf("Lubang udah ada\n");
        }
        else
        {
                lubang1[angka]=1;
                breaker++;
                check++;
        }
    }
    printf("Masukkan angka oleh %s:  ",player2);
    while(4--){
   	 scanf("%d",&angka);
   	 if(lubang1[angka]==1)point1++;
         else point2++;
    }
    status = 1;
 
    return NULL;
}

void* turn2(void *arg)
{
    status = 0;
 
    status = 1;
 
    return NULL;
}
