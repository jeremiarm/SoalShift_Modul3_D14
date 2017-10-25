#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int status=0;
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
int loop=4;
int menang=0;
void poin(){
    printf("Point %s: %d\n",player1,point1);
    printf("Point %s: %d\n",player2,point2);
}

void* turn1(void *arg)
{
while(point1<10){
    while(status==1){}
    if(menang)return NULL;
    printf("Masukkan jumlah lubang yang diisi(1-4) %s\n",player1);
    scanf("%d",&input);
    check=1;
    while(input){
        printf("Cara ke-%d: ",check);
        scanf("%d",&angka);
        angka--;
        if(lubang1[angka]==1){
                printf("Lubang udah ada\n");
        }
        else
        {
                lubang1[angka]=1;
                breaker++;
                check++;
		input--;
        }
    }
    printf("Masukkan 4 angka oleh %s\n  ",player2);
	loop=4;
    while(loop--){
   	 scanf("%d",&angka);
	angka--;
   	 if(lubang1[angka]==1)point1++;
         else point2++;
    }
    status = 1;
    poin();
  // printf("turn1 %d\n",status);
 }
    return NULL;
}

void* turn2(void *arg)
{
while(point2<10){
    while(status==0){}
   if(menang)return NULL;
    printf("Masukkan jumlah lubang yang diisi(1-4) %s\n",player2);
    scanf("%d",&input);
    check=1;
    while(input){
        printf("Cara ke-%d: ",check);
        scanf("%d",&angka);
        angka--;
        if(lubang2[angka]==1){
                printf("Lubang udah ada\n");
        }
        else
        {
                lubang2[angka]=1;
                breaker++;
                check++;
		input--;
        }
    }
    printf("Masukkan 4 angka oleh %s\n  ",player1);
   loop=4;
    while(loop--){
         scanf("%d",&angka);
	angka--;
         if(lubang2[angka]==1)point2++;
         else point1++;
    }
   poin();
   status = 0;
  // printf("turn 2 %d\n",status);
}
    return NULL;
}

int main(){
	int c;
	for(c=0;c<10;c++){
		lubang1[c]=0;
		lubang2[c]=0;
	}
	printf("Masukkan nama pemain1 dan pemain 2: ");
	scanf("%s %s",player1,player2);
	//printf("Masukkan nama pemain2: ");
	//scanf("%s\n",player2);
	pthread_create(&(tid1), NULL, &turn1, NULL);
   	pthread_create(&(tid2), NULL, &turn2, NULL);
 
   	pthread_join(tid1, NULL);
   	pthread_join(tid2, NULL);
}
