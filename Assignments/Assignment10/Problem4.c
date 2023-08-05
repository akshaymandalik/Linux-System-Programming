#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void * simpleThread(void *ptr){

        int iVal = 0;
        printf("Choose Any Number Between 0-9:");
        scanf("%d",&iVal);
        pthread_exit(&iVal);
}

int main(){


    pthread_t TID;
    int iRet = 0;
    void *iVal;

    iRet = pthread_create(&TID,NULL,simpleThread,NULL);
    if(iRet != 0){
        printf("Error: Something Went Wrong!!");
        return -1;
    }

    pthread_join(TID,&iVal);

    printf("Value from Thread:%d\n",*(int *)iVal);

    return 0;
}