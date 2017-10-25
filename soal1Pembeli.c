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
	
        

        
        shmdt(stock);
        shmctl(shmid, IPC_RMID, NULL);
}
