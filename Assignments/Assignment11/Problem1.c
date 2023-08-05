#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#define THREACOUNT 4

void * thread1(void *ptr){
    printf("Thread1\n");
    pthread_exit(NULL);

}
void * thread2(void *ptr){
    printf("Thread2\n");
    pthread_exit(NULL);

}
void * thread3(void *ptr){

    printf("Thread3\n");
    pthread_exit(NULL);

}
void * thread4(void *ptr){
   
    printf("Thread4\n");
    pthread_exit(NULL);
}

int main(){

    pthread_t TID1,TID2,TID3,TID4;
    int iRet = 0;
    int iCnt = 0;

    iRet = pthread_create(&TID1,NULL,thread1,NULL);
    if(iRet != 0){
        printf("Error: Can't run thread1");
    }

    iRet = pthread_create(&TID2,NULL,thread2,NULL);
    if(iRet != 0){
        printf("Error: Can't run thread2");
    }

    iRet = pthread_create(&TID3,NULL,thread3,NULL);
    if(iRet != 0){
        printf("Error: Can't run thread3");
    }

    iRet = pthread_create(&TID4,NULL,thread4,NULL);
    if(iRet != 0){
        printf("Error: Can't run thread4");
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);


    return 0;

}