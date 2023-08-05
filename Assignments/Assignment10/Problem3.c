#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void * simpleThread(void *ptr){

    int *result = (int *)ptr;
    printf("Value from main %d",*result);
    pthread_exit(NULL);
}

int main(){


    pthread_t TID;
    int iRet = 0;
    int iVal = 56;

    iRet = pthread_create(&TID,NULL,simpleThread,(void *)&iVal);
    if(iRet != 0){
        printf("Error: Something Went Wrong!!");
        return -1;
    }

    pthread_join(TID,NULL);

    return 0;
}