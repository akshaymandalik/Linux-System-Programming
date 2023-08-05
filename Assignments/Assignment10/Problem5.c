#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void * thisThread(void *ptr){
    
    printf("Id of current thread:%ld\n",(long)pthread_self());
    pthread_exit(NULL); 
}

int main(){

    pthread_t TID;
    int iRet = 0;

    iRet = pthread_create(&TID,NULL,thisThread,NULL);
    if(iRet !=0){
        printf("Error:Something Went Wrong!!");
        return -1;
    }

    pthread_join(TID,NULL);
    pthread_exit(NULL);

    return 0;   
}