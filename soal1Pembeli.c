#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>



void main()
{
        key_t key = 1234;
        int *stock;
	int check;
	char nama[100];
	int count;
	int angka;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        stock = shmat(shmid, NULL, 0);
	while(1){
	count=-1;
	printf("menu pembeli\n");
	printf("1. beli senjata\n");
	printf("2. lihat stock senjata\n");
        printf("Masukkan input:  ");
	scanf("%d",&check);
	if(check==1){
		printf("Masukkan Nama barang dan jumlah :" );
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
		if(stock[count]>0)stock[count]-=angka;
		else printf("barang di stock tidak cukup\n");
	}
	if(check==2){
		printf("MP4AI %d\n",stock[0]);
		printf("PM2-V1 %d\n",stock[1]);
		printf("SPR-3 %d\n",stock[2]);
		printf("SS2V-5 %d\n",stock[3]);
		printf("SPG1-V3 %d\n",stock[4]);
		printf("MINE %d\n",stock[5]);
	} 
	}
        

        
        shmdt(stock);
        shmctl(shmid, IPC_RMID, NULL);
}
