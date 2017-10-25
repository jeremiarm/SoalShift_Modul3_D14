#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
        key_t key = 1234;
        int *stock;
	char nama[1000];
	int angka;
	int check;
	int count;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        stock = shmat(shmid, NULL, 0);
	stock[0]=0;
	stock[1]=0;
	stock[2]=0;
	stock[3]=0;
	stock[4]=0;
	stock[5]=0;

	while(1){
		 count=-1;
       		 printf("menu penjual\n");
       		 printf("1. tambah senjata\n");
       		 printf("2. lihat stock senjata\n");
       		 printf("Masukkan input:  ");
       		 scanf("%d",&check);
       		 if(check==1){
                printf("Masukkan Nama barang dan jumlah barang:" );
                scanf("%s %d",nama,&angka);
                if(nama[2]='4')count=0;
                else if(nama[0]='P')count=1;
                else if(nama[4]='3')count=2;
                else if(nama[1]='S')count=3;
                else if(nama[2]='G')count=4;
		else if(nama[1]='I')count=5;
                else
                {
                        printf("Input Salah\n");
                        continue;
                }
                stock[count]+=angka;
        }
        if(check==2){
                if(stock[0]>0)printf("MP4AI %d\n",stock[0]);
               if(stock[1]>0) printf("PM2-V1 %d\n",stock[1]);
               if(stock[2]>0) printf("SPR-3 %d\n",stock[2]);
               if(stock[3]>0) printf("SS2V-5 %d\n",stock[3]);
		if(stock[4]>0)printf("SPG1-V3 %d\n",stock[4]);
               if(stock[5]>0) printf("MINE %d\n",stock[5]);
        } 		
	}



        shmdt(stock);
        shmctl(shmid, IPC_RMID, NULL);
}

