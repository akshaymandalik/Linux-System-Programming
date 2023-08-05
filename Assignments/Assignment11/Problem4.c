/*
	Here a problem is that both the threads using 
	the shared memory space and using at the 
	same time.
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

int sharedMemory = 50;

pthread_mutex_t lock;

void *thread1(void *ptr){

	pthread_mutex_lock(&lock);
	sharedMemory+=1;
	printf("SharedMemory(Thread1):%d\n",sharedMemory);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

void * thread2(void *ptr){
	
	pthread_mutex_lock(&lock);
	sharedMemory+=1;
	printf("SharedMemory(Thread2):%d\n",sharedMemory);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

int main(){
	
	pthread_t TID1,TID2;
	int iRet1 = 0,iRet2 = 0;

	pthread_mutex_init(&lock,NULL);
	
	iRet1 = pthread_create(&TID1,NULL,thread1,NULL);
	if(iRet1 != 0){
		printf("Error: Can't execute Thread1");
		return -1;
	}
	iRet2 = pthread_create(&TID2,NULL,thread2,NULL);
	if(iRet2 != 0){
		printf("Error:Can't execute Thread2");
		return -1;
        }

	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	

	pthread_mutex_destroy(&lock);
	pthread_exit(NULL);
	return 0;
}
