#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
#define MAXSIZE 1024

struct ThreadData{
	int fd;
	char buffer[MAXSIZE];
};

void *thread1(void *ptr){

	int iCnt1 = 0,iRet = 0;
    int iCnt = 0;
	struct ThreadData *data = (struct ThreadData *) malloc(sizeof(struct ThreadData));
	data->fd = *(int *)ptr;

    while((iRet = read(data->fd,data->buffer,MAXSIZE)) != 0){

        iCnt = 0;
        while(data->buffer[iCnt] != '\0'){
            
            if(data->buffer[iCnt]>='A' && data->buffer[iCnt]<='Z'){

                iCnt1++;
            }
            iCnt++;
        }
    }

   	lseek(data->fd,0,SEEK_SET);

	printf("No of Capital Letters:%d\n",iCnt1);
	pthread_exit(NULL);
}

void * thread2(void *ptr){
	
	int iCnt1 = 0,iRet = 0;
    int iCnt = 0;
	struct ThreadData *data = (struct ThreadData *) malloc(sizeof(struct ThreadData));
	data->fd = *(int *)ptr;

    while((iRet = read(data->fd,data->buffer,MAXSIZE)) != 0){

        iCnt = 0;
        while(data->buffer[iCnt] != '\0'){
            
            if(data->buffer[iCnt]>='a' && data->buffer[iCnt]<='z'){

                iCnt1++;
            }
            iCnt++;
        }
    }

   	lseek(data->fd,0,SEEK_SET);
	printf("No of Small Letters:%d\n",iCnt1);
	
	pthread_exit(NULL);
}

int main(){
	
	pthread_t TID1,TID2;
	int iRet1 = 0,iRet2 = 0,fd1=0;
	

	fd1 = open("Demo.txt",O_RDONLY);
    if(fd1 == -1){
        printf("Error: Unable to open Demo.txt");
        return -1;
	}

	
	iRet1 = pthread_create(&TID1,NULL,thread1,(void *)&fd1);
	if(iRet1 != 0){
		printf("Error: Can't execute Thread1");
		return -1;
	}
	iRet2 = pthread_create(&TID2,NULL,thread2,(void *)&fd1);
	if(iRet2 != 0){
		printf("Error:Can't execute Thread2");
		return -1;
    }

	

	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);

	close(fd1);

	pthread_exit(NULL);
	return 0;
}
