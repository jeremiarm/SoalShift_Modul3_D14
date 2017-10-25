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
int lubang1[16];
int lubang2[16];
int angka;
int check;
int breaker=0;
char player1[100];
char player2[100];
int point1=0;
int point2=0;
int loop=4;
int menang=0;
int jumlah1=0;
int jumlah2=0;
void poin(){
    printf("Point %s: %d\n",player1,point1);
    printf("Point %s: %d\n",player2,point2);
}

void* turn1(void *arg)
{
while(point1<10){
if(point1==10||point2==10)return NULL;
    while(status==1){}
if(point1==10||point2==10)return NULL;
   if(jumlah1==16)printf("Lubang 1 udah penuh\n");
else{
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
		jumlah1++;
		if(jumlah1==16)break;
        }
    }
}
    printf("Masukkan 4 angka oleh %s\n",player2);
	loop=4;
    while(loop--){
   	 scanf("%d",&angka);
	angka--;
   	 if(lubang1[angka]==1)point1++;
         else point2++;
	if(point1==10||point2==10){
	 status=1;
	return NULL;
	}
    }
    status = 1;
    poin();
    if(breaker==32)return NULL;
  // printf("turn1 %d\n",status);
 }
    return NULL;
}

void* turn2(void *arg)
{
while(point2<10){
if(point1==10||point2==10)return NULL;

    while(status==0){}
if(point1==10||point2==10)return NULL;
   if(jumlah2==16){
  printf("Lubang 2 udah penuh\n");
}
else{
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
		jumlah2++;
		if(jumlah2==16)break;
        }
    }
}
    printf("Masukkan 4 angka oleh %s\n",player1);
   loop=4;
    while(loop--){
         scanf("%d",&angka);
	angka--;
         if(lubang2[angka]==1)point2++;
         else point1++;
        if(point1==10||point2==10){
	status=0;
	return NULL;
}
    }
   poin();
   status = 0;
   if(breaker==32)return NULL;
  // printf("turn 2 %d\n",status);
}
    return NULL;
}

int main(){
	int c;
	for(c=0;c<16;c++){
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
	poin();
	if(point1==10)printf("%s menang\n",player1);
	else if(point2==10)printf("%s menang\n",player2);
	else printf("Tidak ada yang menang\n");
	printf("Permainan selesai, terima kasih\n");
}
