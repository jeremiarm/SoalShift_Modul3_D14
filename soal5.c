#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

FILE* in;


pthread_t tid;
int banyak;
char  vari[1000];
FILE* in;
void* check(void *arg)
{
   int count=0;
   char* line=NULL;
   size_t len;

in=fopen("Novel.txt","r");
    while((getline(&line,&len,in))!=-1){  
	while(line=strstr(line,vari)){
		count++;
		line++;
	}
    }
    printf("%s : %d\n",vari,count);
   fclose(in);
    return NULL;
}


int main(int argc,char **argv){
	int i;	
	for(i=1;i<argc;i++){
		strcpy(vari,argv[i]);
		pthread_create(&(tid),NULL,&check,NULL);
		pthread_join(tid,NULL);
	}
	//fclose(in);
}
