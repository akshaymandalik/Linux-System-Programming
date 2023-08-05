#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#define THREACOUNT 8

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
void * thread5(void *ptr){
    printf("Thread5\n");
    pthread_exit(NULL);

}
void * thread6(void *ptr){
    printf("Thread6\n");
    pthread_exit(NULL);

}
void * thread7(void *ptr){

    printf("Thread7\n");
    pthread_exit(NULL);

}
void * thread8(void *ptr){
   
    printf("Thread8\n");
    pthread_exit(NULL);
}

int main(){

    pthread_t TID[THREACOUNT];
    int iRet = 0;
    int iCnt = 0;
    void * (*functionName[THREACOUNT])(void *) = {thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8};

    for(iCnt = 0;iCnt<THREACOUNT;iCnt++){

        iRet = pthread_create(TID+iCnt,NULL,*(functionName+iCnt),NULL);
        if(iRet != 0){
            printf("Error: Can't run thread1");
        }
        pthread_join(*(TID+iCnt),NULL);
    }
    


    return 0;

}